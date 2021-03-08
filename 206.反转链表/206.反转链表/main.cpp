//
//  main.cpp
//  206.反转链表
//
//  Created by 邱俊荣 on 2021/3/8.
//


/*
    反转一个单链表
 
    示例:
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL
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

/// 递归解法
void reverseList(ListNode* head) {

    if (head->next == nullptr || head == nullptr) return; // head == nullptr是容错当前链表就是个NULL
    reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    
}

/// 迭代解法
void reverseList1(ListNode* head) {

    if (head->next == nullptr || head == nullptr) return; // head == nullptr是容错当前链表就是个NULL
    ListNode *newHead = nullptr;
    while (head) {
        ListNode *tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    
}

int main(int argc, const char * argv[]) {
    
    //先创建一个链表试验 4->1->5->9
    ListNode *node = new ListNode(4);
    node->next = new ListNode(1);
    node->next->next = new ListNode(5);
    ListNode *lastNode = new ListNode(9);
    node->next->next->next = lastNode;
    
//    reverseList(node);
    reverseList1(node);
    
    while (lastNode) {
        cout << lastNode->val << endl;  // 9->5->1->4
        lastNode = lastNode->next;
    }
    
    return 0;
}
//class Solution {
//    public ListNode reverseList(ListNode head) {
//        if (head == null || head.next == null) return head;
//
//        ListNode newHead = reverseList(head.next);
//        head.next.next = head;
//        head.next = null;
//        return newHead;
//    }
//}
