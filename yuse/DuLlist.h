#ifndef _DULINKLIST_
#define _DULINKLIST_
#define INFEASIBLE 0;
#define ERROR 0;
#define OK 1;
struct ElemType {
	int location;
	int password;
};
typedef struct DuLNode {//双向循环链表结点结构
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLlinkList;

struct CycleLinkList {//不带头结点的双向循环链表
	struct DuLNode* head;
	struct DuLNode* tail;
};

void InitList(CycleLinkList&L){//初始化
	L.head = L.tail = NULL;
}

void ClearList(CycleLinkList&L) {//清空双向循环链表
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

void DestoryList(CycleLinkList&L) {//摧毁双向循环链表
	ClearList(L);
}

int ListLength(CycleLinkList&L) {//获取双向链表长度
	if (!L.head) return INFEASIBLE;
	int k = 1;
	DuLlinkList p = L.head;
	while (p != L.tail) {
		k++;
		p = p->next;
	}
	return k;
}

int GetElem(CycleLinkList& L,int i, ElemType& e) {//取得元素
	int l = ListLength(L);
	if (i < 1 || !L.head||i>l) return ERROR;
	DuLlinkList p = L.head;
	int j = 1;
	if (i <= l / 2) {//顺时针
		while (p && j < i) {
			p = p->next;
			j++;
		}
	}
	else {//逆时针
		i = l - i + 2;
		while (p && j < i) {
			p = p->prior;
			j++;
		}
	}
	e = p->data;
	return OK;
}

int ListInsert(CycleLinkList& L, int i, ElemType e) {//插入一个结点
	int l = ListLength(L);
	if(i<1|| i>l+1) return ERROR;
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
		if (i <= l / 2) {//顺时针
			if (!L.head) return ERROR;
			p = L.head;
			int j = 1;
			while (j < i - 1) {
				p = p->next;
				j++;
			}
		}
		else {//逆时针
			i = l - i + 2;
			if (!L.head) return ERROR;
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
		return OK;
	}
}
void ListAppend(CycleLinkList& L, ElemType e) {//尾部插入结点 
	DuLlinkList s;
	s = (DuLlinkList)malloc(sizeof(DuLNode));
	s->data = e;
	s->next = L.tail->next;
	s->prior = L.tail;
	L.tail->next->prior = s;
	L.tail->next = s;		
	L.tail = s;
}
int ListDelete(CycleLinkList& L, int i) {//删除结点
	int l = ListLength(L);
	if (i<1 || i>l) return ERROR;
	DuLlinkList p , q;
	ElemType e;
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
		if (i <= l / 2) {//顺时针
			p = L.head;
			int j = 1;
			while (j < i - 1) {
				p = p->next;
				j++;
			}
		}
		else {//逆时针
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
		return OK;
	}
}

int TraverseDList(CycleLinkList& L, void (*visit)(ElemType&e)) {//遍历结点
	if (!L.head) return INFEASIBLE;
	DuLlinkList p = L.head;
	if(p){
		while (p != L.tail) {
			visit(p->data);
			p = p->next;
		}
		visit(p->data);
	}
	return OK;
}

int LocateElem(CycleLinkList& L, ElemType e,
	bool(*Compare)(ElemType& e1, ElemType& e2)){//获得元素位置
	if (!L.head) return ERROR;
	int k = 1;
	DuLlinkList p =L.head;
	while (p != L.tail && !Compare(p->data, e)) {
		k++;
		p = p->next;
	}
	if (Compare(p->data, e))
		return k;
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
#endif