/* ************************************************************************
> File Name:     二叉树的最大深度.cpp
> Author:        wang
> Created Time:  Fri Oct 29 17:11:35 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <queue>

//递归 （后序）
class Solution01{
public:
    int getDepth(TreeNode* node){
        if(node == NULL) return 0;  //空节点的高度为0
        int lchildDepth = getDepth(node->lchild);
        int rchildDepth = getDepth(node->rchild);
        int depth = 1 + max(lchildDepth, rchildDepth);
        return depth;
    }
};
//递归 （前序）
class Solution02{
public:
    //定义一个全局的result，分多条子树往下搜索，节点有效则depth+1并传入下一层，
    //depth比result大则更新result
    int result;
    void getDepth(TreeNode* node, int depth){
        result = depth > result ? depth : result;   //中
        if(node->lchild == NULL && node->rchild == NULL) return;

        if(node->lchild){   //左
            getDepth(node->lchild, depth + 1);
        }
        if(node->rchild){   //右
            getDepth(node->rchild, depth + 1);
        }
        return;
    }
    int maxdepth(TreeNode* root){
        result = 0;
        if(root == NULL) return result;
        getDepth(root, 1);
        return result;
    }
};
//迭代法 层序遍历，层数即为最大深度
class Solution03 {
public:
    int maxdepth(TreeNode* root){
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size(); //当前层的节点数
            depth++;             //每开始新的一层 depth加一
            //一个for循环遍历完一层的节点
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->lchild) que.push(node->lchild);    //压入下一层的节点
                if(node->rchild) que.push(node->rchild);    //压入下一层的节点
            }
        }
        return depth;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    Solution03 s3;
    cout << s1.getDepth(root) << endl;
    cout << s2.maxdepth(root) << endl;
    cout << s3.maxdepth(root) << endl;
}
int main(){
    test01();
    return 0;
}
