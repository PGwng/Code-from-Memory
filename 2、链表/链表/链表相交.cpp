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
//�ж������Ƿ��ཻ�����ؽ���
class IntersectionSolution {
public:
	ListNode* getIntersectionNode(LinkList* listA, LinkList* listB) {
		//����ָ�����
		ListNode* pCurrentA = listA->head.next;
		ListNode* pCurrentB = listB->head.next;

		int lenA = listA->size;
		int lenB = listB->size;

		//��pCurrentAָ�������ĵ�һ��Ԫ�أ�lenAΪ�䳤��
		if (lenB > lenA) {
			swap(lenA, lenB);
			swap(pCurrentA, pCurrentB);
		}
		//�󳤶Ȳ�
		int gap = lenA - lenB;
		//��pCurrentA��pCurrentB��ͬһ����ϣ�ĩβλ�ö��룩
		while (gap--) {
			pCurrentA = pCurrentA->next;
		}
		//����pCurrentA��pCurrentB��������ֱͬ�ӷ���
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

//��ӡ����
void printLinkList(LinkList* list) {
	//����ָ�����
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
	if (intersection == NULL) cout << "�޽���" << endl;
	else cout << "����Ԫ��ֵΪ" << ((myData*)intersection)->num << endl;

	//��ӡ 
	//printLinkList(listA);
}

int main() {
	test01();
	system("pause");
	return 0;
}
#endif
