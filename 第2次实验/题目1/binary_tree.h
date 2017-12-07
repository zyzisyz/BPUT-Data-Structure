#pragma once
#include<iostream>
#define MAXSIZE 1000
using namespace std;

template<class T>
struct BiNode
{
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
	BiNode<T>* parent;
};


template <class T> class BiTree
{
private:
	void Create(BiNode<T>*&R, T data[], int i, int n);
	void Copy(BiNode<T>*& R, BiNode<T>* &in);
	void Release(BiNode<T>*R);
	int Nodes;
public:
	//�����
	BiNode<T>*root;
	int GetNodesNumber() { return Nodes; }			//�������ĸ���
	BiTree() { roor = NULL; }						
	BiTree(T data[], int n);						//���캯��
	BiTree(BiTree<T>&r);							//���ƹ��캯��
	void PreOrder(BiNode<T> *R);					//ǰ�����
	void InOrder(BiNode<T> *R);						//�������
	void PostOrder(BiNode<T> *R);					//�������
	void LevelOrder(BiNode<T> *R);					//�������
	int Depth(BiNode<T> *R, int d);					//���������
	void Path(BiNode<T>* root, char n);				//�󵽵���֪data��·��

	~BiTree();										//��������
};

template<class T>
inline void BiTree<T>::Create(BiNode<T>*& R, T data[], int i, int n)
{
	if (i <= n&&data[i - 1])
	{
		R = new BiNode<T>;
		R->data = data[i - 1];
		Create(R->lchild, data, 2 * i, n);
		Create(R->rchild, data, 2 * i + 1, n);
	}
	else R = NULL;
}

template<class T>
inline void BiTree<T>::Copy(BiNode<T>*& R, BiNode<T>*& in)
{
	if (in)
	{
		R = new BiNode<T>;
		R->data = in->data;
		Copy(R->lchild, in->lchild);
		Copy(R->rchild, in->rchild);
	}
	else R = NULL;
}



template<class T>
inline void BiTree<T>::Release(BiNode<T>* R)
{
	if (R != NULL)
	{
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}

template<class T>
BiTree<T>::BiTree(T data[], int n)
{
	Create(root, data, 1, n);
	Nodes = n;
}

template<class T>
inline BiTree<T>::BiTree(BiTree<T>& r)
{
	Copy(root, r.root);
	Nodes = r.Nodes;
}

template<class T>
void BiTree<T>::PreOrder(BiNode<T>* R)
{
	if (R != NULL)
	{
		cout << R->data << " ";
		PreOrder(R->lchild);
		PreOrder(R->rchild);
	}
}

template<class T>
void BiTree<T>::InOrder(BiNode<T>* R)
{
	if (R != NULL)
	{
		InOrder(R->lchild);
		cout << R->data << " ";
		InOrder(R->rchild);
	}
}

template<class T>
void BiTree<T>::PostOrder(BiNode<T>* R)
{
	if (R != NULL)
	{
		PostOrder(R->lchild);
		PostOrder(R->rchild);
		cout << R->data << " ";
	}
}

template<class T>
void BiTree<T>::LevelOrder(BiNode<T>* R)
{
	BiNode<T>*quene[MAXSIZE];
	int f = 0, r = 0;
	if (R != NULL)
		quene[++r] = R;
	while (f != r)
	{
		BiNode<T>*p = quene[++f];
		cout << p->data << " ";
		if (p->lchild != NULL)
			quene[++r] = p->lchild;
		if (p->rchild != NULL)
			quene[++r] = p->rchild;
	}
}

template<class T>
inline int BiTree<T>::Depth(BiNode<T>* R, int d)
{
	if (R == NULL) 
		return d;
	if ((R->lchild == NULL) && (R->rchild == NULL)) 
		return d + 1;
	else
	{
		int m = Depth(R->lchild, d + 1); 
		int n = Depth(R->rchild, d + 1); 
		return n>m ? n : m; 
	}
}


template<class T>
void BiTree<T>::Path(BiNode<T>* root, char c)
{
	BiNode<T>* stack[1000];
	BiNode<T>* p;
	int tag[1000];				//����ջ�������ݵı�ǩ,1��ʾ���������ӣ�2��ʾ�����Һ��� 
	int top = 0;
	p = root;
	do
	{
		while (p != NULL)
		{
			stack[++top] = p;
			tag[top] = 1;
			p = p->lchild;
		}
		while ((top != 0) && (tag[top] == 2))
		{
			if (stack[top]->data == c)
			{                                
				for (int i = 1; i <= top; i++)
				{
					cout << stack[i]->data<<" ";
				}
			}
			top--;
		}
		if ((top != 0) && tag[top] == 1)
		{
			p = stack[top]->rchild;
			tag[top] = 2;
		}
	} while (top != 0);
}




template<class T>
BiTree<T>::~BiTree()
{
	Release(root);
}


