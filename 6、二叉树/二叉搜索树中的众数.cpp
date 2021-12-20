/* ************************************************************************
> File Name:     二叉搜索树中的众数.cpp
> Author:        wang
> Created Time:  Thu Nov 11 10:07:41 2021
> Description:   
 ************************************************************************/
#include "AVL.h"
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

//递归 利用哈希表存储元素出现频率 再进行排序
class Solution01{
private:
    void searchBST(TreeNode* cur, unordered_map<int, int>& map){
        if(cur == NULL) return;
        map[cur->data]++;   //  统计元素频率
        searchBST(cur->lchild, map);
        searchBST(cur->rchild, map);
        return;
    }
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root){
        unordered_map<int, int> map;    //key：元素， value：出现的频率
        vector<int> result;
        if(root == NULL) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);  //对频率排序
        result.push_back(vec[0].first);
        for(int i = 1; i < vec.size(); i++){
            //取最高的放到result数组中
            if(vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};
//递归 中序相邻两个元素比较 记录频率最高的元素
class Solution02{
private:
    int maxCount;   //最大频率
    int count;      //统计频率
    TreeNode* pre;
    vector<int> result;
    void searchBST(TreeNode* cur){
        if(cur == NULL) return;
        searchBST(cur->lchild);     //左
                                    //中
        if(pre == NULL) {           //pre = NULL说明这是遍历的第一个节点
            count = 1;
        }
        else if(pre->data == cur->data){    //如果当前节点与前一个节点数值相同
            count++;
        }
        else{
                 count = 1;  //如果当前节点与前一个节点数值不同，清空count，开始统计当前元素的count
        }
        pre = cur;      //更新上一个节点
        if(count == maxCount){  //如果和最大频率相同，放进result
            result.push_back(cur->data);
        }
        if(count > maxCount){   //如果统计频率大于最大频率
            maxCount = count;   //更新最大频率
            result.clear(); //关键的一步，更新最大频率后，之前result里的元素全部失效
            result.push_back(cur->data);
        }
        searchBST(cur->rchild);     //右
        return;
    }
public:
    vector<int> findMode(TreeNode* root){
        count = 0;
        maxCount = 0;
        pre = NULL;
        result.clear();

        searchBST(root);
        return result;
    }
};

class Solution03{
public:
    vector<int> findMode(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* pre = NULL;
        int maxCount = 0;   //最大频率
        int count = 0;      //统计频率
        vector<int> result;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            if(cur != NULL){
                st.pop();   //弹出节点 防止重复入栈
                if(cur->rchild) st.push(cur->rchild);   //右
                st.push(cur);                           //中
                st.push(NULL);                          //标记
                if(cur->lchild) st.push(cur->lchild);   //左
            }
            else{
                st.pop();   //弹出空节点
                cur = st.top();
                st.pop();
                if(pre == NULL){     //弹出的是中序遍历的第一个节点
                    count = 1;
                }
                else if(pre->data == cur->data){    //当前与前一个节点数值相同
                    count++;
                }
                else{   //当前节点与前一个节点数值不同
                    count = 1;
                }
                if(count == maxCount){  //如果统计频率等于最大频率
                    result.push_back(cur->data);    //将节点数据放入result
                }
                if(count > maxCount){
                    maxCount = count;
                    result.clear();
                    result.push_back(cur->data);
                }
                pre = cur;  //更新pre的指向
            }
        }
        return result;
    }
};

void test01(){
    TreeNode* root = CreateBinaryTree();
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = 1;
    node->lchild = node->rchild = NULL;
    node->bf = 0;
    root->lchild->lchild->lchild = node;

    Solution01 s1;
    Solution02 s2;
    Solution03 s3;
    vector<int> result = s3.findMode(root);
    for(auto it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    test01();
    return 0;
}
