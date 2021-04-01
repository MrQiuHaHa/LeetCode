//
//  main.cpp
//  9. 字符串轮转
//
//  Created by 邱俊荣 on 2021/4/1.
//
/*
 字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

 示例1:
  输入：s1 = "waterbottle", s2 = "erbottlewat"
  输出：True
 
 示例2:
  输入：s1 = "aa", s2 = "aba"
  输出：False
 
 提示：
 字符串长度在[0, 100000]范围内。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/string-rotation-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>

using namespace std;

// 判断num字符串是否包含target子串的实现
bool containStr(string &num,string &target){
    //设定两个标记,t用来标记字符串num当前的位置，i标记字符串target当前的位置
    int t = 0, i = 0;
    //遍历整个字符串
    while (t < num.length()) {
        //若当前字符串中的字符与目标字符串中的字符相等则检验下一个
        if (target[i] == num[t]) {
            i++;
            if (i == target.length()) return true; //当检验全部验证通过时则返回true
        } else if (target[i] != num[t]) { //若当前字符串中的字符与目标字符不相等时则将t向后移而i则置为0
            i = 0;
        }
        t++;
    }
    ///当检验完后并未找到目标字符串则返回false
    return false;
}


bool isFlipedString(string s1, string s2) {
    
    if (s1.length() == 0 || s2.length() == 0) return false;
    return containStr(s1.append(s1), s2);
}

int main(int argc, const char * argv[]) {
    
    cout << isFlipedString("waterbottle", "erbottlewat") << endl;
    
    return 0;
}
