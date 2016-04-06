//
//  main.cpp
//  leetcode205
//
//  Created by 刘晓 on 16/4/6.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = (int)s.size();
        int n = (int)t.size();
        if(n!=m) return false;
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i=0; i<m; ++i) {
            char schar = s[i];
            char tchar = t[i];
            //s中同一个字符不能对应t中的不同字符
            if (m1.find(schar)!=m1.end() && m1[schar]!= tchar) {
                return false;
            }
            //s中的不同字符不能对应t中同一个字符
            if (m2.find(tchar)!=m2.end() && m2[tchar]!= schar) {
                return false;
            }
            m1[schar] = tchar;
            m2[tchar] = schar;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string str1 = "hello";
    string str2 = "ikoot";
    Solution test;
    cout<<test.isIsomorphic(str1, str2)<<endl;
    std::cout << "All is done!\n";
    return 0;
}
