//
//  main.cpp
//  283. 移动零
//
//  Created by 邱俊荣 on 2021/3/21.
//

/*
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

 示例:
 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/move-zeroes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    if (nums.size() == 0) return;
    for (int i = 0, cur = 0; i < nums.size(); i++) {
        if (nums[i] == 0) continue;
        if (cur != i) { //如果当前位置不等于0.则判断之前是否有0
            nums[cur] = nums[i];
            nums[i] = 0;
        }
        //cur记录当前第一个0的位置
        cur++;
    }
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for (int num : nums) {
        cout << num << ",";
    }
    cout << endl;
    
    return 0;
}
