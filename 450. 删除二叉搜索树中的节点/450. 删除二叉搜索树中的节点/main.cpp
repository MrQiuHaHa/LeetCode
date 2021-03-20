//
//  main.cpp
//  450. 删除二叉搜索树中的节点
//
//  Created by 邱俊荣 on 2021/3/20.
//
/*
 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
 返回二叉搜索树（有可能被更新）的根节点的引用。

 一般来说，删除节点可分为两个步骤：
 首先找到需要删除的节点；
 如果找到了，删除它。
 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <stack>
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

// 删除节点的具体实现。分三种情况：度为0，为1，为2的情况
void deleteNodeFun(TreeNode *root, TreeNode *parentNode, TreeNode **startNode)
{
    //如果当前是叶子节点，直接父节点删除他
    if (root->left == nullptr && root->right == nullptr) {
        if (parentNode == nullptr) {
            *startNode = nullptr;
            return;
        }
        if (parentNode->left == root) {//节点是父节点的左子节点
            parentNode->left = nullptr;
        } else if (parentNode->right == root) {//节点是父节点的右子节点
            parentNode->right = nullptr;
        }
        return;;
    }
    // 删除的是度为1的节点
    if (root->left == nullptr || root->right == nullptr) {
        if (parentNode == nullptr) { //需要考虑删除的是度为1但是又刚好是根节点情况//修改开始根节点
            *startNode = root->left == nullptr ? root->right : root->left;
            return;
        }
        if (parentNode->left == root) {//节点是父节点的左子节点
            parentNode->left = root->left == nullptr ? root->right : root->left;
        } else if (parentNode->right == root) {//节点是父节点的右子节点
            parentNode->right = root->left == nullptr ? root->right : root->left;
        }
        return;
    }
    // 删除度为2的节点，需要先寻找前驱
    TreeNode *predecNode = root->left;
    parentNode = root;
    while (true) {
        if (predecNode->right == nullptr) {// predecNode就是前驱节点了，删除
            root->val = predecNode->val;//前驱节点的值覆盖要删除的节点
            deleteNodeFun(predecNode, parentNode, startNode);
            break;
        }
        parentNode = predecNode;
        predecNode = predecNode->right;
        
    }
}

// 删除节点方案：度为2的需要寻找前驱或者后续节点的值覆盖当前节点值，再删除对应的前驱或者后继节点
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    
    TreeNode *startNode = root;
    TreeNode *parentNode = nullptr;//保留当前遍历节点的父节点

    while (root) {
        if (key == root->val) { //找到了要删除的节点
            deleteNodeFun(root, parentNode, &startNode);
            break;
        } else if (key < root->val) {
            parentNode = root;
            root = root->left;
        } else {
            parentNode = root;
            root = root->right;
        }
    }
    return startNode;
}

int main(int argc, const char * argv[]) {
    
    TreeNode *root = deleteNode(createBinarySearchTree(), 8);
    // 中序遍历下删除结果
    stack<TreeNode *> st;
    while (true) {
        if (root != nullptr) {
            st.push(root);
            root = root->left;
        } else if (st.empty()) {
            break;
        } else {
            root = st.top();
            cout << root->val << "->";
            st.pop();
            root = root->right;
        }
    }
    cout << endl;
    
    return 0;
}
