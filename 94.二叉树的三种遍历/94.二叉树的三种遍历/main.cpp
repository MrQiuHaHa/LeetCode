//
//  main.cpp
//  94.二叉树的三种遍历
//
//  Created by 邱俊荣 on 2021/3/10.
//

/*
 给你二叉树的根节点 root ，返回它节点值的 遍历
 */

#include <iostream>
#include <vector>
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
    vector<int> arr;
    //前序遍历方法 (根节点-左子树-右子树)
    vector<int> preorderTraversal(TreeNode* root) {
        arr.clear();
        preorderScan(root);
        return arr;
    }
    //中序遍历方法 (左子树-根节点-右子树)
    vector<int> inorderTraversal(TreeNode* root) {
        arr.clear();
        inorderScan(root);
        return arr;
    }
    //后序遍历方法 (左子树-右子树-根节点)
    vector<int> postorderTraversal(TreeNode* root) {
        arr.clear();
        postorderScan(root);
        return arr;
    }
private:
    void preorderScan(TreeNode *root) {
        if (root == nullptr) return;
        arr.push_back(root->val);
        preorderScan(root->left);
        preorderScan(root->right);
    }
    void inorderScan(TreeNode *root) {
        if (root == nullptr) return;
        inorderScan(root->left);
        arr.push_back(root->val);
        inorderScan(root->right);
    }
    void postorderScan(TreeNode *root) {
        if (root == nullptr) return;
        postorderScan(root->left);
        postorderScan(root->right);
        arr.push_back(root->val);
    }
};

/// 构建一个二叉搜索树
/// 前序遍历结果为  10 -> 8 -> 7 -> 5 -> 9 -> 12 -> 11 -> 15
/// 中序遍历结果为   5 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 15
/// 后序遍历结果为  5 -> 7 -> 9 -> 8 -> 11 -> 15 -> 12 -> 10
/*
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

int main(int argc, const char * argv[]) {
    
    TreeNode *rootNode = createBinarySearchTree();
    Solution *obj = new Solution();
    //前序遍历测试
    obj->preorderTraversal(rootNode);
    for (int i = 0; i < obj->arr.size(); i++) {
        cout << obj->arr[i] << "->"; // 打印结果为 10 -> 8 -> 7 -> 5 -> 9 -> 12 -> 11 -> 15 答案正确
    }
    cout << endl;
    //中序遍历测试
    obj->inorderTraversal(rootNode);
    for (int i = 0; i < obj->arr.size(); i++) {
        cout << obj->arr[i] << "->"; // 打印结果为 5 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 15 答案正确
    }
    cout << endl;
    //后序遍历测试
    obj->postorderTraversal(rootNode);
    for (int i = 0; i < obj->arr.size(); i++) {
        cout << obj->arr[i] << "->"; // 打印结果为 5 -> 7 -> 9 -> 8 -> 11 -> 15 -> 12 -> 10 答案正确
    }
    cout << endl;
    return 0;
}

