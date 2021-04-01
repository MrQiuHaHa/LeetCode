//
//  main.cpp
//  75. 颜色分类
//
//  Created by 邱俊荣 on 2021/4/1.
//
/*
 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，
 原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 示例 1：
 输入：nums = [2,0,2,1,1,0]
 输出：[0,0,1,1,2,2]
 
 示例 2：
 输入：nums = [2,0,1]
 输出：[0,1,2]
 
 示例 3：
 输入：nums = [0]
 输出：[0]
 
 示例 4：
 输入：nums = [1]
 输出：[1]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sort-colors
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void sortColors(vector<int>& nums) {
    int i = 0;
    int l = 0;
    int r = (int)nums.size() - 1;
    while (i <= r) {
        if (nums[i] == 0) {
            swap(nums, i++, l++);
        } else if (nums[i] == 1) {
            i++;
        } else {
            swap(nums, i, r--);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {2,2,1,0,1};
    sortColors(nums);
    for (int num : nums) {
        cout << num << ",";
    }
    cout << endl;
    
    return 0;
}
