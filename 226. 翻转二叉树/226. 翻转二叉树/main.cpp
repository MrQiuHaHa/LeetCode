//
//  main.cpp
//  226. 翻转二叉树
//
//  Created by 邱俊荣 on 2021/3/10.
//

/*
 这个问题是受到 Max Howell 面试谷歌被拒的 原问题 启发的 ：
 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了

  把一颗二叉树的所有左右子树进行交换
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
    cout << "层高为：" << height << "层" << endl;
    
    return arr;
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    // 虽然前面把左右子树换了，但是无所谓递归先左还是右
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main(int argc, const char * argv[]) {
    
    TreeNode *root = createBinarySearchTree();
    cout << "翻转前的二叉树打印" << endl;
    vector<vector<int>> arr = levelOrder(root);
    for (int i = 0; i < arr.size(); i++) {
        vector<int> subArr = arr[i];
        for (int j = 0; j < subArr.size(); j++) {
            cout << subArr[j] << "--";
        }
        cout << endl;
    }
    
    cout << "翻转后的的二叉树打印" << endl;
    vector<vector<int>> arr1 = levelOrder(invertTree(root));
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> subArr = arr1[i];
        for (int j = 0; j < subArr.size(); j++) {
            cout << subArr[j] << "--";
        }
        cout << endl;
    }
    
    return 0;
}
