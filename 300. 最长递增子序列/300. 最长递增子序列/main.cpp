//
//  main.cpp
//  300. 最长递增子序列
//
//  Created by 邱俊荣 on 2021/3/19.
//

/*
 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 示例 1：
 输入：nums = [10,9,2,5,3,7,101,18]
 输出：4
 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;
// 时间复杂度： n^2
int lengthOfLIS(vector<int>& nums) {

    if (nums.size() == 0) return 0;
    // 牌顶数组的元素个数就是最长上升子序
    vector<int> top;
    // 遍历所有的牌
    for (int num : nums) {
        if (top.size() == 0 || top.back() < num) { // 牌堆是升序的
            // 说明牌堆里的最大元素都比当前num小，所以直接新建牌堆
            top.push_back(num);
            continue;
        }
        int topIndex = 0; // 从牌顶数组0开始遍历
        while (topIndex < top.size()) {
            //找到一个>=num的牌顶
            if (top[topIndex] >= num) {
                top[topIndex] = num; // 更新牌顶
                break;
            }
            topIndex++;
        }
    }
    return top.size();
}
// 优化：top数组是有序，所以寻找更新牌顶位置可以采用二分搜索定位。时间复杂度： n * lon(n)
int lengthOfLIS1(vector<int>& nums) {

    if (nums.size() == 0) return 0;
    // 牌顶数组的元素个数就是最长上升子序
    vector<int> top;
    // 遍历所有的牌
    for (int num : nums) {
        if (top.size() == 0 || top.back() < num) { // 牌堆是升序的
            // 说明牌堆里的最大元素都比当前num小，所以直接新建牌堆
            top.push_back(num);
            continue;
        }
        // 二分大法定位
        int begin = 0;
        int end = (int)top.size();
        while (begin < end) {
            
            int mid = (begin + end) >> 1;
            if (num == top[mid]) {
                top[mid] = num;
                break; //查找到元素直接覆盖牌顶，退出while循环
            } else if (num < top[mid]) {
                end = mid;
            } else {
                begin = mid+1;
            }
        }

        if (begin == end) { // begin = end说明没有查找到该元素(或者查找到了，但是是最后一个元素，重复覆盖即可)
            top[end] = num;
        }

    }
    return top.size();
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS1(nums) << endl;
    return 0;
}
