//
//  main.cpp
//  141. 环形链表
//
//  Created by 邱俊荣 on 2021/3/8.
//

/*
 给定一个链表，判断链表中是否有环。

 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

 如果链表中存在环，则返回 true 。 否则，返回 false 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/linked-list-cycle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    
    // head == nullptr是容错当前链表就是个NULL
    if (head == nullptr) return false;
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while (fast && fast->next) {
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    //先创建一个链表试验 4->1->5->9
    ListNode *node = new ListNode(4);
    node->next = new ListNode(1);
    node->next->next = new ListNode(5);
    node->next->next->next = new ListNode(9);
    
    node->next->next->next->next = node->next;//创建环
    
    cout << hasCycle(node) << endl;
    
    return 0;
}
