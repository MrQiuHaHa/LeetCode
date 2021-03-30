//
//  main.cpp
//  3. 无重复字符的最长子串
//
//  Created by 邱俊荣 on 2021/3/30.
//
/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 
 示例 1:
 输入: s = "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 
 示例 2:
 输入: s = "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 
 示例 3:
 输入: s = "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 
 示例 4:
 输入: s = ""
 输出: 0

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    
    if (s.length() == 0) return 0;
    
    unordered_map<char, int> map;
    map[s[0]] = 0;
    // 以i - 1位置字符结尾的最长不重复字符串的开始索引（最左索引）
    int li = 0;
    int maxLen = 1;
    for (int i = 1; i < s.length(); i++) {
        // i位置字符上一次出现的位置
        auto iterator = map.find(s[i]);
        if (iterator != map.end()) {
            int pi = iterator->second;
            if (li <= pi) {
                li = pi + 1;
            }
        }
        // 存储这个字符出现的位置
        map[s[i]] = i;
        // 求出最长不重复子串的长度
        maxLen = max(maxLen, i - li + 1);
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    cout << lengthOfLongestSubstring("abba") << endl;
    
    return 0;
}
