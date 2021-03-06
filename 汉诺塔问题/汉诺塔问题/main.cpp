//
//  main.cpp
//  汉诺塔问题
//
//  Created by 邱俊荣 on 2021/3/18.
//

/*
 在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
 (1) 每次只能移动一个盘子;
 (2) 盘子只能从柱子顶端滑出移到下一根柱子;
 (3) 盘子只能叠在比它大的盘子上。

 请编写程序，用栈将所有盘子从第一根柱子移到最后一根柱子。
 你需要原地修改栈。
 示例1:
  输入：A = [2, 1, 0], B = [], C = []
  输出：C = [2, 1, 0]
 示例2:
  输入：A = [1, 0], B = [], C = []
  输出：C = [1, 0]
 提示:
 A中盘子的数目不大于14个。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/hanota-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

void move(int n, vector<int>& A, vector<int>& B, vector<int>& C){
    if (n == 1){
        C.push_back(A.back());
        A.pop_back();
        return;
    }

    move(n-1, A, C, B);    // 将A上面n-1个通过C移到B
    C.push_back(A.back());  // 将A最后一个移到C
    A.pop_back();          // 这时，A空了
    move(n-1, B, A, C);     // 将B上面n-1个通过空的A移到C
}

void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size();
    move(n, A, B, C);
}



int main(int argc, const char * argv[]) {
    
    vector<int> A = {5, 4, 3, 2, 1, 0};
    vector<int> B = {};
    vector<int> C = {};
    
    hanota(A, B, C);
    
    for (int num : C) {
        cout << num << "->";
    }
    
    cout << endl;
    
    return 0;
}
