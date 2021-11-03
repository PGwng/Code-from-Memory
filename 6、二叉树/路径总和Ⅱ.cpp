/* ************************************************************************
> File Name:     路径总和Ⅱ.cpp
> Author:        wang
> Created Time:  Tue Nov  2 17:30:53 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>

//递归
class Solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    //递归函数不需要返回值，因为我们需要遍历整个树
    void traversal(TreeNode* cur, int count){
        //遇到叶子节点且路径总和等于目标值
        if(!cur->lchild && !cur->rchild && count == 0){     //中
            result.push_back(path);
            return;
        }
        //遇到叶子节点但路径总和不等于目标值
        if(!cur->lchild && !cur->rchild) return;
        
        if(cur->lchild) {       //左
            path.push_back(cur->lchild->data);
            traversal(cur->lchild, count - cur->lchild->data);  //这里隐藏着回溯
            path.pop_back();                                    //回溯
        }
        if(cur->rchild){        //右
            path.push_back(cur->rchild->data);
            traversal(cur->rchild, count - cur->rchild->data);  //这里隐藏着回溯
            path.pop_back();                                    //回溯
        }
        return;
    }
public:
    vector<vector<int>> pathsum(TreeNode* root, int sum){
        result.clear();
        path.clear();
        if(root == NULL) return result;
        path.push_back(root->data);     //把根节点放进路径
        traversal(root, sum - root->data);
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    Solution s;
    vector<vector<int>> result = s.pathsum(root, 22);
    for(auto it = result.begin(); it != result.end(); it++) {
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
