//
//  main.cpp
//  20. 有效的括号
//
//  Created by 邱俊荣 on 2021/3/9.
//

/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 有效字符串需满足：1:左括号必须用相同类型的右括号闭合。2:左括号必须以正确的顺序闭合。

 示例 1：输入：s = "()" 输出：true
 示例 2：输入：s = "()[]{}" 输出：true
 示例 3：输入：s = "(]"  输出：false
 示例 4：输入：s = "([)]" 输出：false
 示例 5：输入：s = "{[]}" 输出：true
 */

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {

    stack<char> stk;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push(ch); // 遇见左括号则压入栈
        } else { // 遇见右括号则出栈判断是否对称
            if (stk.empty()) return false;
            char top = stk.top();
            stk.pop();
            if (top == '(' && ch != ')') return false;
            if (top == '{' && ch != '}') return false;
            if (top == '[' && ch != ']') return false;
        }
    }
    return stk.empty();
}

int main(int argc, const char * argv[]) {
    
    cout << isValid("()[{}]") << endl;
    
    return 0;
}
