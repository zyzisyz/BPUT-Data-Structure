//信通院 2016211111班
//学号 2016210318
//小班序号 20
//张阳

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
		cout << "·请输入第" << i + 1 << "项的系数： ";
		cin >> a;
		cout << "·请输入第" << i + 1 << "项的指数： ";
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
		cout << right << setw(15) << setfill(' ') << "菜单" << endl;
		cout << right << setw(32) << setfill('-') << "\n\n";
		cout << left << setw(30) << setfill(' ') << "·测试多项式求和请按";
		cout<<"1\n";
		cout << left << setw(30) << setfill(' ') << "·求导请按";
		cout<<"2\n";
		cout << left << setw(30) << setfill(' ') << "·显示当前多项式";
		cout<<"3\n";
		cout << left << setw(30) << setfill(' ') << "·退出请输入";
		cout<<"q\n";
		cout << "\n请输入： ";
		cin >> ch;
		if (ch == '1')
		{
			system("cls");
			cout << "·请输入要加入的多项式项数目: ";
			int n;
			cin >> n;
			Polynomial B(MakeElement(n), n);
			A.Add(B);
			cout << endl << "·加入多项式成功，当前多项式为：\n\n";
			A.PrintFun();
			cout << "\n\n";
		}
		else if (ch == '2')
		{
			system("cls");
			cout << "\n";
			cout << "·导数为：\n";
			A.GetDerivative();
			cout << "\n\n";
		}
		else if (ch == '3')
		{
			system("cls");
			cout << endl<<"·当前多项式为\n";
			A.PrintFun();
			cout << endl;
		}
	} while (ch == '1' || ch == '2' || ch == '3');

}

int main(void)
{
	cout << "信通院2016211111班 2016210318 张阳\n\n\n"
		<<"请按照指数的升序输入"<<endl
		<< "欢迎使用 Polynomial 测试函数" << endl;
	
	cout << setw(30) << setfill('-') << "\n\n";
	cout << "·请输入项的数目： ";
	int n;
	cin >> n;
	Polynomial A(MakeElement(n), n);
	cout << "\n·创建多项式成功，当前多项式为：\n\n";
	A.PrintFun();
	cout << "\n\n1.5s后进入菜单";
	Sleep(1500);
	system("cls");
	menu(A);
	system("cls");
	cout << "再见" << endl;
	Sleep(1500);
}