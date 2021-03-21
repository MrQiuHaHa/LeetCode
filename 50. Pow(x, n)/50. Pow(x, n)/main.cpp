//
//  main.cpp
//  50. Pow(x, n)
//
//  Created by 邱俊荣 on 2021/3/21.
//
/*
 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。
 
 示例 1：
 输入：x = 2.00000, n = 10
 输出：1024.00000
 
 示例 2：
 输入：x = 2.10000, n = 3
 输出：9.26100
 
 示例 3：
 输入：x = 2.00000, n = -2
 输出：0.25000
 解释：2-2 = 1/22 = 1/4 = 0.25

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/powx-n
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>

using namespace std;

double myPow(double x, int n) {
    //负数的处理
    if (n < 0) {
        x = 1/x;
        n = abs(n);
    }
    if (n == 0) return 1;
    if (n == 1) return x;
    
    double half = myPow(x, n/2);
    // 判断是否奇数
    return n%2 == 0 ? half * half : half * half * x;
}

int main(int argc, const char * argv[]) {
    
    
    cout << myPow(2, 3) << endl;
    
    return 0;
}
