/* ************************************************************************
> File Name:     最大二叉树.cpp
> Author:        wang
> Created Time:  Tue Nov  2 20:38:47 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>

//递归 前序遍历  循环不变量左闭右开
//构造树一般采用的是前序遍历 先构造中节点 然后递归构造左右节点
class Solution {
public:
    TreeNode* createNewNode(){
        TreeNode* node = new TreeNode;
        node->data = 0;
        node->bf = 0;
        node->lchild = NULL;
        node->rchild = NULL;
        return node;
    }
    TreeNode* constructMaxBinaryTree(vector<int>& nums){
        TreeNode* node = createNewNode();
        if(nums.size() == 1) {      //如果遍历到叶子节点
            node->data = nums[0];
            return node;
        }
        //找到数组中的最大值和对应下标
        int maxValue = 0;
        int maxValueIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->data = maxValue;                                                   //中      
        //最大值所在的下标左区间（左闭右开） 构造左子树
        if(maxValueIndex > 0){      //保证左区间至少有一个元素
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex); //左区间
            node->lchild = constructMaxBinaryTree(newVec);  //左子树根节点                     //左  
        }
        //最大值所在下标的右区间（左闭右开） 构造右子树
        if(maxValueIndex < (nums.size() - 1)){      //保证右区间至少有一个元素
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());   //右区间
            node->rchild = constructMaxBinaryTree(newVec);  //右子树根节点       //右
        }
        return node;    //返回最大二叉树根节点
    }
};

void test01(){
    vector<int> nums = { 3, 2, 1, 6, 0, 5 };
    TreeNode* root;
    Solution s;
    root = s.constructMaxBinaryTree(nums);
    Recursion(root);
    cout << endl;
}
int main(){
    test01();
    return 0;
}
