//
//  main.cpp
//  leetcode190
//
//  Created by 刘晓 on 16/4/6.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for(int i=0;i<32;++i){
            int tmp=n&0x01;
            n=n>>1;
            result=(result<<1)|tmp;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution test;
    uint32_t a = 43261596;
    cout<<test.reverseBits(a)<<endl;
    std::cout << "All is done!\n";
    return 0;
}
