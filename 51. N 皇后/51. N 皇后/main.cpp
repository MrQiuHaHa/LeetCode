//
//  main.cpp
//  51. N 皇后
//
//  Created by 邱俊荣 on 2021/3/18.
//

/*
 n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 输入：n = 4
 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 
 提示：
 1 <= n <= 9
 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/n-queens
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 索引是行号，对应元素是列号（因为每一行只能放一个皇后，所以必然只有对应唯一的列的位置放了皇后）
    vector<int> cols;
public:
    vector<vector<string>> totalList;
    vector<vector<string>> solveNQueens(int n) {
        if (n < 1) return totalList;
        cols.resize(n); // 数组的容量就是N皇后数量
        place(0);
        cout << "一共有" << totalList.size() << "种摆法" << endl;
        return totalList;
    }
    
private:
    void place(int row) {
        if (row == cols.size()) {// 进入这里说明一件确定了一种摆法
            // cols数组里已经有了当前摆法的位置
            vector<string> list;
            for (int i = 0; i < cols.size(); i++) {
                string rowStr;
                for (int j = 0; j < cols.size(); j++) {
                    rowStr.append(cols[i] == j ? "Q" : ".");
                }
                list.push_back(rowStr);
            }
            totalList.push_back(list);
            return;
        }
        // 这一行的每一列都遍历，选中一列看是否可以摆放皇后
        for (int col = 0; col < cols.size(); col++) {
            // 这里很重要，for循环找出当前行的每一个可以摆放的列，在每种可以的前提下先往下一行探测
            if (isValid(row, col)) {
                cols[row] = col;// 当前位置可以摆放,因为循环回溯，下一次当前列的可摆法位置被覆盖。
                place(row + 1); // 寻找下一行的需要摆放的位置
            }
        }
        
        // place(row + 1); 如果把递归放这里，其实只选出了一种摆法
    }
    
    // 判断第row行的第col列是否可以摆放皇后
    bool isValid(int row, int col) {
        // 需要遍历之前的每行皇后位置
        for (int i = 0; i < row; i++) {
            // 之前的行已经有在这列摆放了
            if (cols[i] == col) return false;
            // 之前的皇后在同一斜线摆放
            if (abs(row - i) == abs(col-cols[i])) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solu;
    solu.solveNQueens(8);
    
    for (vector<string> str : solu.totalList) {
        for (string subStr : str) {
            cout << subStr << " /// ";
        }
        cout << endl;
    }
    
    return 0;
}
