//
//  main.cpp
//  151. 翻转字符串里的单词
//
//  Created by 邱俊荣 on 2021/3/29.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0) {
            return "";
        }
        stack<char> sta;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && (sta.empty() || sta.top() == ' ')) {
                continue;
            }
            sta.push(s[i]);
        }
        
        string ans;
        while (!sta.empty()) {
            ans += sta.top();
            sta.pop();
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    shared_ptr<Solution> solu(new Solution());
    
    cout << solu->reverseWords("a good   example") << endl;
    
    return 0;
}
