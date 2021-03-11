//
//  main.cpp
//  102. 二叉树的层序遍历
//
//  Created by 邱俊荣 on 2021/3/10.
//

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
// 层序遍历、顺便计算树的高度
vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    
    // 计算树的高度
    int height = 0;
    // 存储着每一层的元素数量
    int levelSize = 1;
    
    vector<vector<int>> arr;
    vector<int> subArr;
    queue<TreeNode *> que;
    que.push(root);
    while (que.empty() != true) {
        
        TreeNode *node = que.front();
        que.pop();
        levelSize--;
        subArr.push_back(node->val);
        
        if (node->left != nullptr) {
            que.push(node->left);
        }
        if (node->right != nullptr) {
            que.push(node->right);
        }
        if (levelSize == 0) { // 当levelSize数量到0的时候，代表当前层的节点访问完毕，要进入下一层了。
            height++;
            levelSize = (int)que.size();// 重新读取下层的节点个数
            vector<int> levArr;
            for (int i = 0; i < subArr.size(); i++) {
                levArr.push_back(subArr[i]);
            }
            arr.push_back(levArr);
            subArr.clear();
        }
    }
    cout << "层序遍历计算层高为：" << height << "层" << endl;
    
    return arr;
}

// 计算单个节点的高度（二叉树深度）递归方法
int depth(TreeNode *root) {
    if (root == nullptr) return 0; //探到0层的时候就往回的时候就不停+1
    return max(depth(root->left), depth(root->right)) + 1;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> arr = levelOrder(createBinarySearchTree());
    
    for (int i = 0; i < arr.size(); i++) {
        vector<int> subArr = arr[i];
        for (int j = 0; j < subArr.size(); j++) {
            cout << subArr[j] << "--";
        }
        cout << endl;
    }
    
    cout << "递归方法计算层高为：" << depth(createBinarySearchTree()) << "层" << endl;
    
    
    return 0;
}
