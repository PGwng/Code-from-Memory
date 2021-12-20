/* ************************************************************************
> File Name:     二叉搜索树的最小绝对差.cpp
> Author:        wang
> Created Time:  Wed Nov 10 20:11:04 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <climits>
#include <vector>
#include <stack>

//递归 转成数组再比较
class Solution01{
private:
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->lchild);    //左
        vec.push_back(root->data);  //中
        traversal(root->rchild);    //右
    }
public:
    int getMinDifference(TreeNode* root){
        vec.clear();
        traversal(root);
        if(vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 0; i < vec.size(); i++){
            result = min(result, vec[i] - vec[i -1]);
        }
        return result;
    }
};
//递归 直接比较
class Solution02{
private:
    int result = INT_MAX;
    TreeNode* pre = NULL;
    void traversal(TreeNode* cur){
        if(cur == NULL) return;
        traversal(cur->lchild); //左
        if(pre != NULL){
            result = min(result, cur->data - pre->data);
        }
        pre = cur;  //记录前一个节点
        traversal(cur->rchild); //右
    }
public:
    int getMinDifference(TreeNode* root){
        traversal(root);
        return result;
    }
};

//迭代 栈模拟中序遍历
class Solution03{
public:
    int getMinDifference(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* pre = NULL;
        int result = INT_MAX;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            if(cur != NULL){        //节点按中序的逆序压入栈，并对要处理节点做标记
                st.pop();           //弹出节点，防止重复入栈
                if(cur->rchild) st.push(cur->rchild);
                st.push(cur);
                st.push(NULL);
                if(cur->lchild) st.push(cur->lchild);
            }
            else{           //弹出顺序即中序，按需要处理数据
                st.pop();   //弹出空节点
                cur = st.top();
                st.pop();
                if(pre != NULL){
                    result = min(result, cur->data - pre->data);
                }
                pre = cur;  //将当前节点记录为下一次弹出节点的前一个节点
            }
        }
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    Solution03 s3;
    cout << s3.getMinDifference(root) << endl;
}
int main(){
    test01();
    return 0;
}
