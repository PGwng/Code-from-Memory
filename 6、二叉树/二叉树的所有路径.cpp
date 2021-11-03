/* ************************************************************************
> File Name:     二叉树的所有路径.cpp
> Author:        wang
> Created Time:  Sun Oct 31 19:45:00 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>
#include <string>
#include <stack>

//递归前序遍历
class Solution01{
private:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result){
        path.push_back(cur->data);                          //中
        //找到叶子节点时 (递归终止条件) 存入节点（处理逻辑）
        if(cur->lchild == NULL && cur->rchild == NULL){
            string sPath;
            for(int i = 0; i < path.size() - 1; i++){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        //有一个递归就要有一个回溯
        if(cur->lchild){                                    //左
            traversal(cur->lchild, path, result);
            path.pop_back();    //回溯，删除path中的节点
        }
        if(cur->rchild){                                    //右
            traversal(cur->rchild, path, result);
            path.pop_back();    //回溯
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> result;
        vector<int> path;
        if(root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};
//Solution01精简
class Solution02{
private:
    void traversal(TreeNode* cur, string path, vector<string>& result){
        path += to_string(cur->data);                   //中
        if(cur->lchild == NULL && cur->rchild == NULL){
            result.push_back(path);
            return;
        }
        //这里上一层的path以形参的形式传入下一层，所以回溯的时候还是原来那一层的path，
        //类似于Solution01中回溯时删除内层在path上添加的节点
        if(cur->lchild) traversal(cur->lchild, path + "->", result);    //左
        if(cur->rchild) traversal(cur->rchild, path + "->", result);    //右
    
    }
public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> result;
        string path;
        if(root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};
//迭代前序遍历 模拟递归需要一个栈，同时还需要一个栈来存放对应的遍历路径
class Solution03{
public:
    vector<string> binaryTreePaths(TreeNode* root){
        stack<TreeNode*> nodeSt;    //保存树的遍历节点
        stack<string> pathSt;       //保存遍历路径的节点
        vector<string> result;      //保存最终路径集合
        if(root == NULL) return result;
        nodeSt.push(root);
        pathSt.push(to_string(root->data));
        while(!nodeSt.empty()){
            TreeNode* node = nodeSt.top(); nodeSt.pop();        //取出节点 中
            string path = pathSt.top(); pathSt.pop();           //取出该节点对应的路径
            if(node->lchild == NULL && node->rchild == NULL){   //遇到叶子节点
                result.push_back(path);                         //将路径保存到栈里
            }
            if(node->rchild){
                nodeSt.push(node->rchild);                      //右
                pathSt.push(path + "->" + to_string(node->rchild->data));   //压入右节点对应的路径
            }
            if(node->lchild){
                nodeSt.push(node->lchild);                      //左
                pathSt.push(path + "->" + to_string(node->lchild->data));   //压入左节点对应的路径
            }
        }
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution01 s1;
    Solution03 s3;
    vector<string> result;
    result = s3.binaryTreePaths(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
