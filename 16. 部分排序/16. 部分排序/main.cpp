//
//  main.cpp
//  16. 部分排序
//
//  Created by 邱俊荣 on 2021/3/29.
//
/*
 给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。
 注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，
      若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

 示例：
 输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
 输出： [3,9]
 
 提示：
 0 <= len(array) <= 1000000

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sub-sort-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> subSort(vector<int>& array) {
    if (array.size() == 0) return { -1, -1 };
    
    // 从左扫描到右寻找逆序对（正序：逐渐变大）
    int max = array[0];
    // 用来记录最右的那个逆序对位置
    int r = -1;
    for (int i = 1; i < array.size(); i++) {
        if (array[i] >= max) {
            max = array[i];
        } else {
            r = i;
        }
    }
    
    // 提前结束
    if (r == -1) return { -1, -1 };
    
    // 从右扫描到左寻找逆序对（正序：逐渐变小）
    int min = array[array.size() - 1];
    // 用来记录最左的那个逆序对位置
    int l = -1;
    for (int i = (int)array.size() - 2; i >= 0; i--) {
        if (array[i] <= min) {
            min = array[i];
        } else {
            l = i;
        }
    }
    
    return { l, r };
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
