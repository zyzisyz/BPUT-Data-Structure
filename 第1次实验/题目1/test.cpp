#include"LinkList.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;


bool PrintOption()
{
	Sleep(1000);
	cout << "\nmenu" << endl;
	cout << setw(32) << setfill('-') << "\n\n";
	cout << left << setw(31) <<setfill(' ')<< "��ӡ����" << right << "1\n";
	cout << left << setw(31) << setfill(' ') << "��ȡ����" << right << "2\n";
	cout << left << setw(31) << setfill(' ') << "����Ԫ��" << right << "3\n";
	cout << left << setw(31) << setfill(' ') << "��ȡԪ�ص�ַ" << right << "4\n";
	cout << left << setw(31) << setfill(' ') << "��ֵ����" << right << "5\n";
	cout << left << setw(31) << setfill(' ') << "ɾ��Ԫ��" << right << "6\n";
	cout << left << setw(31) << setfill(' ') << "����" << right << "7\n";
	cout << left << setw(31) << setfill(' ') << "�˳�" << right << "q\n";
	cout << setw(32) << setfill('-') << "\n\n";
	cout << "�������Ϊ�� ";
	return true;
}


void menu(LinkList<int> &A)
{
	char ch;
	while (PrintOption())
	{
		cin >> ch;
		if (ch == 'q')
		{
			break;
		}

		else if (ch == '1')
		{
			system("cls");
			cout << "��ӡ���Ϊ��";
			A.PrintList();
			cout << endl;
		}
		else if (ch == '2')
		{
			system("cls");
			cout << "����ĳ���Ϊ" << A.GetLength() << "\n\n";
		}

		else if (ch == '3')
		{
			system("cls");
			int a, b;
			cout << "����������λ��:";
			cin >> a;
			cout << "����������ֵ��";
			cin >> b;
			A.Insert(a, b);
			cout << "����ɹ�����ǰ�б�Ϊ��\n";
			A.PrintList();
			cout << endl;
		}
		else if (ch == '4')
		{
			system("cls");
			cout << "�������ȡ��ַԪ�ص����:";
			int i;
			cin >> i;
			cout << A.Get(i) << endl << endl;
		}
		else if (ch == '5')
		{
			system("cls");
			cout << "������Ҫ���ҵ�ֵ: ";
			int i;
			cin >> i;
			cout << A.Locate(i) << endl << endl;
		}
		else if (ch == '6')
		{
			system("cls");
			cout << "������Ҫɾ��Ԫ�ص�λ�ã� ";
			int i;
			cin >> i;
			A.Delete(i);
			cout << "ɾ���ɹ�����ǰ�б�Ϊ��\n";
			A.PrintList();
			cout << endl;
		}
		else if (ch == '7')
		{
			system("cls");
			A.Reverse();
			cout << "���ú�Ľ��Ϊ�� \n";
			A.PrintList();
			cout << endl;
		}
		else
		{
			system("cls");
			cout << "����������������\n";
			continue;
		}
	}
}

int main(void)
{
	cout << "test_program\n";
	cout << setw(31) << setfill('-') << "\n\n";
	cout << "��������������Ԫ�ظ�����";
	int n;
	cin >> n;
	int*a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "�������" << i + 1 << "�����飺 ";
		cin >> a[i];
	}
	LinkList<int> TestLink(a, n);
	delete[]a;
	menu(TestLink);
	system("cls");
	cout << "\n���Խ���\n";
	Sleep(1000);
}
