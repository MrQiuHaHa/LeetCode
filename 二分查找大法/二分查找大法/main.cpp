//
//  main.cpp
//  二分查找大法
//
//  Created by 邱俊荣 on 2021/3/16.
//

/*
 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */

#include <iostream>
#include <vector>
using namespace std;

int search_binary(vector<int>& nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    int begin = 0;
    int end = nums.size();
    
    while (true) {
        if (begin == end) {
            return -1;
        }
        int mid = (begin + end)/2;
        if (target > nums[mid]) {
            begin = mid+1;
        } else if (target < nums[mid]) {
            end = mid;
        } else {
            return mid;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {-1,0,3,5,9,12};
    cout << search_binary(nums, 9) << endl;
    
    return 0;
}
