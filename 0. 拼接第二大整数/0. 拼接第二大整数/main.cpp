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
    
    for (int begin = 0; begin < (int)nums.size(); begin++) {
        
        for (int end = (int)nums.size()-1; end > begin; end--) {
            string a = to_string(nums[end]);
            string b = to_string(nums[end-1]);
            string ab = a+b;
            string ba = b+a;
            int ab_int, ba_int;
            stringstream sStream1;
            sStream1 << ab;
            sStream1 >> ab_int;
            stringstream sStream2;
            sStream2 << ba;
            sStream2 >> ba_int;
            
            if (ab_int > ba_int) {
                
                int tmp = nums[end];
                nums[end] = nums[end-1];
                nums[end-1] = tmp;
            }
        }
    }
    
    //求第二大的数，则把前面第一和第二个元素换下位置
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
