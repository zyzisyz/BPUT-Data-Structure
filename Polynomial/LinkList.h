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
	Node<T>* GetFirst() { return front; }			//获取头节点地址

	LinkList(LinkList& B);							//复制构造函数

	LinkList()										//无参构造函数
	{ 
		front = new Node<T>;
		front->next = NULL; 
	} 
	LinkList(T a[], int n);							//有参构造函数

	~LinkList();									//析构函数

	void PrintList();								//遍历线性表元素

	int GetLength();								//获取线性表长度

	Node <T> * Get(int i);							//获取线性表第i个位置上的元素节点地址

	int Locate(T x);								//查找线性表中值为x的元素，找到后返回其位置

	void Insert(int i, T x);						//在线性表的第i个位置上插入值为x的新元素

	T Delete(int i);								//删除线性表第i个元素，并将该元素返回

	void Reverse();									//倒置链表

};

//头插法构造函数
template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	front = new Node<T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T>*s = new Node<T>;     //创建新结点
		s->data = a[i];              //将a[i]写入到新节点的数据域
		s->next = front->next;       //修改新节点的指针域
		front->next = s;             //修改头结点的的指针域，将新结点插入到链表中
	}
}



/*
//尾插法
template<class T>
LinkList<T>::(T a[], int a)
{
front = new Node<T>;
Node<T>*r = front;
for (int i = 0; i < n; ++i)
{
Node<T>*s = new Node<T>;   //建立新结点
s->data = a[i];            //将a[i]写入结点的数据域中
r->next = s;               //将新结点添加到链表中种
r = s;                     //修改尾指针
}
r->next = NUll;                 //终端结点的指针域设置为空
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
	return p;                 //查找到第i个元素返回地址，没找到返回0
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
	Node<T>*p = front;             //初始化工作指针p
	if (i != 1)
		p = Get(i - 1);            //若不是在第一个元素插入，找到第i-1个元素的位置
	if (p)
	{
		Node<T>*s = new Node<T>;   //建立新的结点
		s->data = x;               //新的结点数据域赋值
		s->next = p->next;         //新结点的指针域指向原来的第i个元素
		p->next = s;               //i-1个结点的指针域指向新结点
	}
	else throw"插入位置错误";
}


template<class T>
T LinkList<T>::Delete(int i)
{
	Node<T>*p = front;                     //初始化工作指针
	if (i != 1)
		p = Get(i - 1);                    //得到要删除结点i前面的一个结点位置
	if (!p && !p->next) throw"位置错误";
	Node<T>*q = p->next;                   //q是要删除的结点
	p->next = q->next;                     //i-1结点指向i+1结点
	T x = q->data;
	delete q;
	return x;
}

template<class T>
LinkList<T>::~LinkList()
{
	Node<T>*p = front;   //初始化工作指针p
	while (p)            //如果指针p是空指针则结束循环
	{
		front = p;       //front存放要释放结点的地址
		p = p->next;    //移动工作指针
		delete front;    //释放front所指向的空间（此时front暂时悬挂）
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
