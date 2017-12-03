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
	cout << left << setw(31) <<setfill(' ')<< "打印链表" << right << "1\n";
	cout << left << setw(31) << setfill(' ') << "获取长度" << right << "2\n";
	cout << left << setw(31) << setfill(' ') << "插入元素" << right << "3\n";
	cout << left << setw(31) << setfill(' ') << "获取元素地址" << right << "4\n";
	cout << left << setw(31) << setfill(' ') << "按值查找" << right << "5\n";
	cout << left << setw(31) << setfill(' ') << "删除元素" << right << "6\n";
	cout << left << setw(31) << setfill(' ') << "倒置" << right << "7\n";
	cout << left << setw(31) << setfill(' ') << "退出" << right << "q\n";
	cout << setw(32) << setfill('-') << "\n\n";
	cout << "你的输入为： ";
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
			cout << "打印结果为：";
			A.PrintList();
			cout << endl;
		}
		else if (ch == '2')
		{
			system("cls");
			cout << "链表的长度为" << A.GetLength() << "\n\n";
		}

		else if (ch == '3')
		{
			system("cls");
			int a, b;
			cout << "请输入插入的位置:";
			cin >> a;
			cout << "请输入插入的值：";
			cin >> b;
			A.Insert(a, b);
			cout << "插入成功，当前列表为：\n";
			A.PrintList();
			cout << endl;
		}
		else if (ch == '4')
		{
			system("cls");
			cout << "请输想获取地址元素的序号:";
			int i;
			cin >> i;
			cout << A.Get(i) << endl << endl;
		}
		else if (ch == '5')
		{
			system("cls");
			cout << "请输入要查找的值: ";
			int i;
			cin >> i;
			cout << A.Locate(i) << endl << endl;
		}
		else if (ch == '6')
		{
			system("cls");
			cout << "请输入要删除元素的位置： ";
			int i;
			cin >> i;
			A.Delete(i);
			cout << "删除成功，当前列表为：\n";
			A.PrintList();
			cout << endl;
		}
		else if (ch == '7')
		{
			system("cls");
			A.Reverse();
			cout << "倒置后的结果为： \n";
			A.PrintList();
			cout << endl;
		}
		else
		{
			system("cls");
			cout << "输入错误，请从新输入\n";
			continue;
		}
	}
}

int main(void)
{
	cout << "test_program\n";
	cout << setw(31) << setfill('-') << "\n\n";
	cout << "请输入整形数组元素个数：";
	int n;
	cin >> n;
	int*a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "请输入第" << i + 1 << "个数组： ";
		cin >> a[i];
	}
	LinkList<int> TestLink(a, n);
	delete[]a;
	menu(TestLink);
	system("cls");
	cout << "\n测试结束\n";
	Sleep(1000);
}
