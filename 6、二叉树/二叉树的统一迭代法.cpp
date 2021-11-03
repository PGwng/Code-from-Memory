/* ************************************************************************
> File Name:     二叉树的统一迭代法.cpp
> Author:        wang
> Created Time:  Wed Oct 27 21:06:19 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>
#include <stack>
//中序
class Solution01{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;     //存放遍历结果
        stack<TreeNode*> st;    //按所需顺序逆序压入栈后再取出
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();      //将该节点弹出，避免重复操作，下面再将右中左节点压入栈中
                if(node->rchild) st.push(node->rchild); //将右节点压入栈中（空节点不入栈）
                st.push(node);  //中节点入栈
                st.push(NULL);  //中节点访问过，但未处理，加入空节点作为标记，如果下一个左节点为叶子节点（不会成为
                //新的中节点），这里标记的要处理的节点是指 弹出左叶子节点后的要处理中节点
                if(node->lchild) st.push(node->lchild); //将左节点压入栈中
            }
            else{       //只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();   //将空节点弹出
                node = st.top();    //取出空节点后面的元素
                st.pop();           //弹出该元素
                result.push_back(node->data);   //将该元素放入结果集
            }
        }
        return result;
    }
};
//前序
class Solution02{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;     //存放遍历结果
        stack<TreeNode*> st;    //按所需顺序逆序压入栈后再取出
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();      //将该节点弹出，避免重复操作，下面再将右中左节点压入栈中
                if(node->rchild) st.push(node->rchild); //将右节点压入栈中（空节点不入栈）
                if(node->lchild) st.push(node->lchild); //将左节点压入栈中
	            st.push(node);  //中节点入栈
                st.push(NULL);  //中节点访问过，但未处理，加入空节点作为标记  前序只是将此处的压入顺序修改
            }
            else{       //只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();   //将空节点弹出
                node = st.top();    //取出空节点后面的元素
                st.pop();           //弹出该元素
                result.push_back(node->data);   //将该元素放入结果集
            }
        }
        return result;
    }
};

void test01(){
    Solution01 s1;
    Solution02 s2;
    vector<int> result;
    TreeNode* root = CreateBinaryTree();
    //result = s1.inorderTraversal(root);
    result = s2.preorderTraversal(root);
    for(auto it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
