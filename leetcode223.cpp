//
//  main.cpp
//  leetcode223
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int val = (C-A)*(D-B) + (G-E)*(H-F);
        if (E > C || G < A || F > D || H < B) {
            return val;
        }
        val -= (min(C,G) - max(A,E))*(min(D,H) - max(B,F));
        return val;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "All is done!\n";
    return 0;
}
