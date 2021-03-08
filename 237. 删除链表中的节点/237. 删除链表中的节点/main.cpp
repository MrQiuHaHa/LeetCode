//
//  main.cpp
//  237. 删除链表中的节点
//
//  Created by 邱俊荣 on 2021/3/8.
//

/*
 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点
 输入：head = [4,5,1,9], node = 5
 输出：[4,1,9]
 解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/delete-node-in-a-linked-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    if(node->next->next == NULL) {
        node->next = NULL;
        return;
    } else {
        node->next->val = node->next->next->val;
    }
    deleteNode(node->next);
}

int main(int argc, const char * argv[]) {
    
    ListNode *node = new ListNode(4);
    node->next = new ListNode(1);
    node->next->next = new ListNode(5);
    node->next->next->next = new ListNode(9);
    
    deleteNode(node->next);//删除值为1的节点
    while (node) {
        cout << node->val << endl;
        node = node->next;
    }
    
    return 0;
}
