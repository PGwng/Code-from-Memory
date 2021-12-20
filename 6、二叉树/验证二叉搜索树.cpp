/* ************************************************************************
> File Name:     验证二叉搜索树.cpp
> Author:        wang
> Created Time:  Wed Nov 10 15:16:42 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>
#include <stack>
#include <climits>

//中序递归遍历 转成数组
class Solution01{
private:
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->lchild);    //左
        vec.push_back(root->data);   //中
        traversal(root->rchild);    //右
    }
public:
    bool isValidBST(TreeNode* root){
        vec.clear();    //清空容器
        traversal(root);
        for(int i = 1; i < vec.size(); i++){
            //注意要小于等于，搜索树里不能有相同的元素
            if(vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};

//递归 直接中序遍历比较 维护一个maxVal 如果出现小于maxVal的节点则不是BST
class Solution02{
public:
    long long maxVal = LONG_MIN;    //测试的节点值可能有int的最小值
    bool isValidBST(TreeNode* root){
        if(root == NULL) return true;

        bool lchild = isValidBST(root->lchild);
        if(maxVal < root->data) maxVal = root->data;
        else return false;
        bool rchild = isValidBST(root->rchild);

        return lchild && rchild;
    }
};
//取到最左边的节点来比较
class Solution03{
public:
    TreeNode* pre = NULL;   //用来记录前一个节点
    bool isValidBST(TreeNode* root){
        if(root == NULL) return true;
        bool lchild = isValidBST(root->lchild);

        if(pre != NULL && pre->data >= root->data) return false;
        pre = root;

        bool rchild = isValidBST(root->rchild);
        return lchild && rchild;
    }
};

class Solution04{
public:
    bool isValidBST(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* pre = NULL;   //记录前一个节点
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            if(cur != NULL){
                st.pop();
                if(cur->rchild) st.push(cur->rchild);   //右
                st.push(cur);                           //中
                st.push(NULL);                          //标记未处理节点
                if(cur->lchild) st.push(cur->lchild);   //左
            }
            else{
                st.pop();   //弹出空节点
                cur = st.top();
                st.pop();
                if(pre != NULL && cur->data <= pre->data) return false;
                pre = cur;
            }
        }
        return true;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    Solution04 s4;
    cout << s4.isValidBST(root) << endl;
}
int main(){
    test01();
    return 0;
}
