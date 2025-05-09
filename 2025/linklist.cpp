#include "functions.h"
#include <iostream>
#include <list>

using namespace std;

REGISTER_FUNCTION(linklist) {
	std::list<int> myList = {1, 2, 3, 4, 5};
	// insert {0,1,2,3,4,5,6}
	myList.push_front(6);
	myList.push_back(0);
	// move {0,1,2,99,3,4,5,6}
	auto it = myList.begin();
	advance(it, 2);  // 迭代器移动到第三个位置
	myList.insert(it, 99);
	// delete {0,2,99,3,4,5,6}
	myList.erase(next(myList.begin())); // 删除第二个元素
	// pop {2,99,3,4,5}
	myList.pop_back();
	myList.pop_front();
	// print linklist
	print_it(myList);
}

// ----------------------------- 203.移除链表元素 --------------------
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_listnode(ListNode *head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}

ListNode* removeElements(ListNode* head, int val) {
	while (head) {
		if (head->val == val)
			head = head->next;
		else
			break;
	}
	ListNode *p = head;
	while(p) {
		ListNode *n = p->next;
		while (n && n->val == val) {
			n = n->next;
		} // find point of (p->next->val != val)
		p->next = n;
		p = p->next;
	}
	return head;
}

REGISTER_FUNCTION(func203) {
//输入：head = [1,2,6,3,4,5,6], val = 6
//输出：[1,2,3,4,5]
	ListNode *head = new ListNode(6);
	ListNode *a1 = new ListNode(2);
	ListNode *a2 = new ListNode(6);
	ListNode *a3 = new ListNode(6);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	ListNode *a6 = new ListNode(6);
	head->next = a1;
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;
	a6->next = nullptr;

	ListNode *p = removeElements(head, 6);
	print_listnode(p);
}

// ----------------------- 206. 反转链表 -----------------------------
ListNode* reverseList(ListNode* head) {
	ListNode *p0, *p1, *p2;
	// 0或者1个结点
	if (!head || !head->next)
		return head;
	p0 = head;
	p1 = head->next;
	// 2个结点
	if (!head->next->next) {
		p0->next = nullptr;
		p1->next = p0;
		return p1;
	}
	p2 = head->next->next;
	p0->next = nullptr;
	// 3个以上结点
	while (p2) {
		p2 =  p1->next;
		p1->next = p0;
		p0 = p1;
		p1 = p2;
		p2 = p2->next;
	}
	p1->next = p0; //处理最后一个节点
	return p1;
}

ListNode* reverseList_2(ListNode* head) {
	ListNode *p0, *p1, *p2;
	p0 = head;
	p1 = nullptr;
	while (p0) {
		p2 = p0->next;
		p0->next = p1;
		p1 = p0;
		p0 = p2;
	}
	return p1;
}

REGISTER_FUNCTION(func206) {
	ListNode *head = new ListNode(6);
	ListNode *a1 = new ListNode(2);
	ListNode *a2 = new ListNode(6);
	ListNode *a3 = new ListNode(6);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	ListNode *a6 = new ListNode(6);
	head->next = a1;
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;
	a6->next = nullptr;

	ListNode *p = reverseList_2(head);
	print_listnode(p);
}

// -------------- 24. 两两交换链表中的节点 --------------------
ListNode* swapPairs(ListNode* head) {
	ListNode *pre, *p0, *p1, *res_head;
	if (!head || !head->next)
		return head;

	// 虚拟头结点
	pre = new ListNode();
	pre->next = head;
	p0 = pre->next;
	p1 = p0->next;
	res_head = pre;

	while (p1) {
		pre->next = p1;
		p0->next = p1->next;
		p1->next = p0;
		if (!p0->next || !p0->next->next)
			break;
		// update pre,p0,p1 nodes
		pre = p0;
		p0 = pre->next;
		p1 = p0->next;
	}

	return res_head->next;
}

REGISTER_FUNCTION(func24) {
	ListNode *head = new ListNode(6);
	ListNode *a1 = new ListNode(2);
	ListNode *a2 = new ListNode(6);
	ListNode *a3 = new ListNode(6);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	ListNode *a6 = new ListNode(6);
	head->next = a1;
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;

	ListNode *p = swapPairs(head);
	print_listnode(p);
}

// ------------------- 19. 删除链表的倒数第 N 个结点 ---------------
ListNode* removeNthFromEnd(ListNode* head, int n) {
	int size = 0;
	ListNode *p = head, *res_head = head;
	while (head) {
		head = head->next;
		size++;
	}
	if (size <= 1)
		return nullptr;
	if (size - n - 1 < 0) {
		return res_head->next;
	}

	for (int i = 0; i < size - n - 1; i++) {
		p = p->next;
	}
	p->next = p->next->next;
	return res_head;
}


REGISTER_FUNCTION(func19) {
	ListNode *head = new ListNode(6);
	ListNode *a1 = new ListNode(2);
	ListNode *a2 = new ListNode(6);
	ListNode *a3 = new ListNode(6);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	ListNode *a6 = new ListNode(6);
	head->next = a1;
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;

	ListNode *p = removeNthFromEnd(head, 2);
	print_listnode(p);
}

// --------------------- 142. 环形链表 II ----------
ListNode* detectCycle(ListNode* head) {
	ListNode *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			ListNode *index1 = head, *index2 = fast;
			while (index1 != index2) {
				index1 = index1->next;
				index2 = index2->next;
			}
			return index1;
		}
	}
	return nullptr;

}
REGISTER_FUNCTION(func142) {
	ListNode *head = new ListNode(6);
	ListNode *a1 = new ListNode(2);
	ListNode *a2 = new ListNode(6);
	ListNode *a3 = new ListNode(6);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	ListNode *a6 = new ListNode(6);
	head->next = a1;
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;
	a6->next = a4;

	ListNode *p = detectCycle(head);
	print_listnode(p);
}
