//
//  main.cpp
//  654. 最大二叉树
//
//  Created by 邱俊荣 on 2021/3/29.
//
/*
 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
 二叉树的根是数组 nums 中的最大元素。
 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
 返回有给定数组 nums 构建的 最大二叉树。

 输入：nums = [3,2,1,6,0,5]
 输出：[6,3,5,null,2,0,null,null,1]
 解释：递归调用如下所示：
 - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
     - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
         - 空数组，无子节点。
         - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
             - 空数组，无子节点。
             - 只有一个元素，所以子节点是一个值为 1 的节点。
     - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
         - 只有一个元素，所以子节点是一个值为 0 的节点。
         - 空数组，无子节点。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

class Solution {
    
    TreeNode* findRoot(vector<int>& nums, int l, int r) {
        if (l == r) return nullptr;
        
        // 找出[l, r)范围内最大值的索引
        int maxIdx = l;
        for (int i = l + 1; i < r; i++) {
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        TreeNode *root = new TreeNode(nums[maxIdx]);
        root->left = findRoot(nums, l, maxIdx);
        root->right = findRoot(nums, maxIdx + 1, r);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if (nums.size() == 0) return nullptr;
        return findRoot(nums, 0, (int)nums.size());
    }
    ~Solution(){
        cout << "Solution obj dealloc" << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {3,2,1,6,0,5};
    
    shared_ptr<Solution> solu(new Solution());
    TreeNode *root = solu->constructMaximumBinaryTree(nums);
    
    // 层序遍历打印结果
    queue<TreeNode *> que;
    que.push(root);
    while (que.empty() != true) {
        
        TreeNode *node = que.front();
        que.pop();
        cout << node->val << "->";
        
        if (node->left != nullptr) {
            que.push(node->left);
        }
        if (node->right != nullptr) {
            que.push(node->right);
        }
    }
    
    cout << endl;
    
    return 0;
}
