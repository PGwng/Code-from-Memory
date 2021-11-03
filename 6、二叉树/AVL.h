#ifndef AVL_H
#define AVL_H

#include <iostream>
#include<string.h>
using namespace std;

#define TRUE	1
#define FALSE	0
#define LH		+1	//左高
#define EH		0	//等高
#define RH		-1	//右高

//二叉树节点（二叉链表示法）
typedef struct TreeNode {
	int data;						//节点数据
	int bf;							//balance factor平衡因子（左子树深度-右子树深度）
	struct TreeNode* lchild;		//左孩子指针
	struct TreeNode* rchild;
	//TreeNode(int x) : data(x), bf(0), lchild(NULL), rchild(NULL){ }
}TreeNode;

void R_Rotate(TreeNode*& p);
void L_Rotate(TreeNode*& p);
void LeftBalance(TreeNode*& T);
void RightBalance(TreeNode*& T);
bool InsertAVL(TreeNode*& T, int e, bool& taller);
void Recursion(TreeNode* root);
TreeNode* CreateBinaryTree();

#endif // !AVL_H
