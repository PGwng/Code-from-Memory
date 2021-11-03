/* ************************************************************************
> File Name:     平衡二叉树.cpp
> Author:        wang
> Created Time:  Sat Oct 30 19:48:13 2021
> Description:   
 ************************************************************************/
#include "AVL.h"

class Solution {
public:
    //返回以该节点为根节点的二叉树的高度，如果不是平衡二叉树了则返回-1
    int getDepth(TreeNode* node){
        if(node == NULL) return 0;
        int leftDepth = getDepth(node->lchild); //左
        if(leftDepth == -1) return -1;
        int rightDepth = getDepth(node->rchild); //右
        if(rightDepth == -1) return -1;

        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth); //中
    }
    bool isBalanced(TreeNode* root){
        return getDepth(root) == -1 ? false : true;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution s;
    cout << s.isBalanced(root) << endl;
}
int main(){
    test01();
    return 0;
}
