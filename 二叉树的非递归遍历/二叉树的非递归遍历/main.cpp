//
//  main.cpp
//  二叉树的非递归遍历
//
//  Created by 邱俊荣 on 2021/3/14.
//

#include <iostream>
#include <vector>
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



class Solution {
public:
    
    //前序遍历方法 (根节点-左子树-右子树) //// 利用栈实现非递归方式
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        if (root == nullptr) {
            return arr;
        }
        stack<TreeNode *> st;
        while (true) {
            if (root != nullptr) {
                
                if (root->right != nullptr) {
                    st.push(root->right);
                }
                arr.push_back(root->val);
                root = root->left;
                
            } else if (st.empty()) {
                break;
            } else {
                root = st.top();
                st.pop();
            }
        }
        return arr;
    }
        
    //中序遍历方法 (左子树-根节点-右子树) //// 利用栈实现非递归方式
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        if (root == nullptr) {
            return arr;
        }
        stack<TreeNode *> st;
        while (true) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else if (st.empty()) {
                break;
            } else {
                root = st.top();
                arr.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }
        return arr;
    }
    //后序遍历方法 (左子树-右子树-根节点)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        if (root == nullptr) {
            return arr;
        }
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *prev = nullptr;
        while (!st.empty()) {
            TreeNode *node = st.top();
            bool isLeaf = node->left == nullptr && node->right == nullptr;
            if (isLeaf || (prev != nullptr && (prev == node->left || prev == node->right))) {
                prev = st.top();
                arr.push_back(st.top()->val);
                st.pop();
            } else {
                if (node->right != nullptr) {
                    st.push(node->right);
                }
                if (node->left != nullptr) {
                    st.push(node->left);
                }
            }
        }
        return arr;
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
    
    for (int i = 0; i < obj->preorderTraversal(rootNode).size(); i++) {
        cout << obj->preorderTraversal(rootNode)[i] << "->";
        // 打印结果为 10 -> 8 -> 7 -> 5 -> 9 -> 12 -> 11 -> 15 答案正确
    }
    cout << endl;
    //中序遍历测试
    
    for (int i = 0; i < obj->inorderTraversal(rootNode).size(); i++) {
        cout << obj->inorderTraversal(rootNode)[i] << "->";
        // 打印结果为 5 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 15 答案正确
    }
    cout << endl;
    //后序遍历测试
    
    for (int i = 0; i < obj->postorderTraversal(rootNode).size(); i++) {
        cout << obj->postorderTraversal(rootNode)[i] << "->";
        // 打印结果为 5 -> 7 -> 9 -> 8 -> 11 -> 15 -> 12 -> 10 答案正确
    }
    cout << endl;
    return 0;
}

