/* ************************************************************************
> File Name:     二叉树的递归遍历.cpp
> Author:        wang
> Created Time:  Tue Oct 26 21:29:42 2021
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include "AVL.h"

using namespace std;

// struct TreeNode{
    // int val;
    // TreeNode* lchild;
    // TreeNode* rchild;
    // TreeNode(int x) : val(x), lchild(NULL), rchild(NULL) { }
// };

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur == NULL) return;
        //vec.push_back(cur->data);    //先根节点
        traversal(cur->lchild, vec);    //再左子树
        vec.push_back(cur->data);    //先根节点
        traversal(cur->rchild, vec);    //再右子树
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution s;
    vector<int> result;
    result = s.preorderTraversal(root);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
