#if 0
#include <iostream>
#include <list>
using namespace std;

//定义链表节点
struct ListNode {
	ListNode* next;
};

//定义链表
struct LinkList {
	ListNode head;
	int size;
};

struct myData {
	ListNode node;
	int num;
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
			}
			else {
				pCurrent = pCurrent->next;
			}
		}
	}
};

void test01() {
	int val = 6;
	myData d1, d2, d3, d4, d5, d6, d7;
	d1.num = 1;
	d2.num = 2;
	d3.num = 6;
	d4.num = 3;
	d5.num = 4;
	d6.num = 5;
	d7.num = 6;

	Solution s;
	LinkList* list = s.Init_LinkList();
	list->head.next = (ListNode*)&d1;
	((ListNode*)&d1)->next = (ListNode*)&d2;
	((ListNode*)&d2)->next = (ListNode*)&d3;
	((ListNode*)&d3)->next = (ListNode*)&d4;
	((ListNode*)&d4)->next = (ListNode*)&d5;
	((ListNode*)&d5)->next = (ListNode*)&d6;
	((ListNode*)&d6)->next = (ListNode*)&d7;
	((ListNode*)&d7)->next = NULL;

	s.Remove_ListNode(list, val);
	list->size = 6;
	
	//辅助指针变量
	ListNode* pCurrent = list->head.next;
	while (pCurrent != NULL) {
		cout << ((myData*)pCurrent)->num << " ";
		pCurrent = pCurrent->next;
	}
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}
#endif