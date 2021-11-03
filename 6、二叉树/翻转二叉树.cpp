/* ************************************************************************
> File Name:     翻转二叉树.cpp
> Author:        wang
> Created Time:  Thu Oct 28 11:05:01 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>
#include <stack>
#include <queue>

//前序递归交换翻转
class Solution01{
public:
    TreeNode* invertTree(TreeNode* root){
        if(root == NULL) return root;
        swap(root->lchild, root->rchild);   //中
        invertTree(root->lchild);           //左
        invertTree(root->rchild);           //右
        return root;
    }
};
//前序迭代交换翻转
class Solution02 {
public:
    TreeNode* invertTree(TreeNode* root){
        if(root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            swap(node->lchild, node->rchild);
            if(node->rchild) st.push(node->rchild);
            if(node->lchild) st.push(node->lchild);
        }
        return root;
    }
};
//前序迭代统一写法 交换翻转
class Solution03 {
public:
    TreeNode* invertTree(TreeNode* root){
        stack<TreeNode*> st;
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();
                if(node->rchild) st.push(node->rchild); //右
                if(node->lchild) st.push(node->lchild); //左
                st.push(node);                          //中
                st.push(NULL);                          //要处理节点的标志
            }
            else{
                st.pop();   //弹出空节点
                node = st.top();
                st.pop();                               //取出要处理的节点
                swap(node->lchild, node->rchild);       //节点处理逻辑
            }
        }
        return root;
    }
};
//广度优先遍历，层序遍历
class Solution04 {
public:
    TreeNode* invertTree(TreeNode* root){
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();  //取出每一层的节点数
            for(int i = 0; i < size; i++){//for循环结束时，将当前层的节点全部取出，进行处理，
                //并将下一层的节点全部压入队列
                TreeNode* node = que.front();       //取出节点
                que.pop();                          
                swap(node->lchild, node->rchild);   //节点处理
                if(node->lchild) que.push(node->lchild);
                if(node->rchild) que.push(node->rchild);
            }
        }
        return root;
    }
};

//前序递归遍历
void preorderTraversal(TreeNode* root, vector<int>& result){
    if(root == NULL) return;
    result.push_back(root->data);
    preorderTraversal(root->lchild, result);
    preorderTraversal(root->rchild, result);
}

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    Solution03 s3;
    Solution04 s4;
    //root = s1.invertTree(root);
    //root = s2.invertTree(root);
    //root = s3.invertTree(root);
    root = s4.invertTree(root);
    vector<int> result;
    preorderTraversal(root, result);
    for(auto it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
