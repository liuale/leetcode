//
//  main.cpp
//  303
//
//  Created by 刘晓 on 16/4/6.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums):array(nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum+=nums[i];
            sumAarray.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return sumAarray[j]-sumAarray[i]+array[i];
    }
    vector<int> sumAarray;
    vector<int> &array;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a;
    a.push_back(5);
    a.push_back(-7);
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    NumArray test(a);
    cout<<test.sumRange(2,4)<<endl;
    cout << "Hello, World!\n";
    return 0;
}
