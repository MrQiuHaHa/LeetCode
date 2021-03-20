//
//  main.cpp
//  42. 接雨水
//
//  Created by 邱俊荣 on 2021/3/20.
//
/*
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 
 示例 1：(leetcode上有图直观看题意)
 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 输出：6
 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/trapping-rain-water
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    if (height.size() == 0) return 0;
    //解题思路：每个圆柱上可以放多少水，取决于它左边最高和右边最高中的更低的柱子
    int water = 0;
    // 先求出整数数最大的值和下标
    int maxHeight = 0;
    int maxIndex = 0;
    for (int i = 0; i < height.size(); i++) {
        if (height[i] > maxHeight) {
            maxHeight = height[i];
            maxIndex = i;
        }
    }
    // 根据最大值，将数组分两边单独求
    int leftHeight = height[0];
    for (int i = 1; i < maxIndex; i++) {
        if (leftHeight <= height[i]) {
            leftHeight = height[i];
        } else {
            water = water + leftHeight - height[i];
        }
    }
    int rightheight = height[height.size()-1];
    for (int i = (int)height.size()-2; i > maxIndex; i--) {
        if (rightheight <= height[i]) {
            rightheight = height[i];
        } else {
            water = water + rightheight - height[i];
        }
    }
    
    return water;
}

int main(int argc, const char * argv[]) {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    
    return 0;
}
