//
//  main.cpp
//  572. 另一个树的子树
//
//  Created by 邱俊荣 on 2021/3/29.
//
/*
 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

 示例 1:
 给定的树 s:
      3
     / \
    4   5
   / \
  1   2
 给定的树 t：
    4
   / \
  1   2
 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
 
 示例 2:
 给定的树 s：

      3
     / \
    4   5
   / \
  1   2
     /
    0
 给定的树 t：

    4
   / \
  1   2
 返回 false。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/subtree-of-another-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if (s == nullptr) {
            return false;
        } else if (s->val == t->val && isSameTree(s, t)) {
            return true;
        } else {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        return (p == q) || (p != nullptr && q != nullptr && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    
    ~Solution(){
        cout << "obj dealloc ~" << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
