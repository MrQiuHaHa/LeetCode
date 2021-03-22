//
//  main.cpp
//  160. 相交链表
//
//  Created by 邱俊荣 on 2021/3/22.
//
/*
 编写一个程序，找到两个单链表相交的起始节点。

 如下面的两个链表：
 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 输出：Reference of the node with value = 8
 输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// 用A链表的尾结点串上B链表的头节点，再用B链表的尾节点串上A链表的头节点，如此，两个链表的元素的就相等了，再同步遍历
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    if (headA == nullptr || headB == nullptr) return nullptr;
    
    ListNode *curA = headA;
    ListNode *curB = headB;
    
    while (curA != curB) {
        
        curA = curA == nullptr ? headB : curA->next;
        curB = curB == nullptr ? headA : curB->next;
    }
    
    return curA;
}

int main(int argc, const char * argv[]) {

    
    return 0;
}
