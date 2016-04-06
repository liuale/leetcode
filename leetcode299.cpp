//
//  main.cpp
//  leetcode299
//
//  Created by 刘晓 on 16/4/6.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int num[10] = {0};
        //该部分为secret相关的
        for (int i=0; i<secret.size(); ++i) {
            if (secret[i]==guess[i]) {
                ++bulls;
            }
            else{
                num[secret[i]-'0']++;
            }
        }
        //该部分为guess相关的
        for (int i=0; i<guess.size(); ++i) {
            if (secret[i]!=guess[i] && num[guess[i]-'0']>0) {
                ++cows;
                num[guess[i]-'0']--;
            }
        }
        char buff[20];
        sprintf(buff, "%dA%dB",bulls,cows);
        return buff;
    }

};

int main(int argc, const char * argv[]) {
    // insert code here...
    string str1 = "1123";
    string str2 = "0111";
    Solution test;
    cout<<test.getHint(str1, str2)<<endl;
    std::cout << "All is done!\n";
    return 0;
}
