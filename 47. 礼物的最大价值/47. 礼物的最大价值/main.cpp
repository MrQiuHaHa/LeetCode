//
//  main.cpp
//  47. 礼物的最大价值
//
//  Created by 邱俊荣 on 2021/3/29.
//

/*
 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 
 示例 1:
 输入:
 [
   [1,3,1],
   [1,5,1],
   [4,2,1]
 ]
 输出: 12
 解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

int maxValue(vector<vector<int>>& grid) {
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();
    
    int dp[rows][cols];
    dp[0][0] = grid[0][0];
    // 第0行
    for (int col = 1; col < cols; col++) {
        dp[0][col] = dp[0][col - 1] + grid[0][col];
    }
    // 第0列
    for (int row = 1; row < rows; row++) {
        dp[row][0] = dp[row - 1][0] + grid[row][0];
    }
    for (int row = 1; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
        }
    }
    return dp[rows - 1][cols - 1];
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << maxValue(grid) << endl;
    
    return 0;
}
