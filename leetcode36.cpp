//
//  main.cpp
//  leetcode36
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

//依次检查每行，每列，每个子九宫格是否出现重复元素，如果出现返回false，否则返回true.
//
//难点在于表示第i个九宫格每个格点的坐标。
//
//观察行号规律：
//
//第0个九宫格：000111222; 第1个九宫格：000111222; 第2个九宫格：000111222;
//
//第3个九宫格：333444555; 第4个九宫格：333444555; 第5个九宫格：333444555;
//
//第6个九宫格：666777888; 第7个九宫格：666777888; 第8个九宫格：666777888;
//
//可见对于每三个九宫格行号增3；对于单个九宫格，每三个格点行号增1。
//
//因此第i个九宫格的第j个格点的行号可表示为i/3*3+j/3
//
//
//
//观察列号规律：
//
//第0个九宫格：012012012; 第1个九宫格：345345345; 第2个九宫格：678678678;
//
//第3个九宫格：012012012; 第4个九宫格：345345345; 第5个九宫格：678678678;
//
//第6个九宫格：012012012; 第7个九宫格：345345345; 第8个九宫格：678678678;
//
//可见对于下个九宫格列号增3，循环周期为3；对于单个九宫格，每个格点行号增1，周期也为3。
//
//周期的数学表示就是取模运算mod。
//
//因此第i个九宫格的第j个格点的列号可表示为i%3*3+j%3

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            unordered_map<char,bool> m1;
            unordered_map<char,bool> m2;
            unordered_map<char, bool> m3;
            for (int j=0; j<9; ++j) {
                if (board[i][j]!='.') {
                    if (m1[board[i][j]]==true) {
                        return false;
                    }
                    m1[board[i][j]]=true;
                }
                if (board[j][i]!='.') {
                    if (m2[board[j][i]]==true) {
                        return false;
                    }
                    m2[board[j][i]]=true;
                }
                if (board[i/3*3+j/3][i%3*3+j%3]!='.') {
                    if (m3[board[i/3*3+j/3][i%3*3+j%3]]==true) {
                        return false;
                    }
                    m3[board[i/3*3+j/3][i%3*3+j%3]]=true;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
