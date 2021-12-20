/* ************************************************************************
> File Name:     二叉搜索树中的搜索.cpp
> Author:        wang
> Created Time:  Mon Nov  8 15:33:10 2021
> Description:   
 ************************************************************************/
#include "AVL.h"

//递归
class Solution01{
public:
    TreeNode* searchBST(TreeNode* root, int val){
        if(root == NULL || root->data == val) return root;
        if(root->data > val) return searchBST(root->lchild, val);
        if(root->data < val) return searchBST(root->rchild, val);
        return NULL;
    }
};
//迭代
class Solution02{
public:
    TreeNode* searchBST(TreeNode* root, int val){
        while(root != NULL){
            if(root->data > val) root = root->lchild;
            else if(root->data < val) root = root->rchild;
            else return root;
        }
        return NULL;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    cout << (s1.searchBST(root, 5))->data << endl;
}
int main(){
    test01();
    return 0;
}
