
#include <iostream>
using namespace std;
#include"header.h"


int main(){
	CycleLinkList L;
	InitList(L);
	int n, m;
	ElemType e;
	cout << "��Լɪ�򻷡�" << endl << endl;

	cout << "����������: ";
	cin >> n;
	cout << endl << "�������1������: ";
	cin >> e.password;
	e.location = 1;
	ListInsert(L, 1, e);
	for (int i = 2; i <= n; i++)
	{
		cout << "�������" << i << "������: ";
		cin >> e.password;
		e.location = i;
		ListAppend(L, e);
	}
	cout << endl << "��ǰѭ��˫�������е�����Ԫ������Ϊ��" << endl << endl;
	TraverseDList(L, Cout);

	cout << endl << "�������ʼ����: ";
	cin >> m;
	Ysfring(L, n, m);
	cout << endl << endl;

	system("pause");
	return 0;
}

