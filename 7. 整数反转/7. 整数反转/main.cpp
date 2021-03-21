//
//  main.cpp
//  7. 整数反转
//
//  Created by 邱俊荣 on 2021/3/21.
//
/*
 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 假设环境不允许存储 64 位整数（有符号或无符号）。
 
 输入：x = 123
 输出：321
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-integer
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>

using namespace std;

int reverseInt(int x) {
    long res = 0;
    while (x != 0) {
        res = res * 10 + x % 10;//每次让先前的结果*10，再拿出x的最后一位数+
        if (res > INT_MAX || res < INT_MIN) return 0;
        x /= 10;//每次削去最后一位 如：123 -> 12
    }
    return (int) res;
}

int main(int argc, const char * argv[]) {
    
    cout << reverseInt(123) << endl;
    
    return 0;
}
