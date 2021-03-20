//
//  main.cpp
//  203. 移除链表元素
//
//  Created by 邱俊荣 on 2021/3/20.
//
/*
 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，
 并返回 新的头节点 。
 输入：head = [1,2,6,3,4,5,6], val = 6
 输出：[1,2,3,4,5]
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return nullptr;

    ListNode *newHead = head;
    ListNode *parentNode = nullptr;
    while (head) {
        if (head->val == val) {
            if (parentNode == nullptr) {
                //删除的是头节点
                newHead = head->next;
                head = newHead;
            } else {
                parentNode->next = head->next;
                head->next = nullptr;
                head = parentNode->next;
            }
            
        } else {
            parentNode = head;
            head = head->next;
        }
    }
    return newHead;
}

int main(int argc, const char * argv[]) {
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    
    ListNode *node = removeElements(head, 6);
    while (node) {
        
        cout << node->val << "->";
        node = node->next;
    }
    cout << endl;
    return 0;
}
