#ifndef AVL_H
#define AVL_H

#include <iostream>
#include<string.h>
using namespace std;

#define TRUE	1
#define FALSE	0
#define LH		+1	//���
#define EH		0	//�ȸ�
#define RH		-1	//�Ҹ�

//�������ڵ㣨��������ʾ����
typedef struct TreeNode {
	int data;						//�ڵ�����
	int bf;							//balance factorƽ�����ӣ����������-��������ȣ�
	struct TreeNode* lchild;		//����ָ��
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
