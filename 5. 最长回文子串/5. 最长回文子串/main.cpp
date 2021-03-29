//
//  main.cpp
//  5. 最长回文子串
//
//  Created by 邱俊荣 on 2021/3/29.
//

/*
 给你一个字符串 s，找到 s 中最长的回文子串。
 示例 1：

 输入：s = "babad"
 输出："bab"
 解释："aba" 同样是符合题意的答案。
 示例 2：

 输入：s = "cbbd"
 输出："bb"
 示例 3：

 输入：s = "a"
 输出："a"
 示例 4：

 输入：s = "ac"
 输出："a"

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;


string longestPalindrome(string s) {
    int n = (int)s.size();
    if (n < 2) { return s;}
    
    int maxLen = 1;//最长回文串长度
    int begin = 0;//最长回文串开始的位置
    // dp[i][j]表示s[i...j]是否回文串，转移方式就是dp[i][j] = s[i] == s[j] && dp[i+1][j-1]
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) { // 单个字符的情况
        dp[i][i] = true;
    }
    
    for (int j = 1; j < n; j++) { //外循环是右边边界
        for (int i = 0; i < j; i++) { //内循环是左边边界
            if (s[i] != s[j]) { //如果当前串最外面字符不等，当前串则肯定不是回文串
                dp[i][j] = false;
            } else {
                if (j-i < 3) {//三个元素，且最外层又是相等，则是回文串，如aba
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if (dp[i][j] == true && j-i+1 > maxLen) {
                //更新目前最大回文串坐标
                maxLen = j-i+1;
                begin = i;
            }
        }
    }
    //截取最大回文串返回
    return s.substr(begin,maxLen);
}

int main(int argc, const char * argv[]) {
    
    cout << longestPalindrome("babad") << endl;
    
    return 0;
}
