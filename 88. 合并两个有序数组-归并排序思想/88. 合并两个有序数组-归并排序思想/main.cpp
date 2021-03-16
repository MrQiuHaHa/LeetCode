//
//  main.cpp
//  88. 合并两个有序数组-归并排序思想
//
//  Created by 邱俊荣 on 2021/3/16.
//
/*
 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 输出：[1,2,2,3,5,6]
 */
#include <iostream>
#include <vector>

using namespace std;


void mergeSort(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int li = 0; //copyArr的遍历下标
    int ri = 0; //nums2的遍历下标
    int ai = 0; //nums1的遍历下标
    vector<int> copyArr;
    for (int i = 0; i < m; i++) {
        copyArr.push_back(nums1[i]); // 把num1里的元素备份
    }
    while (true) {
        if (li >= m) {//copyArr使用完毕了，则直接把nums2剩下的元素覆盖追加到nums1尾部
            for (int i = ri; i < n; i++) {
                nums1[ai++] = nums2[i];
            }
            break;
        } else if (ri >= n) {//nums2使用完毕了，则直接把copyArr剩下的元素覆盖追加到nums1尾部
            for (int i = li; i < m; i++) {
                nums1[ai++] = copyArr[i];
            }
            break;
        }
        // 一个个填充num1里的位置
        if (copyArr[li] > nums2[ri]) {
            nums1[ai++] = nums2[ri++];
        } else {
            nums1[ai++] = copyArr[li++];
        }
    }
}

int main(int argc, const char * argv[]) {
   
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    
    mergeSort(nums1, 3, nums2, 3);
    for (int num : nums1) {
        cout << num << "->";
    }
    cout << endl;
    
    return 0;
}
