
#include <iostream>
using namespace std;
#include"header.h"


int main(){
	CycleLinkList L;
	InitList(L);
	int n, m;
	ElemType e;
	cout << "《约瑟夫环》" << endl << endl;

	cout << "请输入人数: ";
	cin >> n;
	cout << endl << "请输入第1人密码: ";
	cin >> e.password;
	e.location = 1;
	ListInsert(L, 1, e);
	for (int i = 2; i <= n; i++)
	{
		cout << "请输入第" << i << "人密码: ";
		cin >> e.password;
		e.location = i;
		ListAppend(L, e);
	}
	cout << endl << "当前循环双向链表中的数据元素依序为：" << endl << endl;
	TraverseDList(L, Cout);

	cout << endl << "请输入初始密码: ";
	cin >> m;
	Ysfring(L, n, m);
	cout << endl << endl;

	system("pause");
	return 0;
}

