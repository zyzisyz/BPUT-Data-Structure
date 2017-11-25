#include"LinkList.h"
#include<cmath>

//����������ṹ
struct element
{
	double coef;										//ϵ��
	int exp;											//ָ��
	element(double c = 0, int e = 0):coef(c),exp(e){}	//���캯��
};


//����Polynomial��(LinkList������)
class Polynomial:public LinkList<element>
{
public:
	Polynomial(element data[], int n) :LinkList(data, n){}//���캯��
	void Add(Polynomial &B);								//��ͺ���
	void GetDerivative();								//����
	void PrintFun();
};

//һԪ����ʽ����ͺ���
void Polynomial::Add(Polynomial &B)
{
	Node<element>*p_prior = GetFirst();					//���ͷָ��				p_prior�ǹ���ָ��pǰ���ָ��
	Node<element>*p = p_prior->next;					//��ʼ������ָ��			p�ǹ���ָ��
	Node<element>*q = B.GetFirst()->next;				//��ʼ��B����Ĺ���ָ��		q��B�Ĺ���ָ��


	while (p&&q)										//�������p q���Ƿǿ�ָ�룬��ִ���������
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
			if (fabs(p->data.coef) < 1e-7)				//���ϵ���ľ���ֵС��1e-7���������Ϊϵ��Ϊ��
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

//�����ݰ�������˳�����
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

//��һԪ����ʽ�ĵ���
void Polynomial::GetDerivative()
{
	Node<element>*p_prior = GetFirst();
	Node<element>*p = p_prior->next;
	while (p)
	{
		if (p->data.exp == 0)				//ָ��Ϊ0���󵼺�Ϊ0��ɾ�����
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
	PrintFun();								//�󵼺�����󵼽��
}