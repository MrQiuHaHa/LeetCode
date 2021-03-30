//
//  main.cpp
//  72. 编辑距离
//
//  Created by 邱俊荣 on 2021/3/30.
//
/*
 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 你可以对一个单词进行如下三种操作：

 插入一个字符
 删除一个字符
 替换一个字符
  
 示例 1：
 输入：word1 = "horse", word2 = "ros"
 输出：3
 解释：
 horse -> rorse (将 'h' 替换为 'r')
 rorse -> rose (删除 'r')
 rose -> ros (删除 'e')
 
 示例 2：
 输入：word1 = "intention", word2 = "execution"
 输出：5
 解释：
 intention -> inention (删除 't')
 inention -> enention (将 'i' 替换为 'e')
 enention -> exention (将 'n' 替换为 'x')
 exention -> exection (将 'n' 替换为 'c')
 exection -> execution (插入 'u')
  
 提示：
 0 <= word1.length, word2.length <= 500
 word1 和 word2 由小写英文字母组成

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/edit-distance
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
using namespace std;

int minDistance(string word1, string word2) {

    int len1 = (int)word1.size();
    int len2 = (int)word2.size();
    
    int dp[len1+1][len2+1];
    memset(dp, 0, sizeof(dp));
    // 把特殊情况先赋值，用于后面计算
    for (int i = 0; i < len1+1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < len2+1; j++) {
        dp[0][j] = j;
    }
    //开始动态规划查找，状态转移方程，dp[i][j]表示word1[0...i]变成word2[0...j]的操作次数
    // 1.当word1[i] = word2[j]时，则dp[i][j] = dp[i-1][j-1]
    // 2.否则，dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
    // 第2部的解释：插入一个字符、删除一个字符、替换一个字符有三种情况操作，如果是替换为相同尾字符，则又变成dp[i-1][j-1]
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (word1[i] == word2[j]) {//遍历从0开始才能判断到word1[0] == word2[0]情况
                dp[i+1][j+1] = dp[i][j];
            } else {
                dp[i+1][j+1] = 1 + min(min(dp[i][j+1],dp[i+1][j]),dp[i][j]);
            }
        }
    }
    
    // dp的 i，j 代表是截取一样的下标，所以取到length的最后
    return dp[len1][len2];
}
int main(int argc, const char * argv[]) {
    
    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance(word1, word2) << endl;
    
    return 0;
}
