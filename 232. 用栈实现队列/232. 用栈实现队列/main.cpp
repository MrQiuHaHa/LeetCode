//
//  main.cpp
//  232. 用栈实现队列
//
//  Created by 邱俊荣 on 2021/3/9.
//
/*
 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

 实现 MyQueue 类：
 void push(int x) 将元素 x 推到队列的末尾
 int pop() 从队列的开头移除并返回元素
 int peek() 返回队列开头的元素
 boolean empty() 如果队列为空，返回 true ；否则，返回 false

 说明：
 你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
 输入：
 ["MyQueue", "push", "push", "peek", "pop", "empty"]
 [[], [1], [2], [], [], []]
 输出：
 [null, null, null, 1, 1, false]

 解释：
 MyQueue myQueue = new MyQueue();
 myQueue.push(1); // queue is: [1]
 myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 myQueue.peek(); // return 1
 myQueue.pop(); // return 1, queue is [2]
 myQueue.empty(); // return false
 */
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    
    stack<int> *inStack;
    stack<int> *outStack;
    int size;
    
    /** Initialize your data structure here. */
    MyQueue() {
        inStack = new stack<int>();
        outStack = new stack<int>();
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        size++;
        inStack->push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (size == 0) {
            return NULL;
        }
        size--;
        
        if (outStack->size() == 0) {
            // 输出队列的元素为空
            int inSize = (int)inStack->size();
            for (int i = 0; i < inSize; i++) {
                // 循环把输入队列的所有元素pop出来，push到输出队列
                outStack->push(inStack->top());
                inStack->pop();
            }
            
        }
        int top = outStack->top();
        outStack->pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (outStack->size() == 0) {
            // 输出队列的元素为空
            int inSize = (int)inStack->size();
            for (int i = 0; i < inSize; i++) {
                // 循环把输入队列的所有元素pop出来，push到输出队列
                outStack->push(inStack->top());
                inStack->pop();
            }
        }
        return outStack->top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size==0;
    }
};


int main(int argc, const char * argv[]) {
    
    MyQueue queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);
    
    cout << "元素共有--" << queue.size << endl;
    cout << "出队" << queue.pop();
    cout << "-队头为--" << queue.peek() << endl;
    cout << "出队" << queue.pop();
    cout << "-队头为--" << queue.peek() << endl;
    cout << "出队" << queue.pop();
    cout << "-队头为--" << queue.peek() << endl;
    cout << "出队" << queue.pop();
    cout << "-队头为--" << queue.peek() << endl;
    
    return 0;
}
