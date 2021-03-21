//
//  main.cpp
//  62. 圆圈中最后剩下的数字
//
//  Created by 邱俊荣 on 2021/3/21.
//
/*
 0,1,··,n-1这n个数字排成一个圆圈，从数字0开始，
 每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 
 输入: n = 5, m = 3
 输出: 3
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>

using namespace std;

// 约瑟夫环问题，通过链表可以解决，但是此处不借住链表
int lastRemaining(int n, int m) {
    
    if (n == 1) return 0;
    int x = lastRemaining(n - 1, m);// 动态规划思想，推导n-1和n的关系公司
    return (m + x) % n;
}

int main(int argc, const char * argv[]) {
    
    cout << lastRemaining(5, 3) << endl;
    
    return 0;
}
