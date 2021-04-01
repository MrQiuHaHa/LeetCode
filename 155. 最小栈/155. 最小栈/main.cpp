//
//  main.cpp
//  155. 最小栈
//
//  Created by 邱俊荣 on 2021/4/1.
//
/*
 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 push(x) —— 将元素 x 推入栈中。
 pop() —— 删除栈顶的元素。
 top() —— 获取栈顶元素。
 getMin() —— 检索栈中的最小元素。

 示例:

 输入：
 ["MinStack","push","push","push","getMin","pop","top","getMin"]
 [[],[-2],[0],[-3],[],[],[],[]]

 输出：
 [null,null,null,null,-3,null,0,-2]

 解释：
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.getMin();   --> 返回 -2.
  
 提示：
 pop、top 和 getMin 操作总是在 非空栈 上调用。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/min-stack
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>

using namespace std;


class MinStack {
    
    struct Node {
        int val;
        int min;
        Node *next;
        Node(int x, int min, Node *next) : val(x), min(min), next(next) {}
    };
    
    Node *head;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        //链表的头插法，每次节点都是插入到链表的最前面
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            head = new Node(val, min(val, head->min), head);
        }
    }
    
    void pop() {
        //先进后出，移除链表最后进来的元素
        if (head != nullptr) {
            head = head->next;
        }
    }
    
    int top() {
        if (head != nullptr) {
            return head->val;
        }
        return 0;
    }
    
    int getMin() {
        if (head != nullptr) {
            return head->min;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    
    
    MinStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    
    cout << "top = " << stack.top() << "; min =" << stack.getMin() << endl;
    
    return 0;
}
