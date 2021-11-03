/* ************************************************************************
> File Name:     二叉树的层序遍历.cpp
> Author:        wang
> Created Time:  Thu Oct 28 09:45:29 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            //这里一定要用固定大小的size，不要使用que.size(),que.size()是不断变化的
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->data);
                if(node->lchild) que.push(node->lchild);
                if(node->rchild) que.push(node->rchild);
            }
            result.push_back(vec);
        }
        return result;
    }
};

void test01(){
    Solution s;
    TreeNode* root = CreateBinaryTree();
    vector<vector<int>> result;
    result = s.levelOrder(root);
    for(auto it = result.begin(); it != result.end(); it++){
        for(auto it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++){
            cout << *it_inner << "\t" << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    test01();
    return 0;
}
