//
//  main.cpp
//  22. 括号生成
//
//  Created by 邱俊荣 on 2021/3/22.
//
/*
 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 1 <= n <= 8
 
 示例 1：
 输入：n = 3
 输出：["((()))","(()())","(())()","()(())","()()()"]
 
 示例 2：
 输入：n = 1
 输出：["()"]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/generate-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;
// 回溯（DFS深度优先，每一层先选定一种可能往下探测，等到最下的面的结果都确定了再往上一层换种可能继续往下探测）
void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
    if (cur.size() == n * 2) {
        ans.push_back(cur);
        return;
    }
    if (open < n) {
        cur.push_back('(');
        backtrack(ans, cur, open + 1, close, n);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        backtrack(ans, cur, open, close + 1, n);
        cur.pop_back();
    }
}


vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    backtrack(result, current, 0, 0, n);
    return result;
}

int main(int argc, const char * argv[]) {
    
    vector<string> arr = generateParenthesis(3);
    for (string str : arr) {
        cout << str << ",";
    }
    cout << endl;
    return 0;
}
