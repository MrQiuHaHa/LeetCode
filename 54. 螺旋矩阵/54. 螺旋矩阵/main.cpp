//
//  main.cpp
//  54. 螺旋矩阵
//
//  Created by 邱俊荣 on 2021/3/21.
//
/*
 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 
   1 -> 2 -> 3
             |
   4 -> 5    6
   |         |
   7 <- 8 <- 9
 
 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 输出：[1,2,3,6,9,8,7,4,5]
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    if (matrix.size() == 0) return {};
    
    int left = 0, right = (int)matrix[0].size()-1, top = 0, bottom = (int)matrix.size()-1;
    
    vector<int> arr;
    while (left <= right && top <= bottom) {
        
        for (int i = left; i <= right; i++) {
            arr.push_back(matrix[top][i]);
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            arr.push_back(matrix[i][right]);
        }
        right--;
        
        // 奇数行或者偶数列的时候有问题处理
        if (top > bottom || left > right) {
            break;
        }
        
        for (int i = right; i >= left; i--) {
            arr.push_back(matrix[bottom][i]);
        }
        bottom--;
        
        for (int i = bottom; i >= top; i--) {
            arr.push_back(matrix[i][left]);
        }
        left++;
    }
    
    return arr;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> nums = spiralOrder(matrix);
    
    for (int num : nums) {
        
        cout << num << "->";
    }
    cout << endl;
    
    return 0;
}
