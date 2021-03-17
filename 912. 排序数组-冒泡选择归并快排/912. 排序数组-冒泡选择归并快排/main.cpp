//
//  main.cpp
//  排序
//
//  Created by 邱俊荣 on 2021/3/16.
//

/*
 给你一个整数数组 nums，请你将该数组升序排列。
 输入：nums = [5,2,3,1]
 输出：[1,2,3,5]
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 冒泡排序1 平均时间复杂度O(n^2))
void bubbleSort1(vector<int>& nums) {
    for (int end = nums.size()-1; end > 0; end--) {
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin-1]) {
                int tmp = nums[begin];
                nums[begin] = nums[begin-1];
                nums[begin-1] = tmp;
            }
        }
    }
}
// 冒泡排序2--优化--排除本来就是有序的数组
void bubbleSort2(vector<int>& nums) {
    bool sorted = true;
    for (int end = nums.size()-1; end > 0; end--) {
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin-1]) {
                int tmp = nums[begin];
                nums[begin] = nums[begin-1];
                nums[begin-1] = tmp;
                sorted = false;
            }
        }
        if (sorted) {
            break;
        }
    }
}
// 冒泡排序3--优化--记录交换的最后一次位置，排除掉末尾已经排序的地方
void bubbleSort3(vector<int>& nums) {
    for (int end = nums.size()-1; end > 0; end--) {
        int sortedIndex = 1;
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin-1]) {
                int tmp = nums[begin];
                nums[begin] = nums[begin-1];
                nums[begin-1] = tmp;
                sortedIndex = begin;
            }
        }
        end = sortedIndex;
    }
}
// 选择排序--对比冒泡法减少了交换次数，但是没法独立优化。可以配合使用二叉堆进行优化
// 平均时间复杂度O(n^2))
void selectionSort(vector<int>& nums) {
    for (int end = nums.size()-1; end > 0; end--) {
        int maxIndex = 0;
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] > nums[maxIndex]) {
                maxIndex = begin; // 内层循环先记录最大值下标，到外层交换
            }
        }
        int tmp = nums[end];
        nums[end] = nums[maxIndex];
        nums[maxIndex] = tmp;
    }
}

// 归并排序 平均时间复杂度O(n*log(n))
class MergeSort {
    vector<int> leftArr;
    vector<int> numsArr;
public:
    
    vector<int> sortArray(vector<int>& nums) {
        numsArr = nums;
        leftArr.resize(nums.size() >> 1);
        mergeSort(0, (int)nums.size());
        return numsArr;
    }
    
    void mergeSort(int begin, int end) {
        if (end - begin < 2) { // 至少要有两个元素才可以排序
            return;
        }
        
        int mid = (begin + end) >> 1;
        mergeSort(begin, mid); // [begin, mid)
        mergeSort(mid, end);   // [mid, end)
        // 此处begin到mid以及mid到end下标应该都是有序了。且begin-mid-end在原数组中就是相邻的元素
        //接下来合并两个有序数组
        merge(begin, mid, end);
    }
    
    void merge(int begin, int mid, int end) {
        
        int li = 0, le = mid - begin; //基于左边备份出来的数组leftArr
        int ri = mid, re = end; //基于原数组右边部分
        int ai = begin; //基于原数组索引
        for (int i = 0; i < le; i++) {
            leftArr[i] = numsArr[begin+i]; // 备份出左边数组
        }
        
        while (li < le) {//leftArr用完了，直接使用右边元素覆盖剩下位置,因为右边元素本来就是在剩下位置，直接退出就行
            if (ri < re && numsArr[ri] < leftArr[li]) { // 这个判断的位置不要反过来，否则会失去排序后的稳定性
                numsArr[ai++] = numsArr[ri++];
            } else {
                numsArr[ai++] = leftArr[li++];
            }
        }
        
    }
};

// 快速排序  平均时间复杂度O(n*log(n))
class QuickSort {
    
    vector<int> numsArr;
public:
    
    vector<int> sortArray(vector<int>& nums) {
        numsArr = nums;
        quickSort(0, (int)nums.size());
        return numsArr;
    }
    // [begin, end) 左闭右开
    void quickSort(int begin, int end) {
        if (end - begin < 2) { // 至少要有两个元素才可以排序
            return;
        }
        
        int mid = pivotIndex(begin, end); // 已确定的轴点不再需要参与后面的任何事情
        quickSort(begin, mid); //[begin, mid)
        quickSort(mid+1, end); //[mid+1, end) 这里必须+1，其实是（除去mid轴点这个元素）后的两边重新递归构造轴点
    }
private:
    // 核心方法：构造出begin-end间的轴点元素的位置，
    // 备份begin位置的元素为轴点元素，小于轴点的放begin左边，大于轴点的放begin右边，全部完成最终返回轴点的位置
    int pivotIndex(int begin, int end) {
        
        // 让begin随机和begin-end的一个位置交换，随机生成轴点，避免出现轴点分割后数组两边极度不均匀
        // 交换后避免出现最坏时间复杂度O(n^2)
        int tmp = numsArr[begin];
        srand((int)time(0));
        int random = begin + int(rand()%1 *(end-begin));
        numsArr[begin] = numsArr[random];
        numsArr[random] = tmp;
        
        int pivot = numsArr[begin];//备份出轴点元素
        end--; // 先减1指向最后一个元素，[begin, end) 右边是开区间的设计
        
        // 左右循环扫描。（原地将数组以某个元素为中间切分成两边）
        while (begin < end) {
            
            while (begin < end) {
                // 从右边扫描中
                if (pivot < numsArr[end]) {
                    // 右边大于轴点元素，则直接移动end位置，无需改元素位置
                    end--;
                } else {
                    numsArr[begin++] = numsArr[end];
                    //一旦发生了交换，则改变扫描方向，当前内循环先退出
                    break;
                }
            }
            
            while (begin < end) {
                //从左边扫描中
                if (pivot > numsArr[begin]) {
                    // 左边小于轴点元素，则直接移动begin位置，无需改元素位置
                    begin++;
                } else {
                    numsArr[end--] = numsArr[begin];
                    //一旦发生了交换，则改变扫描方向，当前内循环先退出
                    break;
                }
            }
            
        }
        //最后还需要把轴点数据也更新到轴点位置（开始忘记了，坑自己）
        numsArr[begin] = pivot;
        return begin;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {10,9,8,7,5,1,1,2,0,0};
//    bubbleSort1(nums);
//    bubbleSort2(nums);
//    bubbleSort3(nums);
//    selectionSort(nums);
    
//    MergeSort solu;
//    nums = solu.sortArray(nums);
    
    QuickSort solu;
    nums = solu.sortArray(nums);
    
    for (int num : nums) {
        cout << num << "->";
    }
    
    cout << endl;
    
    return 0;
}
