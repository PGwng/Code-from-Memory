/* ************************************************************************
> File Name:     二叉排序树查找.cpp
> Author:        wang
> Created Time:  Sun Oct 17 10:30:58 2021
> Description:   
 ************************************************************************/
#include <iostream>
using namespace std;

#define TRUE  1
#define FALSE 0

typedef struct BiTNode{                 /* 节点结构 */
    int data;                           /* 节点数据 */
    struct BiTNode *lchild, *rchild;    /* 左右孩子指针 */
}BiTNode;

/*递归查找二叉排序树T中是否存在关键字key
 *指针f指向当前节点T的双亲，其初始调用值为NULL
 *若查找成功，则p指向该数据元素的节点，并返回TRUE
 *否则指针p指向查找路径上访问的最后一个节点并返回FALSE
 */
bool SearchBST(BiTNode* T, int key, BiTNode* f, BiTNode* p){
    if (!T){                    /*判断当前二叉树是否到叶子节点，若到达叶子节点，*/
        p = f;                  /*下次递归调用，T变为NULL，p指向双亲节点（即叶子节点）*/
        return FALSE;           /*查找失败*/
    }
    else if (key == T->data){   /*查找成功*/
        p = T;
        return TRUE;
    }
    else if(key < T->data){
        return SearchBST(T->lchild, key, T, p); /*在左子树继续查找*/
    }
    else
        return SearchBST(T->rchild, key, T, p);
}

int main(){
    BiTNode* n1 = new BiTNode;
    BiTNode* n2 = new BiTNode;
    BiTNode* n3 = new BiTNode;
    BiTNode* n4 = new BiTNode;
    BiTNode* n5 = new BiTNode;
    BiTNode* n6 = new BiTNode;
    BiTNode* n7 = new BiTNode;
    BiTNode* n8 = new BiTNode;
    BiTNode* n9 = new BiTNode;
    BiTNode* n10 = new BiTNode;
    n1->data = 62;
    n1->lchild = n2;
    n1->rchild = n3;
    n2->data = 58;
    n2->lchild = n4;
    n2->rchild = NULL;
    n3->data = 88;
    n3->lchild = n5;
    n3->rchild = n6;
    n4->data = 47;
    n4->lchild = n7;
    n4->rchild = n8;
    n5->data = 73;
    n5->lchild = NULL;
    n5->rchild = NULL;
    n6->data = 99;
    n6->lchild = n9;
    n6->rchild = NULL;
    n7->data = 35;
    n7->lchild = NULL;
    n7->rchild = n10;
    n8->data = 51;
    n8->lchild = NULL;
    n8->rchild = NULL;
    n9->data = 93;
    n9->lchild = NULL;
    n9->rchild = NULL;
    n10->data = 37;
    n10->lchild = NULL;
    n10->rchild = NULL;
    BiTNode* p;
    bool Status = SearchBST(n1, 93, NULL, p);
    if(Status == TRUE) cout << "找到了" << endl;
    else cout << "没找到" << endl;
    return 0;
}


