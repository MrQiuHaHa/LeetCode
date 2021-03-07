//
//  main.cpp
//  509-斐波那契
//
//  Created by 邱俊荣 on 2021/3/7.
//

/*
 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

 F(0) = 0，F(1) = 1
 F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 给你 n ，请计算 F(n) 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/fibonacci-number
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int first = 0;
    int second = 1;
    for (int i = 0; i < n-1; i++) {
        int sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}

int main(int argc, const char * argv[]) {
    
    cout << fib(10) << endl;
    
    return 0;
}
