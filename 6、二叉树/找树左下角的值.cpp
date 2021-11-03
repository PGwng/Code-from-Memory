/* ************************************************************************
> File Name:     找树左下角的值.cpp
> Author:        wang
> Created Time:  Mon Nov  1 15:20:53 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <climits>
#include <queue>

//前序递归
class Solution01{
public:
    int maxLen = INT_MIN;   //全局变量  记录最大深度
    int maxleftValue;       //全局变量  记录最大深度左节点的数值
    void traversal(TreeNode* node, int leftLen){    //leftLen记录当前的最长深度
        if(node->lchild == NULL && node->rchild == NULL){       //中
            if(leftLen > maxLen){
                maxLen = leftLen;
                maxleftValue = node->data;
            }
            return;
        }
        if(node->lchild){                                       //左
            traversal(node->lchild, leftLen + 1);   //形参传值，隐藏着回溯
        }
        if(node->rchild){                                       //右
            traversal(node->rchild, leftLen + 1);   //形参传值，隐藏着回溯
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root){
        traversal(root, 0);
        return maxleftValue;
    }
};

//迭代 层序遍历
class Solution02{
public:
    int findBottomLeftValue(TreeNode* root){
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        int result = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(i == 0) result = node->data; //记录最后一行的第一个元素
                if(node->lchild) que.push(node->lchild);
                if(node->rchild) que.push(node->rchild);
            }
        }
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution02 s2;
    cout << "树左下角的值为：" << s1.findBottomLeftValue(root) << endl;
    cout << "树左下角的值为：" << s2.findBottomLeftValue(root) << endl;
}
int main(){
    test01();
    return 0;
}
