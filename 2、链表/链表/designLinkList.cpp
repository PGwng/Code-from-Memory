#if 0
#include <iostream>
#include <list>
using namespace std;

//��������ڵ�
struct ListNode {
	ListNode* next;
	//ListNode():next(nullptr){ }
	//����Ĺ��캯���൱��
	//			ListNode(){
	//				next = nullptr;
	//			}
};

//��������
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
	//��ʼ������
	LinkList* Init_LinkList() {
		LinkList* list = new LinkList;
		list->head.next = NULL;
		list->size = 0;
		return list;
	}
	//��ȡ�����е�index���ڵ��ֵ�����������Ч�򷵻�-1��
	int get(LinkList* list, int index) {
		if (list == NULL) return 0;
		if (index < 0 || index > list->size) return -1;
		//����ָ�����		ͷһ���������ݵĽڵ�Ϊ��0���ڵ㣬��0��ʼ����
		ListNode* pCurrent = &(list->head);		//pCurrent->next�ǵ�0���ڵ�ĵ�ַ
		for (int i = 0; i < index; i++) {
			pCurrent = pCurrent->next;
		}
		return ((myData*)pCurrent->next)->num;
	}

	//������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
	void addAtHead(LinkList* list, ListNode* newNode, int val) {
		if (list == NULL) return;
		//����ָ�����
		ListNode* pCurrent = &(list->head);
		//��ʼ��Ҫ��������ݽڵ�
		newNode->next = NULL;
		((myData*)newNode)->num = val;		
		//����
		newNode->next = pCurrent->next;
		pCurrent->next = newNode;
		//����size
		list->size++;
	}
	//��ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
	void addAtTail(LinkList* list, ListNode* newNode, int val) {
		if (list == NULL) return;
		//����ָ�����
		ListNode* pCurrent = &(list->head);
		//�ƶ������һ���ڵ��λ��
		for (int i = 0; i < list->size; i++) {
			pCurrent = pCurrent->next;
		}
		//��ʼ��Ҫ��������ݽڵ�
		newNode->next = NULL;
		((myData*)newNode)->num = val;
		//����
		newNode->next = pCurrent->next;
		pCurrent->next = newNode;
		
		//����size
		list->size++;
	}

	//addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪval�Ľڵ㡣
	//��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣
	//���indexС��0������ͷ������ڵ�
	void addAtIndex(LinkList* list, int index, ListNode* newNode, int val) {
		if (list == NULL) return;
		if (index < 0) index = 0;
		if (index > list->size)	return;
		//����ָ�����
		ListNode* pCurrent = &(list->head);
		//�ƶ���index��ǰһ��λ�ã�index��0��ʼ������
		for (int i = 0; i < index; i++) {
			pCurrent = pCurrent->next;
		}
		//��ʼ��Ҫ����Ľڵ�
		newNode->next = NULL;
		((myData*)newNode)->num = val;
		//����
		newNode->next = pCurrent->next;
		pCurrent->next = newNode;
		//����size
		list->size++;
	}
	//deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
	void deleteAtIndex(LinkList* list, int index) {
		if (list == NULL) return;
		if (index >= 0 && index < list->size) {
			//����ָ�����
			ListNode* pCurrent = &(list->head);
			//�ƶ���indexǰһ��Ԫ��
			for (int i = 0; i < index; i++) {
				pCurrent = pCurrent->next;
			}
			//ɾ��
			pCurrent->next = pCurrent->next->next;
			//����size
			list->size--;
		}
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
				list->size--;
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
	list->size = 7;
	//s.Remove_ListNode(list, val);
	myData newNode1, newNode2;
	//s.addAtHead(list, (ListNode*)&newNode1, 10);
	//s.addAtTail(list, (ListNode*)&newNode2, 10);
	s.addAtIndex(list, 2, (ListNode*)&newNode1, 20);
	s.addAtIndex(list, list->size, (ListNode*)&newNode2, 100);
	s.deleteAtIndex(list, 8);
	//����ָ�����
	ListNode* pCurrent = list->head.next;
	while (pCurrent != NULL) {
		cout << ((myData*)pCurrent)->num << " ";
		pCurrent = pCurrent->next;
	}
	cout << endl;
	
	//cout << s.get(list, 2) << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}
#endif
