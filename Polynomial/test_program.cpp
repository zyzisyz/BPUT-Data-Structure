//��ͨԺ 2016211111��
//ѧ�� 2016210318
//С����� 20
//����

#include"LinkList.h"
#include"Polynomial.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;



element* MakeElement(int n)
{
	element* E = new element[n];
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cout << "���������" << i + 1 << "���ϵ���� ";
		cin >> a;
		cout << "���������" << i + 1 << "���ָ���� ";
		cin >> b;
		cout << "\n\n";
		E[i] = element(a, b);
	}
	return E;
}

void menu(Polynomial&A)
{
	char ch;
	do {
		cout << right << setw(15) << setfill(' ') << "�˵�" << endl;
		cout << right << setw(32) << setfill('-') << "\n\n";
		cout << left << setw(30) << setfill(' ') << "�����Զ���ʽ����밴";
		cout<<"1\n";
		cout << left << setw(30) << setfill(' ') << "�����밴";
		cout<<"2\n";
		cout << left << setw(30) << setfill(' ') << "����ʾ��ǰ����ʽ";
		cout<<"3\n";
		cout << left << setw(30) << setfill(' ') << "���˳�������";
		cout<<"q\n";
		cout << "\n�����룺 ";
		cin >> ch;
		if (ch == '1')
		{
			system("cls");
			cout << "��������Ҫ����Ķ���ʽ����Ŀ: ";
			int n;
			cin >> n;
			Polynomial B(MakeElement(n), n);
			A.Add(B);
			cout << endl << "���������ʽ�ɹ�����ǰ����ʽΪ��\n\n";
			A.PrintFun();
			cout << "\n\n";
		}
		else if (ch == '2')
		{
			system("cls");
			cout << "\n";
			cout << "������Ϊ��\n";
			A.GetDerivative();
			cout << "\n\n";
		}
		else if (ch == '3')
		{
			system("cls");
			cout << endl<<"����ǰ����ʽΪ\n";
			A.PrintFun();
			cout << endl;
		}
	} while (ch == '1' || ch == '2' || ch == '3');

}

int main(void)
{
	cout << "��ͨԺ2016211111�� 2016210318 ����\n\n\n"
		<<"�밴��ָ������������"<<endl
		<< "��ӭʹ�� Polynomial ���Ժ���" << endl;
	
	cout << setw(30) << setfill('-') << "\n\n";
	cout << "�������������Ŀ�� ";
	int n;
	cin >> n;
	Polynomial A(MakeElement(n), n);
	cout << "\n����������ʽ�ɹ�����ǰ����ʽΪ��\n\n";
	A.PrintFun();
	cout << "\n\n1.5s�����˵�";
	Sleep(1500);
	system("cls");
	menu(A);
	system("cls");
	cout << "�ټ�" << endl;
	Sleep(1500);
}