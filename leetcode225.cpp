//
//  main.cpp
//  leetcode225
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

class Stack{
public:
    queue<int> queue1;
    queue<int> queue2;
    // Push element x onto stack.
    void push(int x) {
        if (queue1.empty()) {
            queue1.push(x);
            while(!queue2.empty()){
                int tmp = queue2.front();
                queue2.pop();
                queue1.push(tmp);
            }
        }
        else{
            queue2.push(x);
            while(!queue1.empty()){
                int tmp = queue1.front();
                queue1.pop();
                queue2.push(tmp);
            }
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if(!queue1.empty()){
            queue1.pop();
        }
        if (!queue2.empty()) {
            queue2.pop();
        }
    }
    
    // Get the top element.
    int top() {
        if (!queue1.empty()) {
            return queue1.front();
        }
        else if (!queue2.empty()) {
            return queue2.front();
        }
        else return 0;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return queue1.empty()&&queue2.empty();
    }

};

int main(int argc, const char * argv[]) {
    // insert code here...
    Stack ret;
    ret.push(1);
    ret.push(2);
    ret.push(3);
    ret.pop();
    ret.push(4);
    cout<<"Top of the stack is "<<ret.top()<<endl;
    while(!ret.empty()){
        int tmp = ret.top();
        ret.pop();
        cout<<tmp<<" ";
    }
    cout<<endl;
    cout << "All is done!\n";
    return 0;
}
