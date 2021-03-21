//
//  main.cpp
//  113. 路径总和 II
//
//  Created by 邱俊荣 on 2021/3/22.
//

/*
 给你二叉树的根节点 root 和一个整数目标和 targetSum ，
 找出所有 从根节点到叶子节点 路径总和等于targetSum。


 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/path-sum-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

class Solution {
    
    vector<vector<int>> res;
    vector<int> subRes;
    
    void dpSum(TreeNode* root, int targetSum) {
        
        if (root == nullptr) return;
        
        subRes.push_back(root->val);
        targetSum = targetSum - root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            res.push_back(subRes);
        }
        
        dpSum(root->left, targetSum);
        dpSum(root->right, targetSum);
        subRes.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        dpSum(root, targetSum);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
