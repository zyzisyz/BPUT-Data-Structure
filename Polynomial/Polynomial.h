#include"LinkList.h"
#include<cmath>

//定义数据域结构
struct element
{
	double coef;										//系数
	int exp;											//指数
	element(double c = 0, int e = 0):coef(c),exp(e){}	//构造函数
};


//定义Polynomial类(LinkList的派生)
class Polynomial:public LinkList<element>
{
public:
	Polynomial(element data[], int n) :LinkList(data, n){}//构造函数
	void Add(Polynomial &B);								//求和函数
	void GetDerivative();								//求导数
	void PrintFun();
};

//一元多项式的求和函数
void Polynomial::Add(Polynomial &B)
{
	Node<element>*p_prior = GetFirst();					//获得头指针				p_prior是工作指针p前面的指针
	Node<element>*p = p_prior->next;					//初始化工作指针			p是工作指针
	Node<element>*q = B.GetFirst()->next;				//初始化B链表的工作指针		q是B的工作指针


	while (p&&q)										//如果满足p q都是非空指针，则执行以下语句
	{
		if (p->data.exp < q->data.exp)
		{
			p_prior = p;
			p = p->next;
		}
		else if (p->data.exp > q->data.exp)
		{
			p_prior->next = q;
			p_prior = q;
			q = q->next;
			p_prior->next = p;
		}
		else
		{
			p->data.coef += q->data.coef;
			if (fabs(p->data.coef) < 1e-7)				//如果系数的绝对值小于1e-7，则可以认为系数为零
			{
				p_prior->next = p->next;
				delete p;
				p = p_prior->next;
			}
			else
			{
				p_prior = p;
				p = p_prior->next;
			}
			Node<element>*temp = q;
			q = q->next;
			delete temp;
		}
	}
	if (q)
		p_prior->next = q;
	B.GetFirst()->next = NULL;

}

//将数据按照链表顺序输出
void Polynomial::PrintFun()
{
	Node<element>*p = GetFirst()->next;
	while (p->next)
	{
		cout << p->data.coef << "*x^" << p->data.exp << " + ";
		p = p->next;
	}
	cout << p->data.coef << "*x^" << p->data.exp << endl;
}

//求一元多项式的倒数
void Polynomial::GetDerivative()
{
	Node<element>*p_prior = GetFirst();
	Node<element>*p = p_prior->next;
	while (p)
	{
		if (p->data.exp == 0)				//指数为0，求导后为0，删除结点
		{
			p = p->next;
			delete p_prior->next;
			p_prior->next = p;
		}
		else
		{
			p->data.coef *= p->data.exp;
			p->data.exp -= 1;
			p_prior = p;
			p = p->next;
		}
	}
	PrintFun();								//求导后输出求导结果
}