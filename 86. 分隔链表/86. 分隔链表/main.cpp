//
//  main.cpp
//  86. 分隔链表
//
//  Created by 邱俊荣 on 2021/4/1.
//
/*
 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 你应当 保留 两个分区中每个节点的初始相对位置。
 
 输入：head = [1,4,3,2,5,2], x = 3
 输出：[1,2,2,4,3,5]

 输入：head = [2,1], x = 2
 输出：[1,2]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/partition-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

ListNode* partition(ListNode* head, int x) {
    //新建两个虚拟头节点
    ListNode* small = new ListNode(0);
    ListNode* smallHead = small;
    ListNode* large = new ListNode(0);
    ListNode* largeHead = large;
    while (head != nullptr) {
        if (head->val < x) {
            small->next = head;
            small = head;
        } else {
            large->next = head;
            large = head;
        }
        head = head->next;
    }
    large->next = nullptr;
    small->next = largeHead->next;
    return smallHead->next;
}

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
