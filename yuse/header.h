#ifndef _DULINKLIST_
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

#define _DULINKLIST_

struct ElemType {
	int location;
	int password;
};
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLlinkList;

struct CycleLinkList {
	struct DuLNode* head;
	struct DuLNode* tail;
};

void InitList(CycleLinkList&L){
	L.head = L.tail = NULL;
}

void ClearList(CycleLinkList&L) {
	if (L.head) {
		DuLlinkList p, q;
		p = L.head;
		while (p != L.tail) {
			q = p;
			p = p->next;
			free(q);
		}
		free(L.tail);
		L.head = L.tail = NULL;
	}
}

void DestoryList(CycleLinkList&L) {
	ClearList(L);
}

int ListLength(CycleLinkList&L) {
	if (!L.head) return 0;
	int i = 1;
	DuLlinkList p = L.head;
	while (p != L.tail) {
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(CycleLinkList& L,int i, ElemType& e) {
	int l = ListLength(L);
	if (i < 1 || !L.head||i>l) return 0;
	DuLlinkList p = L.head;
	int j = 1;
	if (i <= l / 2) {
		while (p && j < i) {
			p = p->next;
			j++;
		}
	}
	else {
		i = l - i + 2;
		while (p && j < i) {
			p = p->prior;
			j++;
		}
	}
	e = p->data;
	return 1;
}

int ListInsert(CycleLinkList& L, int i, ElemType e) {
	int l = ListLength(L);
	if(i<1|| i>l+1) return 0;
	DuLlinkList p ,q;
	if (i == 1) {
		q = (DuLlinkList)malloc(sizeof(DuLNode));
		q->data = e;
		if (!L.head) {
			L.head = L.tail = q;
			q->prior = q;
			q->next = q;
		}
		else{
			q->prior = L.tail;
			q->next = L.head;
			L.head->prior= q;
			L.tail->next = q;
			L.head = q;
		}
	}
	else {
		if (i <= l / 2) {
			if (!L.head) return 0;
			p = L.head;
			int j = 1;
			while (j < i - 1) {
				p = p->next;
				j++;
			}
		}
		else {
			i = l - i + 2;
			if (!L.head) return 0;
			p = L.head;
			int j = 0;
			while (j < i ) {
				p = p->prior;
				j++;
			}
		}
		q = (DuLlinkList)malloc(sizeof(DuLNode));
		q->data = e;
		q->prior = p;
		q->next = p->next;
		p->next->prior = q;
		p->next = q;
		if (p == L.tail)
			L.tail = q;

	}
	return 1;
}
void ListAppend(CycleLinkList& L, ElemType e) {
	DuLlinkList s;
	s = (DuLlinkList)malloc(sizeof(DuLNode));
	s->data = e;
	s->next = L.tail->next;
	s->prior = L.tail;
	L.tail->next->prior = s;
	L.tail->next = s;
	L.tail = s;
}
int ListDelete(CycleLinkList& L, int i) {
	int l = ListLength(L);
	if (i<1 || i>l) return 0;
	DuLlinkList p , q;

	if (i == 1) {
		p = L.head;
		if (L.head == L.tail)
			L.head = L.tail = NULL;

		else {
			L.tail->next = L.head->next;
			L.head->next->prior = L.tail;
			L.head = L.head->next;
		}
		free(p);
	}
	else {
		if (i <= l / 2) {
			p = L.head;
			int j = 1;
			while (j < i - 1) {
				p = p->next;
				j++;
			}
		}
		else {
			i = l - i + 2;
			p = L.head;
			int j = 0;
			while (j < i) {
				p = p->prior;
				j++;
			}
		}
		q = p->next;
		p->next = q->next;
		q->next->prior = p;
		if (q == L.tail)
			L.tail = p;
		free(q);
		return 1;
	}
	return 1;
}

int TraverseDList(CycleLinkList& L, void (*visit)(ElemType&e)) {
	if (!L.head) return 0;
	DuLlinkList p = L.head;
	if(p){
		while (p != L.tail) {
			visit(p->data);
			p = p->next;
		}
		visit(p->data);
	}
	return 1;
}

int LocateElem(CycleLinkList& L, ElemType e,
	bool(*Compare)(ElemType& e1, ElemType& e2)){
	if (!L.head) return 0;
	int i = 1;
	DuLlinkList p =L.head;
	while (p != L.tail && !Compare(p->data, e)) {
		i++;
		p = p->next;
	}
	if (Compare(p->data, e))
		return i;
	else
		return 0;
}

bool Equal(ElemType& a, ElemType& b){
	if (a.location == b.location && a.password == b.password)
		return true;
	else
		return false;
}

void Cout(ElemType& e){
	cout << " 位置: " << e.location << " 密码: " << e.password << endl;
}

void Ysfring(CycleLinkList& L, int n, int m) {
	DuLlinkList p = L.tail,q;

	int k = n;
	while (n > 0) {
		m = m % n;
		if (m == 0)
			m = n;
		if (m<=n/2) { //指针顺时针移动
			for (int i = 1; i < m; i++) {
				p = p->next;
			}
		}
		else {//指针逆时针移动
			m = n - m + 2;
			for (int i = 1; i <m; i++) {
				p = p->prior;
			}
		}
		q = p->next;
		p->next = q->next;
		q->next->prior = p;
		cout << endl << "第" << k - n + 1 << "个出列的位序是: " << q->data.location;
		m = q->data.password;
		free(q);
		n--;
	}
	L.head = L.tail = NULL;
}
#endif
