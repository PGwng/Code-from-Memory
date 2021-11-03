/* ************************************************************************
> File Name:     对称二叉树.cpp
> Author:        wang
> Created Time:  Thu Oct 28 19:15:24 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <queue>
#include <stack>
//递归 后序
class Solution01 {
public:
    bool compare(TreeNode* lchild, TreeNode* rchild){
        //首先排除空节点的情况
        if(lchild == NULL && rchild != NULL) return false;
        else if(lchild != NULL && rchild == NULL) return false;
        else if(lchild == NULL && rchild == NULL) return true;
        //排除了空节点，再排除数值不相同的情况
        else if(lchild->data != rchild->data) return false;

        //此时就是：左右子树根节点都不为空，且数值相同的情况（只是根节点数值相等，还要其下的子树对称才算这两个子树对称）
        //此时才做递归，做下一层的判断
        //这里是判断子树对称性才算完成该节点的处理。
        //左子树的左子树和右子树的右子树对称
        bool outside = compare(lchild->lchild, rchild->rchild); //左子树：左    右子树：右  外侧
        //左子树的右子树和右子树的左子树对称
        bool inside = compare(lchild->rchild, rchild->lchild);  //左子树：右    右子树：左  内侧
        //因为左子树和右子树的内外侧对称，且左子树、右子树根节点相等，所以左子树和右子树对称。
        bool isSame = outside && inside;                        //左子树：中    右子树：中
        return isSame;
    }
    bool isSymmetric(TreeNode* root){
        if(root == NULL) return true;
        return compare(root->lchild, root->rchild);
    }
};

//迭代法 使用队列
class Solution02 {
public:
    bool isSymmetric(TreeNode* root){
        if(root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->lchild);     //左子树根节点加入队列
        que.push(root->rchild);     //右子树根节点加入队列
        while(!que.empty()){        //判断两个子树是否相互翻转
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if(!leftNode && !rightNode){    //左节点和右节点都为空，相等（对称）
                continue;
            }
            //左右一个节点不为空，或者都不为空但数值不相等，返回false
            if(!leftNode || !rightNode || (leftNode->data != rightNode->data)){
                return false;
            }
            que.push(leftNode->lchild);
            que.push(rightNode->rchild);
            que.push(leftNode->rchild);
            que.push(rightNode->lchild);
        }
        return true;    //没有在while里提前返回false结束程序，说明队列里每次弹出的两个节点是相同的，返回true
    }
};

//迭代法 使用栈
class Solution03 {
public:
    bool isSymmetric(TreeNode* root){
        if(root == NULL) return true;
        stack<TreeNode*> st;
        st.push(root->lchild);     //左子树根节点加入栈
        st.push(root->rchild);     //右子树根节点加入栈
        while(!st.empty()){        //判断两个子树是否相互翻转
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* rightNode = st.top(); st.pop();
            if(!leftNode && !rightNode){    //左节点和右节点都为空，相等（对称）
                continue;
            }
            //左右一个节点不为空，或者都不为空但数值不相等，返回false
            if(!leftNode || !rightNode || (leftNode->data != rightNode->data)){
                return false;
            }
            st.push(leftNode->lchild);
            st.push(rightNode->rchild);
            st.push(leftNode->rchild);
            st.push(rightNode->lchild);
        }
        return true;    //没有在while里提前返回false结束程序，说明队列里每次弹出的两个节点是相同的，返回true
    }
};

void test01(){
    TreeNode node1;
    TreeNode node2;
    TreeNode node3;
    node1 = { 1, 0, &node2, &node3 };
    node2 = { 2, 0, NULL, NULL };
    node3 = { 2, 0, NULL, NULL };
    Solution01 s1;
    Solution02 s2;
    Solution03 s3;
    //cout << s1.isSymmetric(&node1) << endl;
    cout << s3.isSymmetric(&node1) << endl;
}
int main(){
    test01();
    return 0;
}
