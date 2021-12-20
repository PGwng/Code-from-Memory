#include "AVL.h"


//以p为根的二叉排序树做右旋处理
//处理之后p指向新的树根节点，即旋转处理之前的左子树的根节点
void R_Rotate(TreeNode*& p) {
	TreeNode* L;		//L表示p的左孩子
	L = p->lchild;
	p->lchild = L->rchild;	//L的右子树挂接为p的左子树
	L->rchild = p;
	p = L;
}
//以p为根的二叉排序树做左旋处理
//处理之后p指向新的树根节点，即旋转处理之前的右子树的根节点
void L_Rotate(TreeNode*& p) {
	TreeNode* R;
	R = p->rchild;
	p->rchild = R->lchild;
	R->lchild = p;
	p = R;
}

//左平衡旋转
/*对T所指的根节点的二叉树做左平衡旋转处理，处理完成后T指向新的根节点*/
void LeftBalance(TreeNode*& T) {
	TreeNode* L;
	L = T->lchild;		//L指向T的左子树根节点
	switch (L->bf) {
		/*检查T的左子树的平衡度，并作相应平衡处理*/
	case LH:		/*新节点插入再T的左孩子的左子树上，要对节点T作单右旋处理*/
		T->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:			/*新节点插入在T的左孩子的右子树上，要作双旋处理
						先对L左旋，再对T右旋*/
		T->bf = L->bf = EH;
		L_Rotate(T->lchild);	//对T的左子树作左旋
		R_Rotate(T);			//对T作右旋
		break;
	}
}
//右平衡旋转
void RightBalance(TreeNode*& T) {
	TreeNode* R;
	R = T->rchild;
	switch (R->bf)
	{
	case LH:			/*新节点插入在T的右孩子的左子树上，要作双旋处理
						先对R作右旋处理，再对T作左旋*/
		T->bf = R->bf = EH;
		R_Rotate(T->rchild);
		L_Rotate(T);
		break;
	case RH:			/*新节点插入在T的右孩子的右子树上，对T作单左旋处理*/
		T->bf = R->bf = EH;
		L_Rotate(T);            //对T作左旋
		break;
	}
}
/*若在平衡的二叉排序树T中不存在和e有相同关键字的节点，则插入一个
  数据元素为e的新节点并返回1，否则返回0。若因插入使得二叉排序树
  失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否*/
bool InsertAVL(TreeNode*& T, int e, bool& taller) {
	if (!T) {
		/*若T为空，插入新节点，树“长高”，置taller为TRUE*/
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = TRUE;
	}
	else {
		if (e == T->data) {
			/*树中已存在和e有相同关键字的节点则不再插入*/
			taller = FALSE;
			return FALSE;
		}
		if (e < T->data) {
			/*应继续在T的左子树中进行搜索*/
			if (!InsertAVL(T->lchild, e, taller))	//未插入
				return FALSE;
			if (taller) {							//已经插入到T的左子树中，且左子树“长高”
				switch (T->bf) {					//检查父节点的平衡度
				case LH:							//原本左子树比右子树高，需要作左平衡处理
					LeftBalance(T);
					taller = FALSE;
					break;
				case EH:							//原本左右子树等高，现因左子树增高而树增高，修改父节点的平衡因子
					T->bf = LH;						//修改父节点平衡因子
					taller = TRUE;					//修改完父节点T的bf还要返回上一层判断父节点的父节点的bf是否失衡
													//所以这里taller要置TRUE，以返回上一层
					break;
				case RH:							//原本右子树比左子树高，现左右子树等高
					T->bf = EH;
					taller = FALSE;
					break;
				}
			}
		}
		else {
			/*应继续在T的右子树中进行搜索*/
			if (!InsertAVL(T->rchild, e, taller))
				return FALSE;
			if (taller) {
				switch (T->bf) {
				case LH:							//原本左子树比右子树高，现左右子树等高
					T->bf = EH;
					taller = FALSE;
					break;
				case EH:							//原本左右子树等高，现因右子树增高而树增高
					T->bf = RH;						//增高导致T平衡因子变化，需返回上一层判断T的父节点平衡因子是否失衡
					taller = TRUE;					//所以这里taller置TRUE
					break;
				case RH:							//原本右子树比左子树高，需作右平衡处理
					RightBalance(T);
					taller = FALSE;
					break;
				}
			}
		}
	}
	return TRUE;
}

//递归
void Recursion(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	//中序遍历
	//先遍历左子树
	Recursion(root->lchild);

	//再访问根节点
	printf("%d ", root->data);

	//再遍历右子树
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



