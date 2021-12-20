/* ************************************************************************
> File Name:     合并二叉树.cpp
> Author:        wang
> Created Time:  Mon Nov  8 10:23:41 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <queue>

//递归 前序遍历
class Solution01{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL) return t2;   //  如果t1为空，合并之后就是t2
        if(t2 == NULL) return t1;   //  入托t2为空，合并之后就是t1
        //修改t1的数值和结构    
        t1->data += t2->data;       //中
        t1->lchild = mergeTrees(t1->lchild, t2->lchild);    //左
        t1->rchild = mergeTrees(t1->rchild, t2->rchild);    //右
        return t1;
    }
};

//迭代层序遍历
class Solution02{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        while(!que.empty()){
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            //此时两个节点一定不为空
            node1->data += node2->data;

            //如果两棵树左节点都不为空，加入队列
            if(node1->lchild != NULL && node2->lchild != NULL){
                que.push(node1->lchild);
                que.push(node2->lchild);
            }
            //如果两棵树右节点都不为空，加入队列
            if(node1->rchild != NULL && node2->rchild != NULL){
                que.push(node1->rchild);
                que.push(node2->rchild);
            }
            //当t1左节点为空， t2左节点不为空，赋值到t1
            if(node1->lchild == NULL && node2->lchild != NULL){
                node1->lchild = node2->lchild;
            }
            //当t1右节点为空，t2右节点不为空，赋值到t1
            if(node1->rchild == NULL && node2 != NULL){
                node1->rchild = node2->rchild;
            }
        }
        return t1;
    }
};

void test01(){
    TreeNode* t1 = CreateBinaryTree();
    TreeNode* t2 = CreateBinaryTree();
    Solution01 s1;
    t1 = s1.mergeTrees(t1, t2);
    Recursion(t1);
    cout << endl;
}
int main(){
    test01();
    return 0;
}
