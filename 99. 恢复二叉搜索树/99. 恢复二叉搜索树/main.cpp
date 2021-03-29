//
//  main.cpp
//  99. 恢复二叉搜索树
//
//  Created by 邱俊荣 on 2021/3/28.
//

/*
 给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/recover-binary-search-tree
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
          8   7
         / \  / \
        12  9 11 15
       /
      5
 */
TreeNode * createBinarySearchTree() {
    TreeNode *root = new TreeNode(10);
    TreeNode *node1 = new TreeNode(8);
    TreeNode *node2 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(12);
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
    TreeNode *prev;//中序遍历时前一个节点保留
    TreeNode *first;//第一个错误节点
    TreeNode *second;//第二个错误节点
    void find(TreeNode *node) {
        // 出现了逆序对
        if (prev != nullptr && prev->val > node->val) {
            // 第2个错误节点：最后一个逆序对中较小的那个节点
            second = node;

            // 第1个错误节点：第一个逆序对中较大的那个节点
            if (first != nullptr) return;
            first = prev;
        }
        prev = node;
    }
    void findWrongNodes(TreeNode *root) {
        if (root == nullptr) return;
        findWrongNodes(root->left);
        find(root);
        findWrongNodes(root->right);
    }
    
public:
    //析构函数必须是public，不然其他地方无法销毁当前对象
    ~Solution(){
        cout << "Solution obj dealloc" << endl;
    }
    void recoverTree(TreeNode* root) {
        findWrongNodes(root);
        // 交换2个错误节点的值
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    
};
int main(int argc, const char * argv[]) {
    
    TreeNode *root = createBinarySearchTree();
    
    shared_ptr<Solution> solu(new Solution());
    solu->recoverTree(root);
    
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
