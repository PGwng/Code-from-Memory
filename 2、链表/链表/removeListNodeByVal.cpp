#if 0
#include <iostream>
#include <list>
using namespace std;

//��������ڵ�
struct ListNode {
	ListNode* next;
};

//��������
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
	//��ʼ������
	LinkList* Init_LinkList() {
		LinkList* list = new LinkList;
		list->head.next = NULL;
		list->size = 0;
		return list;
	}

	//����ֵɾ���ڵ�
	void Remove_ListNode(LinkList* list, int val) {
		if (list == NULL) return;
		//����ָ�������ͷ�ڵ㲻�洢���ݣ���ͷ�ڵ����һ�ڵ㿪ʼ��ѯ
		ListNode* pCurrent = &(list->head);
		while (pCurrent->next != NULL) {	//Ҫ���ҵ���pCurrent->next�ڵ��е����ݣ����ڵ�pCurrent->next��ַΪ��ʱ��ֹѭ��
			if (((myData*)pCurrent->next)->num == val) {	//->�������ȼ���( )�ߣ�����(myData*)pCurrent����Ҫ��С��������->����
				//ListNode* temp = pCurrent->next;		
				pCurrent->next = pCurrent->next->next;
				//delete temp;						//����δ�ڶ�������ռ䣬�ڵ���ջ�ϵľֲ�������delete�ᵼ�³������
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
	
	//����ָ�����
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