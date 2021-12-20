/* ************************************************************************
> File Name:     二叉树的最近公共祖先.cpp
> Author:        wang
> Created Time:  Fri Nov 12 09:30:33 2021
> Description:   
 ************************************************************************/
#include "AVL.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == q || root == p || root == NULL) return root;
        TreeNode* lchild = lowestCommonAncestor(root->lchild, p, q);
        TreeNode* rchild = lowestCommonAncestor(root->rchild, p, q);
        if(lchild != NULL && rchild != NULL) return root;

        if(lchild == NULL && rchild != NULL) return rchild;
        else if(lchild != NULL && rchild == NULL) return lchild;
        else{   //(lchild == NULL && rchild == NULL)
            return NULL;
        }
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution s;
    TreeNode* p = root->rchild->rchild;
    TreeNode* q = root->lchild->lchild;
    cout << (s.lowestCommonAncestor(root, p, q))->data << endl;
}
int main(){
    test01();
    return 0;
}
