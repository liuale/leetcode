//
//  main.cpp
//  leetcode155
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//
//新建一个stack来存放数据，栈顶为最小值

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> sta;
    stack<int> min;
    void push(int x) {
        sta.push(x);
        if(min.empty()||x<=min.top()){
            min.push(x);
        }
    }
    
    void pop() {
        if (sta.top()==min.top()) {
            sta.pop();
            min.pop();
        }
        else
            sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return min.top();
    }
};

int main(int argc, const char * argv[]) {
    MinStack test;
    test.push(0);
    test.push(1);
    test.push(0);
    cout<<test.getMin()<<endl;
    test.pop();
    cout<<test.getMin()<<endl;
    // insert code here...
    std::cout << "All is done!\n";
    return 0;
}
