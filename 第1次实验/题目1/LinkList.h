#pragma once
#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>*next;
};


template<class T>
class LinkList
{
private:
	Node<T>*front;
public:
	LinkList()
	{
		front = new Node<T>;
		front->next = NULL;
	}
	LinkList(T a[], int n);			
	LinkList(LinkList& B);			//���ƹ��캯��
	void PrintList();
	int GetLength();
	Node<T>*Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);
	void Reverse();				//��������
	~LinkList();
};

//ͷ�巨���캯��
template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	front = new Node<T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T>*s = new Node<T>;     //�����½��
		s->data = a[i];              //��a[i]д�뵽�½ڵ��������
		s->next = front->next;       //�޸��½ڵ��ָ����
		front->next = s;             //�޸�ͷ���ĵ�ָ���򣬽��½����뵽������
	}
}



/*
//β�巨
template<class T>
LinkList<T>::(T a[], int a)
{
front = new Node<T>;
Node<T>*r = front;
for (int i = 0; i < n; ++i)
{
Node<T>*s = new Node<T>;   //�����½��
s->data = a[i];            //��a[i]д�������������
r->next = s;               //���½����ӵ���������
r = s;                     //�޸�βָ��
}
r->next = NUll;                 //�ն˽���ָ��������Ϊ��
}
*/

template<class T>
void LinkList<T>::PrintList()
{
	Node<T>*p = front->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


template<class T>
LinkList<T>::LinkList(LinkList& B)
{
	Node<T>*p = B.Get(1);
	front = new Node <T>;
	Node<T> * r = front;

	while (p)
	{
		Node<T>* s = new Node<T>;
		s->data = p->data;
		p = p->next;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

template<class T>
int LinkList<T>::GetLength()
{
	Node<T>*p = front->next;
	int n = 0;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}


template<class T>
Node<T>* LinkList<T>::Get(int i)
{
	Node<T> * p = front->next;
	int j = 1;
	while (p&&j != i)
	{
		p = p->next;
		j++;
	}
	return p;                 //���ҵ���i��Ԫ�ط��ص�ַ��û�ҵ�����0
}

template<class T>
int LinkList<T>::Locate(T x)
{
	Node<T>*p = front->next;
	int j = 1;
	while (p)
	{
		if (p->data == x)
			return j;
		p = p->next;
		j++;
	}
	return -1;
}


template<class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T>*p = front;             //��ʼ������ָ��p
	if (i != 1)
		p = Get(i - 1);            //�������ڵ�һ��Ԫ�ز��룬�ҵ���i-1��Ԫ�ص�λ��
	if (p)
	{
		Node<T>*s = new Node<T>;   //�����µĽ��
		s->data = x;               //�µĽ��������ֵ
		s->next = p->next;         //�½���ָ����ָ��ԭ���ĵ�i��Ԫ��
		p->next = s;               //i-1������ָ����ָ���½��
	}
	else throw"����λ�ô���";
}


template<class T>
T LinkList<T>::Delete(int i)
{
	Node<T>*p = front;                     //��ʼ������ָ��
	if (i != 1)
		p = Get(i - 1);                    //�õ�Ҫɾ�����iǰ���һ�����λ��
	if (!p && !p->next) throw"λ�ô���";
	Node<T>*q = p->next;                   //q��Ҫɾ���Ľ��
	p->next = q->next;                     //i-1���ָ��i+1���
	T x = q->data;
	delete q;
	return x;
}

template<class T>
LinkList<T>::~LinkList()
{
	Node<T>*p = front;   //��ʼ������ָ��p
	while (p)            //���ָ��p�ǿ�ָ�������ѭ��
	{
		front = p;       //front���Ҫ�ͷŽ��ĵ�ַ
		p = p->next;    //�ƶ�����ָ��
		delete front;    //�ͷ�front��ָ��Ŀռ䣨��ʱfront��ʱ���ң�
	}
}


template<class T>
void LinkList<T>::Reverse()
{
	Node<T>*p = front->next;
	Node<T>*q;
	front->next = NULL;
	while (p)
	{
		q = p->next;
		p->next = front->next;
		front->next = p;
		p = q;
	}
}