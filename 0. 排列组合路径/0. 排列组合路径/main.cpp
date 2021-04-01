//
//  main.cpp
//  0. 排列组合路径
//
//  Created by 邱俊荣 on 2021/4/1.
//

/*
 将“ABC”字符串，排列组合行程"ABC", "ACB", "BCA", "BAC", "CBA", "CAB"输出
 */

#include <iostream>
#include <vector>
using namespace std;

/*
     A  B  C
     A  B  C
     A  B  C
    从第一层开始，选中一个结果每次往下探测，到底就是一种结果
 */

class Solution {
    // 一共有3层，每层的值对应这层选中的结果的索引号
    vector<int> cols;
    string testStr;
public:
    vector<string> totalList;
    vector<string> pathWaysFind(string &str) {
        testStr = str;
        int n = (int)str.size();
        if (n < 1) return totalList;
        cols.resize(n);
        place(0);
        cout << "一共有" << totalList.size() << "种行程" << endl;
        return totalList;
    }
    ~Solution(){
        cout << "Solution obj dealloc" << endl;
    }
private:
    void place(int row) {
        if (row == cols.size()) {// 进入这里说明一件确定了一种路径
            // cols数组里已经有了当前路径的位置
            string resStr;
            for (int i = 0; i < cols.size(); i++) {
                resStr.push_back(testStr[cols[i]]);
            }
            totalList.push_back(resStr);
            return;
        }
        // 这一行的每一列都遍历，选中一列看是否可以摆放皇后
        for (int col = 0; col < cols.size(); col++) {
            // 这里很重要，for循环找出当前行的每一个可以摆放的列，在每种可以的前提下先往下一行探测
            if (isValid(row, col)) {
                cols[row] = col;// 当前位置可以摆放,因为循环回溯，下一次当前列的可选中位置被覆盖。
                place(row + 1); // 寻找下一行的需要选中的位置
            }
        }
        
        // place(row + 1); 如果把递归放这里，其实只选出了一种路径
    }
    
    // 判断第row行的第col列是否可以选中
    bool isValid(int row, int col) {
        // 需要遍历之前的每行选中的位置
        for (int i = 0; i < row; i++) {
            // 之前的行已经有选中这列了
            if (cols[i] == col) return false;
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    
    shared_ptr<Solution> solu(new Solution());
    string test = "ABCD";
    vector<string> arr = solu->pathWaysFind(test);
    for (string str : arr) {
        cout << str << endl;
    }
    
    return 0;
}
