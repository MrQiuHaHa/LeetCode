//
//  main.cpp
//  234. 回文链表
//
//  Created by 邱俊荣 on 2021/3/29.
//

/*
 请判断一个链表是否为回文链表。

 示例 1:

 输入: 1->2
 输出: false
 示例 2:

 输入: 1->2->2->1
 输出: true
 */

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   bool isPalindrome(ListNode* head) {
       vector<int> vals;
       while (head != nullptr) {
           vals.emplace_back(head->val);
           head = head->next;
       }
       for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
           if (vals[i] != vals[j]) {
               return false;
           }
       }
       return true;
   }
};
int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
