#include "AVL.h"


//��pΪ���Ķ�������������������
//����֮��pָ���µ������ڵ㣬����ת����֮ǰ���������ĸ��ڵ�
void R_Rotate(TreeNode*& p) {
	TreeNode* L;		//L��ʾp������
	L = p->lchild;
	p->lchild = L->rchild;	//L���������ҽ�Ϊp��������
	L->rchild = p;
	p = L;
}
//��pΪ���Ķ�������������������
//����֮��pָ���µ������ڵ㣬����ת����֮ǰ���������ĸ��ڵ�
void L_Rotate(TreeNode*& p) {
	TreeNode* R;
	R = p->rchild;
	p->rchild = R->lchild;
	R->lchild = p;
	p = R;
}

//��ƽ����ת
/*��T��ָ�ĸ��ڵ�Ķ���������ƽ����ת����������ɺ�Tָ���µĸ��ڵ�*/
void LeftBalance(TreeNode*& T) {
	TreeNode* L;
	L = T->lchild;		//Lָ��T�����������ڵ�
	switch (L->bf) {
		/*���T����������ƽ��ȣ�������Ӧƽ�⴦��*/
	case LH:		/*�½ڵ������T�����ӵ��������ϣ�Ҫ�Խڵ�T������������*/
		T->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:			/*�½ڵ������T�����ӵ��������ϣ�Ҫ��˫������
						�ȶ�L�������ٶ�T����*/
		T->bf = L->bf = EH;
		L_Rotate(T->lchild);	//��T��������������
		R_Rotate(T);			//��T������
		break;
	}
}
//��ƽ����ת
void RightBalance(TreeNode*& T) {
	TreeNode* R;
	R = T->rchild;
	switch (R->bf)
	{
	case LH:			/*�½ڵ������T���Һ��ӵ��������ϣ�Ҫ��˫������
						�ȶ�R�����������ٶ�T������*/
		T->bf = R->bf = EH;
		R_Rotate(T->rchild);
		L_Rotate(T);
		break;
	case RH:			/*�½ڵ������T���Һ��ӵ��������ϣ���T������������*/
		T->bf = R->bf = EH;
		L_Rotate(T);            //��T������
		break;
	}
}
/*����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽڵ㣬�����һ��
  ����Ԫ��Ϊe���½ڵ㲢����1�����򷵻�0���������ʹ�ö���������
  ʧȥƽ�⣬����ƽ����ת������������taller��ӳT�������*/
bool InsertAVL(TreeNode*& T, int e, bool& taller) {
	if (!T) {
		/*��TΪ�գ������½ڵ㣬�������ߡ�����tallerΪTRUE*/
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = TRUE;
	}
	else {
		if (e == T->data) {
			/*�����Ѵ��ں�e����ͬ�ؼ��ֵĽڵ����ٲ���*/
			taller = FALSE;
			return FALSE;
		}
		if (e < T->data) {
			/*Ӧ������T���������н�������*/
			if (!InsertAVL(T->lchild, e, taller))	//δ����
				return FALSE;
			if (taller) {							//�Ѿ����뵽T���������У��������������ߡ�
				switch (T->bf) {					//��鸸�ڵ��ƽ���
				case LH:							//ԭ�����������������ߣ���Ҫ����ƽ�⴦��
					LeftBalance(T);
					taller = FALSE;
					break;
				case EH:							//ԭ�����������ȸߣ��������������߶������ߣ��޸ĸ��ڵ��ƽ������
					T->bf = LH;						//�޸ĸ��ڵ�ƽ������
					taller = TRUE;					//�޸��길�ڵ�T��bf��Ҫ������һ���жϸ��ڵ�ĸ��ڵ��bf�Ƿ�ʧ��
													//��������tallerҪ��TRUE���Է�����һ��
					break;
				case RH:							//ԭ�����������������ߣ������������ȸ�
					T->bf = EH;
					taller = FALSE;
					break;
				}
			}
		}
		else {
			/*Ӧ������T���������н�������*/
			if (!InsertAVL(T->rchild, e, taller))
				return FALSE;
			if (taller) {
				switch (T->bf) {
				case LH:							//ԭ�����������������ߣ������������ȸ�
					T->bf = EH;
					taller = FALSE;
					break;
				case EH:							//ԭ�����������ȸߣ��������������߶�������
					T->bf = RH;						//���ߵ���Tƽ�����ӱ仯���践����һ���ж�T�ĸ��ڵ�ƽ�������Ƿ�ʧ��
					taller = TRUE;					//��������taller��TRUE
					break;
				case RH:							//ԭ�����������������ߣ�������ƽ�⴦��
					RightBalance(T);
					taller = FALSE;
					break;
				}
			}
		}
	}
	return TRUE;
}

//�ݹ�
void Recursion(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	//�������
	//�ȱ���������
	Recursion(root->lchild);

	//�ٷ��ʸ��ڵ�
	printf("%d ", root->data);

	//�ٱ���������
	Recursion(root->rchild);	
}

TreeNode* CreateBinaryTree() {
	int a[10] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	TreeNode* T = NULL;
	bool taller = false;
	for (int i = 0; i < 10; i++) {
		InsertAVL(T, a[i], taller);
	}
	return T;
}



