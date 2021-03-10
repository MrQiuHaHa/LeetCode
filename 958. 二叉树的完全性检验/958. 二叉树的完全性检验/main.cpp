//
//  main.cpp
//  958. 二叉树的完全性检验
//
//  Created by 邱俊荣 on 2021/3/10.
//

/*
 给定一个二叉树，确定它是否是一个完全二叉树(层序遍历处理)
 */

#include <iostream>
#include <vector>
#include <queue>

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

bool isCompleteTree(TreeNode* root) {
    if (root == nullptr) return true;
    
    bool leaf = false;
    queue<TreeNode *> que;
    que.push(root);
    
    while (que.empty() != true) {
        
        TreeNode *node = que.front();
        if (leaf == true) {
            if (node->left != nullptr || node->right != nullptr) {
                return false;
            }
        }
        
        que.pop();
        
        if (node->left != nullptr && node->right != nullptr) {
            que.push(node->left);
            que.push(node->right);
        } else if (node->left == nullptr && node->right != nullptr) {
            return false;
        } else if (node->left != nullptr && node->right == nullptr) {
            leaf = true;// 后面的节点全部都需要是叶子节点
            que.push(node->left);
        } else {// 后面的节点全部都需要是叶子节点
            leaf = true;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    cout << isCompleteTree(createBinarySearchTree()) << endl;
    return 0;
}
