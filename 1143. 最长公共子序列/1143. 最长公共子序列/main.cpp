//
//  main.cpp
//  1143. 最长公共子序列
//
//  Created by 邱俊荣 on 2021/3/19.
//

/*
 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
 若这两个字符串没有公共子序列，则返回 0。
 
 示例 1:
 输入：text1 = "abcde", text2 = "ace"
 输出：3
 解释：最长公共子序列是 "ace"，它的长度为 3。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-common-subsequence
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

// 这种方法就是类似斐波那契的递归，时间复杂度 O(2^n)
int longestCommon(string text1, int i, string text2, int j) {
    if (i == 0 || j == 0) return 0;
    
    if (text1[i-1] == text2[j-1]) return longestCommon(text1, i-1, text2, j-1)+1;
    
    return max(longestCommon(text1, i-1, text2, j), longestCommon(text1, i, text2, j-1));
}

int longestCommonSubsequence1(string text1, string text2) {
    
    if (text1.size() == 0 || text2.size() == 0) return 0;
    return longestCommon(text1, (int)text1.size(), text2, (int)text2.size());
}


// 动态规划方法
int longestCommonSubsequence2(string text1, string text2) {
    
    if (text1.size() == 0 || text2.size() == 0) return 0;
    
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}

int main(int argc, const char * argv[]) {
    
    
    cout << longestCommonSubsequence2("abcde", "abce") << endl;
    
    return 0;
}
