//
//  main.cpp
//  257
//
//  Created by 刘晓 on 16/4/6.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        //四个情况：root为空；root不为空，左右子树为空；左子树不为空；右子树不为空
        if (root==NULL) {
            return vec;
        }
        if (root->left==NULL&&root->right==NULL) {
            char buff[124];
            sprintf(buff,"%d",root->val);
            vec.push_back(buff);
            return vec;
        }
        if (root->left) {
            vector<string> lefts = binaryTreePaths(root->left);
            for (int i=0; i<lefts.size(); ++i) {
                char *buff = new char[lefts[i].size()+56];
                sprintf(buff, "%d->%s", root->val, lefts[i].c_str());//转换为特定形式的字符串，str1.c_str()将字符串转为char*类型
                vec.push_back(buff);
                delete [] buff;//记得将new的东西delete掉，数组用的delete[]
            }
        }
        if (root->right) {
            vector<string> rights = binaryTreePaths(root->right);
            for (int i=0; i<rights.size(); ++i) {
                char *buff = new char[rights[i].size()+56];
                sprintf(buff, "%d->%s",root->val,rights[i].c_str());
                vec.push_back(buff);
                delete [] buff;
            }
        }
        return vec;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
