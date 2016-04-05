//
//  main.cpp
//  leetcode111
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>


  //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(l==0||r==0){
            return r+l+1;
        }
        else return (r<l?r:l)+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
