//
//  main.cpp
//  53. 最大子序和
//
//  Created by 邱俊荣 on 2021/3/18.
//
/*
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 示例 1：
 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 输出：6
 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-subarray
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

// 使用分治的思想处理
int maxSubArray(vector<int>& nums, int begin, int end) {
    if (end - begin < 2) return nums[begin]; // 只有一个元素
    
    int mid = (begin + end) >> 1;
    int leftMax = nums[mid-1];
    int leftSum = 0;
    for (int i = mid-1; i >= begin; i--) {
        leftSum = leftSum + nums[i];
        leftMax = max(leftMax, leftSum);
    }
    
    int rightMax = nums[mid];
    int rightSum = 0;
    for (int i = mid; i < end; i++) {
        rightSum = rightSum + nums[i];
        rightMax = max(rightMax, rightSum);
    }
    
    return max(leftMax+rightMax, max(maxSubArray(nums, begin, mid), maxSubArray(nums, mid, end)));
}


int maxSubArray(vector<int>& nums) {
//    return maxSubArray(nums, 0, nums.size());
    
    // 下面使用动态规划思想，状态转移分析。
    // dp[i] 代表的是以nums的第i个元素结尾的最大子序后，而dp[i]可以根据dp[i-1]的值推出
    if (nums.size() == 0) return 0;
    int dp[nums.size()];
    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        if (dp[i-1] <= 0) { //如果前一个元素结尾的最大子序和是<=0，则抛弃他们自己作为最大和
            dp[i] = nums[i];
        } else {
            dp[i] = dp[i-1]+nums[i];
        }
        maxSum = max(dp[i], maxSum);
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    
    return 0;
}
