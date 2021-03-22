//
//  main.cpp
//  235. 二叉搜索树的最近公共祖先
//
//  Created by 邱俊荣 on 2021/3/22.
//
/*
 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 
 示例 1:
 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 输出: 6
 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 
 示例 2:
 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 输出: 2
 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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

/* 构建一颗二叉树用于测试代码
            10
           /  \
          8   12
         / \  / \
        7  9 11 15
       /
      5
 */
TreeNode * createBinarySearchTree() {
    TreeNode *root = new TreeNode(10);
    TreeNode *node1 = new TreeNode(8);
    TreeNode *node2 = new TreeNode(12);
    TreeNode *node3 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(11);
    TreeNode *node5 = new TreeNode(9);
    TreeNode *node6 = new TreeNode(15);
    TreeNode *node7 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node5;
    node2->left = node4;
    node2->right = node6;
    node3->left = node7;
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root->val == p->val || root->val == q->val) return root;
    // 去以root.left为根节点的二叉树中查找p、q的最近公共祖先
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    // 去以root.right为根节点的二叉树中查找p、q的最近公共祖先
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) return root;
    return (left != nullptr) ? left : right;
}

int main(int argc, const char * argv[]) {
    
    TreeNode *node = lowestCommonAncestor(createBinarySearchTree(), new TreeNode(8), new TreeNode(12));
    
    cout << node->val << endl;
    
    return 0;
}
