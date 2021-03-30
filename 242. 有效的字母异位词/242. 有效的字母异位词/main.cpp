//
//  main.cpp
//  242. 有效的字母异位词
//
//  Created by 邱俊荣 on 2021/3/30.
//
/*
 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

 示例 1:

 输入: s = "anagram", t = "nagaram"
 输出: true
 示例 2:

 输入: s = "rat", t = "car"
 输出: false
 说明:
 你可以假设字符串只包含小写字母。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-anagram
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    
    if (s.length() != t.length()) return false;
    
    unordered_map<char, int> table;
    
    //哈希表的value记录的是某个字母出现的次数
    for (char letter : s) {
        auto operate = table.find(letter);
        if (operate == table.end()) {
            table[letter] = 1;
        } else {
            table[letter] = operate->second+1;
        }
    }
    for (char letter : t) {
        auto operate = table.find(letter);
        if (operate == table.end()) {
            return false;//找不到肯定是false
        } else {
            if (operate->second > 1) {
                table[letter] = operate->second - 1;
            } else {
                table.erase(letter);
            }
        }
    }
    
    return table.size() == 0;
}

int main(int argc, const char * argv[]) {
    
    cout << isAnagram("anagram", "nagaram") << endl;
    
    return 0;
}
