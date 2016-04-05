//
//  main.cpp
//  leetcode278
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//

//用二分法，如果你把ver = (low + high)/2; 那就会出现超时错误，因为直接相加可能溢出，仅此一点

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int ver = 0;
        while(low<high){
            ver = low+(high-low)/2;
            if(isBadVersion(ver)){
                high = ver;
            }
            else
                low = ver+1;
        }
        return low;
    }
};