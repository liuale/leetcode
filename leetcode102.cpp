//
//  main.cpp
//  leetcode102
//
//  Created by 刘晓 on 16/4/5.
//  Copyright © 2016年 刘晓. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


  //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector< vector<int> > res;
    void Tralevel(TreeNode* root, int level){
        if (root==NULL) {
            return ;
        }
        if(level==res.size()){
            vector<int> v;
            res.push_back(v);
        }
        res[level].push_back(root->val);
        Tralevel(root->left, level+1);
        Tralevel(root->right, level+1);
    }
    
    vector< vector<int> > levelOrder(TreeNode* root) {
        Tralevel(root, 0);
        vector< vector<int> > ret(res.begin(), res.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
