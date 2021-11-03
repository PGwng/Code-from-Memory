/* ************************************************************************
> File Name:     左叶子之和.cpp
> Author:        wang
> Created Time:  Mon Nov  1 10:41:50 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <stack>

//递归 后序遍历 因为要通过递归函数的返回值来累加求取左叶子数值之和
class Solution01{
public:
    int sumOfLeftLeaves(TreeNode* root){
        if(root == NULL) return 0;

        int leftValue = sumOfLeftLeaves(root->lchild);      //左
        int rightValue = sumOfLeftLeaves(root->rchild);     //右
                                                            //中
        int midValue = 0;
        if(root->lchild && !root->lchild->lchild && !root->lchild->rchild){
            midValue = root->lchild->data;
        }
        int sum = midValue + leftValue + rightValue;
        return sum;
    }
};

//迭代法使用前中后序都可以，只要把叶子节点统计出来就可以，此处用迭代遍历的统一写法 中序遍历
class Solution02{
public:
    int sumOfLeftLeaves(TreeNode* root){
        stack<TreeNode*> st;
        if(root == NULL) return 0;
        st.push(root);                  //中
        int result = 0;
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();   //将该节点弹出，避免重复操作，下面在将右中左节点压入栈
                if(node->rchild) st.push(node->rchild); //右
                st.push(node);                          //中
                st.push(NULL);  //中节点访问过，但未处理，加入空节点作为标记，（因为未处理，所以是要处理的节点，每个节点都会按弹出顺序成为要处理的节点）
                if(node->lchild) st.push(node->lchild); //左
            }
            else{       //只有遇到空节点的时候，才对空节点的下一个节点进行逻辑处理
                st.pop();   //弹出空节点
                node = st.top();    //取出空节点后面的元素
                st.pop();
                if(node->lchild && !node->lchild->lchild && !node->lchild->rchild){
                    result += node->lchild->data;
                }
            }
        }
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    cout << "左叶子之和为：" << s1.sumOfLeftLeaves(root) << endl;
    cout << "左叶子之和为：" << s2.sumOfLeftLeaves(root) << endl;
}
int main(){
    test01();
    return 0;
}
