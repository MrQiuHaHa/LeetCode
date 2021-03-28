//
//  main.cpp
//  739. 每日温度
//
//  Created by 邱俊荣 on 2021/3/28.
//
/*
 请根据每日气温列表，重新生成一个列表。对应位置的输出为：
 要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 例如:
    给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
    你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/daily-temperatures
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    int n = (int)T.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && T[i] > T[s.top()]) {
            int previousIndex = s.top();
            ans[previousIndex] = i - previousIndex;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    vector<int> data = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> arr = dailyTemperatures(data);
    for (int element : arr) {
        cout << element << "，";
    }
    cout << endl;
    return 0;
}
