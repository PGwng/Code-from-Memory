/* ************************************************************************
> File Name:     路径总和Ⅰ.cpp
> Author:        wang
> Created Time:  Tue Nov  2 15:31:59 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <stack>

//递归 前序遍历
class Solution01{
private:
    bool traversal(TreeNode* cur, int count){
        //遇到叶子节点 并且计数器减至0
        if(!cur->lchild && !cur->rchild && count == 0) return true;             //中
        //遇到叶子节点 计数器不为零 直接返回
        if(!cur->lchild && !cur->rchild) return false;

        if(cur->lchild){                                                        //左
            //遇到叶子节点返回true 则本层递归函数直接返回true
            if(traversal(cur->lchild, count - cur->lchild->data)) return true;  //注意这里有回溯逻辑，count传参返回上一层时，上一层的count没有改变，相当于操作撤销
        }
        if(cur->rchild){                                                        //右
            //遇到叶子节点返回true 则本层递归函数直接返回true
            if(traversal(cur->rchild, count - cur->rchild->data)) return true;
        }
        return false;
    }
public:
    bool haspathsum(TreeNode* root, int sum){
        if(root == NULL) return false;
        return traversal(root, sum - root->data);
    }
};

//迭代模拟前序递归
class Solution02{
public:
    bool haspathsum(TreeNode* root, int sum){
        if(root == NULL) return false;
        //此时栈里要放的是pair<节点指针，路径数值>
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->data));
        while(!st.empty()){
            pair<TreeNode*, int> node = st.top();
            if(node.first != NULL){
                st.pop();   //将该节点弹出，避免重复操作，下面再将右左中节点压入栈
                if(node.first->rchild) st.push(pair<TreeNode*, int>(node.first->rchild, node.second + node.first->rchild->data));  //右 
                if(node.first->lchild) st.push(pair<TreeNode*, int>(node.first->lchild, node.second + node.first->lchild->data));  //左
                st.push(pair<TreeNode*, int>(node.first, node.second));                                   //中
                st.push(pair<TreeNode*, int>(NULL, 0)); //标记要处理的节点
            }
            else{
                st.pop();   //弹出空节点
                node = st.top();
                st.pop();
                //如果该节点是叶子节点了，同时该节点的路径总和数值等于sum，返回true
                if(!node.first->lchild && !node.first->rchild && sum == node.second) return true;

            }
        }
        return false;
    }
};


void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    int sum = 22;
    cout << s1.haspathsum(root, sum) << endl;
    cout << s2.haspathsum(root, sum) << endl;
}
int main(){
    test01();
    return 0;
}
