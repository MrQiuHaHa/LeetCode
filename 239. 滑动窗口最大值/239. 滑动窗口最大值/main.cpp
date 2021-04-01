//
//  main.cpp
//  239. 滑动窗口最大值
//
//  Created by 邱俊荣 on 2021/4/1.
//
/*
 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 返回滑动窗口中的最大值。
 
 示例 1：
 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 输出：[3,3,5,5,6,7]
 解释：
 滑动窗口的位置                最大值
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
  1 [3  -1  -3] 5  3  6  7       3
  1  3 [-1  -3  5] 3  6  7       5
  1  3  -1 [-3  5  3] 6  7       5
  1  3  -1  -3 [5  3  6] 7       6
  1  3  -1  -3  5 [3  6  7]      7

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sliding-window-maximum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> q;
    for (int i = 0; i < k; ++i) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};
    for (int i = k; i < n; ++i) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        while (q.front() <= i - k) {
            q.pop_front();
        }
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
