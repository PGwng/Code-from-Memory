#if 0
#include <iostream>
#include <list>
using namespace std;

//定义链表节点
struct ListNode {
	ListNode* next;
	//ListNode():next(nullptr){ }
	//这里的构造函数相当于
	//			ListNode(){
	//				next = nullptr;
	//			}
};

//定义链表
struct LinkList {
	ListNode head;
	int size;
};

struct myData {
	ListNode node;
	int num;
	/*myData() {
		node.next = nullptr;
		num = num;
	}*/
};

class Solution {
public:
	//初始化链表
	LinkList* Init_LinkList() {
		LinkList* list = new LinkList;
		list->head.next = NULL;
		list->size = 0;
		return list;
	}
	//获取链表中第index个节点的值。如果索引无效则返回-1。
	int get(LinkList* list, int index) {
		if (list == NULL) return 0;
		if (index < 0 || index > list->size) return -1;
		//辅助指针变量		头一个存有数据的节点为第0个节点，由0开始计数
		ListNode* pCurrent = &(list->head);		//pCurrent->next是第0个节点的地址
		for (int i = 0; i < index; i++) {
			pCurrent = pCurrent->next;
		}
		return ((myData*)pCurrent->next)->num;
	}

	//在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
	void addAtHead(LinkList* list, ListNode* newNode, int val) {
		if (list == NULL) return;
		//辅助指针变量
		ListNode* pCurrent = &(list->head);
		//初始化要插入的数据节点
		newNode->next = NULL;
		((myData*)newNode)->num = val;
		//插入
		newNode->next = pCurrent->next;
		pCurrent->next = newNode;
		//更新size
		list->size++;
	}
	//将值为 val 的节点追加到链表的最后一个元素。
	void addAtTail(LinkList* list, ListNode* newNode, int val) {
		if (list == NULL) return;
		//辅助指针变量
		ListNode* pCurrent = &(list->head);
		//移动到最后一个节点的位置
		for (int i = 0; i < list->size; i++) {
			pCurrent = pCurrent->next;
		}
		//初始化要插入的数据节点
		newNode->next = NULL;
		((myData*)newNode)->num = val;
		//插入
		newNode->next = pCurrent->next;
		pCurrent->next = newNode;

		//更新size
		list->size++;
	}

	//addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为val的节点。
	//如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。
	//如果index小于0，则在头部插入节点
	void addAtIndex(LinkList* list, int index, ListNode* newNode, int val) {
		if (list == NULL) return;
		if (index < 0) index = 0;
		if (index > list->size)	return;
		//辅助指针变量
		ListNode* pCurrent = &(list->head);
		//移动到index的前一个位置（index从0开始计数）
		for (int i = 0; i < index; i++) {
			pCurrent = pCurrent->next;
		}
		//初始化要插入的节点
		newNode->next = NULL;
		((myData*)newNode)->num = val;
		//插入
		newNode->next = pCurrent->next;
		pCurrent->next = newNode;
		//更新size
		list->size++;
	}
	//deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
	void deleteAtIndex(LinkList* list, int index) {
		if (list == NULL) return;
		if (index >= 0 && index < list->size) {
			//辅助指针变量
			ListNode* pCurrent = &(list->head);
			//移动到index前一个元素
			for (int i = 0; i < index; i++) {
				pCurrent = pCurrent->next;
			}
			//删除
			pCurrent->next = pCurrent->next->next;
			//更新size
			list->size--;
		}
	}

	//根据值删除节点
	void Remove_ListNode(LinkList* list, int val) {
		if (list == NULL) return;
		//辅助指针变量，头节点不存储数据，从头节点的下一节点开始查询
		ListNode* pCurrent = &(list->head);
		while (pCurrent->next != NULL) {	//要查找的是pCurrent->next节点中的数据，当节点pCurrent->next地址为空时终止循环
			if (((myData*)pCurrent->next)->num == val) {	//->运算优先级比( )高，所以(myData*)pCurrent外面要加小括号再作->操作
				//ListNode* temp = pCurrent->next;		
				pCurrent->next = pCurrent->next->next;
				//delete temp;						//这里未在堆区申请空间，节点是栈上的局部变量，delete会导致程序崩溃
				list->size--;
			}
			else {
				pCurrent = pCurrent->next;
			}
		}
	}
};
//判断链表是否相交并返回交点
class IntersectionSolution {
public:
	ListNode* getIntersectionNode(LinkList* listA, LinkList* listB) {
		//辅助指针变量
		ListNode* pCurrentA = listA->head.next;
		ListNode* pCurrentB = listB->head.next;

		int lenA = listA->size;
		int lenB = listB->size;

		//让pCurrentA指向最长链表的第一个元素，lenA为其长度
		if (lenB > lenA) {
			swap(lenA, lenB);
			swap(pCurrentA, pCurrentB);
		}
		//求长度差
		int gap = lenA - lenB;
		//让pCurrentA和pCurrentB在同一起点上（末尾位置对齐）
		while (gap--) {
			pCurrentA = pCurrentA->next;
		}
		//遍历pCurrentA和pCurrentB，遇到相同直接返回
		while (pCurrentA != NULL) {
			if (pCurrentA == pCurrentB) {
				return pCurrentA;
			}
			pCurrentA = pCurrentA->next;
			pCurrentB = pCurrentB->next;
		}
		return NULL;
	}
};

//打印链表
void printLinkList(LinkList* list) {
	//辅助指针变量
	ListNode* pCurrent = list->head.next;
	while (pCurrent != NULL) {
		cout << ((myData*)pCurrent)->num << " ";
		pCurrent = pCurrent->next;
	}
	cout << endl;
}

void test01() {

	Solution s;
	LinkList* listA = s.Init_LinkList();
	LinkList* listB = s.Init_LinkList();
	myData a1, a2, a3, a4, a5, a6;
	myData b1, b2, b3, b4, b5, b6;

	s.addAtTail(listA, (ListNode*)&a1, 1);
	s.addAtTail(listA, (ListNode*)&a2, 2);
	s.addAtTail(listA, (ListNode*)&a3, 3);
	s.addAtTail(listA, (ListNode*)&a4, 4);
	s.addAtTail(listA, (ListNode*)&a5, 5);
	s.addAtTail(listA, (ListNode*)&a6, 6);

	/*s.addAtTail(listB, (ListNode*)&b1, 7);
	s.addAtTail(listB, (ListNode*)&b2, 8);*/
	s.addAtTail(listB, (ListNode*)&b3, 9);
	s.addAtTail(listB, (ListNode*)&a4, 4);
	s.addAtTail(listB, (ListNode*)&a5, 5);
	s.addAtTail(listB, (ListNode*)&a6, 6);

	IntersectionSolution intersectionS;
	ListNode* intersection = intersectionS.getIntersectionNode(listA, listB);
	if (intersection == NULL) cout << "无交点" << endl;
	else cout << "交点元素值为" << ((myData*)intersection)->num << endl;

	//打印 
	//printLinkList(listA);
}

int main() {
	test01();
	system("pause");
	return 0;
}
#endif
