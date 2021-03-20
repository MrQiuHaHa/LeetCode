//
//  main.cpp
//  98. 验证二叉搜索树
//
//  Created by 邱俊荣 on 2021/3/20.
//

/*
 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 
 假设一个二叉搜索树具有如下特征：
 节点的左子树只包含小于当前节点的数。
 节点的右子树只包含大于当前节点的数。
 所有左子树和右子树自身必须也是二叉搜索树。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
//    TreeNode *node3 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(11);
//    TreeNode *node5 = new TreeNode(9);
    TreeNode *node6 = new TreeNode(15);
//    TreeNode *node7 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
//    node1->left = node3;
//    node1->right = node5;
    node2->left = node4;
    node2->right = node6;
//    node3->left = node7;
    return root;
}

// 动态规划思想：
// dp[i]是否二叉搜索树，取决dp[i->left] && dp[i->right] 都是二叉搜索树，
// 且自己必须大于左节点小于右节点，（且必须大于前驱节点小于后继节点）
bool isValidBST(TreeNode* root) {
    
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return true;
    }
    
    //后续节点
    int succeedVal = 0;
    TreeNode *succeedNode = root->right;
    while (succeedNode) {
        succeedVal = succeedNode->val;
        succeedNode = succeedNode->left;
    }
    //前驱
    int predecVal = 0;
    TreeNode *predecNode = root->left;
    while (predecNode) {
        predecVal = predecNode->val;
        predecNode = predecNode->right;
    }
    if (root->left == nullptr) {
        // 小于自己的右节点，且必须小于后继节点
        if (root->val < root->right->val && root->val < succeedVal) {
            return isValidBST(root->right);
        } else {
            return false;
        }
    }
    if (root->right == nullptr) {
        // 大于自己的左节点，且必须大于前驱节点
        if (root->val > root->left->val && root->val > predecVal) {
            return isValidBST(root->left);
        } else {
            return false;
        }
    }
    
    if (root->val > root->left->val && root->val < root->right->val
        && root->val < succeedVal && root->val > predecVal) {
        return isValidBST(root->left) && isValidBST(root->right);
    } else {
        return false;
    }
}
// 中序遍历思想，只要是二叉搜索树，中序遍历的结果必然是升序。。。
bool isValidBST1(TreeNode* root) {
    if (root == nullptr) return true;
    
    stack<TreeNode*> stack;
    
    long long inorder = (long long)INT_MIN - 1;

    while (true) {
        if (stack.empty()) {
            break;
        }
        while (root != nullptr) {
            stack.push(root);
            root = root -> left;
        }
        root = stack.top();
        stack.pop();
        // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
        if (root -> val <= inorder) return false;
        inorder = root -> val;
        root = root -> right;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    cout << isValidBST1(createBinarySearchTree()) << endl;
    
    return 0;
}
