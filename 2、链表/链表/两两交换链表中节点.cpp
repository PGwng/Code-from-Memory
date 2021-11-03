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

class swapSolution {
public:
	void swapPairs(LinkList* list) {
		//����ָ�����
		ListNode* pCurrent = &(list->head);
		while (pCurrent->next != NULL && pCurrent->next->next != NULL) {	//��һ���ڵ�͵ڶ����ڵ㶼��Ϊ��
			ListNode* temp1 = pCurrent->next;		//�����һ�����ݽڵ�
			ListNode* temp3 = pCurrent->next->next->next;	//������������ݽڵ�

			pCurrent->next = pCurrent->next->next;		//����һ
			pCurrent->next->next = temp1;				//�����
			pCurrent->next->next->next = temp3;			//������

			//pCurrent�ƶ���λ��׼����һ�ֽ���
			pCurrent = pCurrent->next->next;
		}
	}
};

void test01() {

	Solution s;
	LinkList* list = s.Init_LinkList();
	myData d1, d2, d3, d4, d5, d6;
	s.addAtTail(list, (ListNode*)&d1, 1);
	s.addAtTail(list, (ListNode*)&d2, 2);
	s.addAtTail(list, (ListNode*)&d3, 3);
	s.addAtTail(list, (ListNode*)&d4, 4);
	s.addAtTail(list, (ListNode*)&d5, 5);
	s.addAtTail(list, (ListNode*)&d6, 6);

	swapSolution swaps;
	swaps.swapPairs(list);

	//��ӡ 
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
