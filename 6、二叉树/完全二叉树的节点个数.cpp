/* ************************************************************************
> File Name:     完全二叉树的节点个数.cpp
> Author:        wang
> Created Time:  Fri Oct 29 21:22:53 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <queue>

//递归（后序） 普通二叉树
class Solution01{
private:
    int getNodesNum(TreeNode* cur){
        if(cur == 0) return 0;
        int leftNum = getNodesNum(cur->lchild); //左
        int righNum = getNodesNum(cur->rchild); //右
        int nodeNum = leftNum + righNum + 1;    //中
        return nodeNum;
    }
public:
    int countNodes(TreeNode* root){
        return getNodesNum(root);
    }
};
//迭代（层序） 普通二叉树
class Solution02{
public:
    int countNodes(TreeNode* root){
        queue<TreeNode*> que;
        int result;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                result++;   //记录节点数量
                if(node->lchild) que.push(node->lchild);
                if(node->rchild) que.push(node->rchild);
            }
        }
        return result;
    }
};

//递归求完全二叉树的节点上，满二叉树的节点数为2^（树的深度）-1
//时间复杂度O(logn * logn) 空间复杂度O(logn)
class Solution03{
public:
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;
        TreeNode* lchild = root->lchild;
        TreeNode* rchild = root->rchild;
        int leftHeight = 0, rightHeight = 0;    //这里初始为0是为了下面求指数方便
        while(lchild){      //求左子树深度
            lchild = lchild->lchild;
            leftHeight++;
        }
        while(rchild){      //求右子树深度
            rchild = rchild->rchild;
            rightHeight++;
        }
        if(leftHeight == rightHeight) { //满二叉树
            return (2 << leftHeight) - 1; //注意( 2<<1 )相当于2^2，所以leftHeight初始化为0
        }
        return countNodes(root->lchild) + countNodes(root->rchild) + 1;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    cout << "节点数为：" << s1.countNodes(root) << endl;
    cout << "节点数为：" << s2.countNodes(root) << endl;
}
int main(){
    test01();
    return 0;
}
