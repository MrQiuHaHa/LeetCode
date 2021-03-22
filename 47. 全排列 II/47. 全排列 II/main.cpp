//
//  main.cpp
//  47. 全排列 II
//
//  Created by 邱俊荣 on 2021/3/22.
//
/*
 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 示例 1：
 输入：nums = [1,1,2]
 输出：[[1,1,2],[1,2,1],[2,1,1]]
 
 示例 2：
 输入：nums = [1,2,3]
 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/permutations-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> vis;

public:
    // 所有组合问题的算法，都可以采用回溯（深度优先，当前层选定一种可能继续往下）
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
