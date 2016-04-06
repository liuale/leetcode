//
//  main.cpp
//  leetcode204
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//超时
//class Solution {
//public:
//    vector<int> prime_vec;
//    bool isPrime(int n){
//        if (n<2) {
//            return false;
//        }
//        if (n==2) {
//            return true;
//        }
//        if (n%2==0) {
//            return false;
//        }
//        int sq = sqrt(n);
//        int len = (int)prime_vec.size();
//        for (int index = 0; index<len; ++index) {
//            int tmp = prime_vec[index];
//            if (index>sq) {
//                break;
//            }
//            if (n%tmp==0) {
//                return false;
//            }
//        }
//        return true;
//    }
//    int countPrimes(int n) {
//        int count=0;
//        for (int i=1; i<n; ++i) {
//            if (isPrime(i)) {
//                ++count;
//                prime_vec.push_back(i);
//            }
//        }
//        return count;
//    }
//};
//Solution2
//不超时
class Solution2{
public:
    int countPrimes(int n){
        vector<bool> prime(n, true);
        prime[0]=false;
        prime[1] = false;
        for (int i=0; i<sqrt(n); ++i) {
            if (prime[i]) {
                for (int j=i*i; j<n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        return (int)count(prime.begin(), prime.end(), true);
        
    }

};

int main(int argc, const char * argv[]) {
    Solution2 test;
    cout<<test.countPrimes(1500000)<<endl;
    std::cout << "All is done!\n";
    return 0;
}
