//
//  main.cpp
//  55.验证是否平衡二叉树
//
//  Created by 邱俊荣 on 2021/3/11.
//

/*
 判断该树是不是平衡二叉树。
 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
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
// 计算单个节点的高度
int depth(TreeNode *root) {
    if (root == nullptr) return 0; //探到0层的时候就往回的时候就不停+1
    return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    // 当前节点是否平衡（计算左边节点高度和右边节点高度的差值）
    bool rootBalanced = abs(depth(root->left) - depth(root->right)) <= 1;
    if (rootBalanced == false) {
        return false;
    }
    // 左节点是否平衡
    bool leftBalanced = isBalanced(root->left);
    if (leftBalanced == false) {
        return false;
    }
    // 右节点是否平衡
    bool rightBalanced = isBalanced(root->right);
    if (rightBalanced == false) {
        return false;
    }
    return  true;
}

int main(int argc, const char * argv[]) {
    
    cout << isBalanced(createBinarySearchTree()) << endl;
    
    return 0;
}
