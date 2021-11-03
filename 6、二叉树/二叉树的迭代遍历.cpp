/* ************************************************************************
> File Name:     二叉树的迭代遍历.cpp
> Author:        wang
> Created Time:  Wed Oct 27 10:37:32 2021
> Description:   
 ************************************************************************/
#include <vector>
#include <stack>
#include <algorithm>
#include "AVL.h"

using namespace std;

class Solution01 {      //先序
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;     //存放遍历结果数据
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();              //取根节点
            st.pop();                               //弹出根节点后，先压入右节点，再压入左节点
            result.push_back(node->data);           //保证弹出顺序为先根再左再右
            if(node->rchild) st.push(node->rchild); //先右再左，弹出是才会是先左再右，空节点不入栈
            if(node->lchild) st.push(node->lchild); 
        }
        return result;
    }
};

class Solution02 {      //中序
public:
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* cur = root;
        while(cur != NULL || !st.empty()){
            if(cur != NULL){    //指针访问节点，访问到最底层
                st.push(cur);   //将访问的节点入栈
                cur = cur->lchild;  //左
            }
            else{
                cur = st.top(); 
                st.pop();
                result.push_back(cur->data);    //中
                cur = cur->rchild;              //右
            }
        }
    return result;
    }
};

class Solution03 {      //后序
public:
    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();                               //弹出根节点后，先压入左节点，再压入右节点
            result.push_back(node->data);           //保证弹出顺序为先根再右再左，再做反转即为后序
            if(node->lchild) st.push(node->lchild);
            if(node->rchild) st.push(node->rchild);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    Solution03 s3;
    vector<int> result;
    //result = s1.preorderTraversal(root);
    //result = s2.inorderTraversal(root);
    result = s3.postorderTraversal(root);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
