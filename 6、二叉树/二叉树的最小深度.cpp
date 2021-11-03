/* ************************************************************************
> File Name:     二叉树的最小深度.cpp
> Author:        wang
> Created Time:  Fri Oct 29 20:27:32 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <queue>

//递归（后序）
class Solution01{
public:
    int getDepth(TreeNode* node){
        if(node == NULL) return 0;
        int leftDepth = getDepth(node->lchild);     //左
        int rightDepth = getDepth(node->rchild);    //右
                                                    //中
        //当一个左子树为空，右不为空，这时并不是最低点！！！！！！！
        if(node->lchild == NULL && node->rchild != NULL){
            return 1 + rightDepth;
        }
        //当一个右子树为空，左不为空，这时并不是最低点
        if(node->lchild != NULL && node->rchild == NULL){
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }
    int minDepth(TreeNode* root){
        return getDepth(root);
    }
};
//迭代（层序）
class Solution02{
public:
    int minDepth(TreeNode* root){
        if(root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            depth++; //记录最小深度
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(!node->lchild && !node->rchild){ //遇到叶子节点，说明已经找到最小深度
                    return depth;
                }
                if(node->lchild) que.push(node->lchild);
                if(node->rchild) que.push(node->rchild);
            }
        }
        return depth;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    cout << "最小深度为：" << s1.minDepth(root) << endl;
    cout << "最小深度为：" << s2.minDepth(root) << endl;
}
int main(){
    test01();
    return 0;
}
