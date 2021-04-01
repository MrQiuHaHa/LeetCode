//
//  main.cpp
//  0. 拼接第二大整数
//
//  Created by 邱俊荣 on 2021/4/1.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/*
 输入一个int正数数组，返回由这些数拼接成的最大的整数
 
 思路：比较两个字符串s1,s2大小的时候，先将它们拼接起来，
      比较s1+s2,和s2+s1那个大，如果s1+s2大，那说明s1应该放前面，
      所以按这个规则，s2就应该排在s1前面。
      用冒泡法两两比较
 */
void makeMax(vector<int> &nums){
    
    for (int end = (int)nums.size()-1; end > 0; end--) {
        int lastMove = 0;//记录最后一次交换的位置，下次内循环从最后交换位置进行遍历
        //冒泡法，每次内循环都把最小当前循环内最小的放到后面去了
        for (int begin = 0; begin < end; begin++) {
            string a = to_string(nums[begin]);
            string b = to_string(nums[begin+1]);
            string ab = a+b;
            string ba = b+a;
            int ab_int, ba_int;
            stringstream sStream1;
            sStream1 << ab;
            sStream1 >> ab_int;
            stringstream sStream2;
            sStream2 << ba;
            sStream2 >> ba_int;
            //ab组合小于ba组合，则说明a的数组的位置必然在b的后面
            if (ab_int < ba_int) {
                int tmp = nums[begin];
                nums[begin] = nums[begin+1];
                nums[begin+1] = tmp;
                lastMove = begin+1;
            }
            
        }
        end = lastMove;
    }
    
    //求第二大的数，则把前面第一和第二个元素换下位置，屏蔽则是求的最大拼接整数
    int tmp = nums[0];
    nums[0] = nums[1];
    nums[1] = tmp;
}


int main(int argc, const char * argv[]) {
    
    vector<int> nums = {3,32,321,4,42,43};
    makeMax(nums);
    for (int num : nums) {
        cout << num;
    }
    cout << endl;
    
    return 0;
}
