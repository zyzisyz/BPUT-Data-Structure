#pragma once
#include<iostream>
#define MAXSIZE 10
using namespace std;



template<class T> 
class MGraph
{
public:
	MGraph(T a[], int n, int e);				//���캯��(�Լ�����)
	MGraph(T a[], int n, int e, int b[]);		//���캯��(�����Լ�����,Ϊ�˺ò���)
	void DFS_Travel(int v);
	void BFS_Travel(int v);
	int vNum, arcNum;							//������������
	T vertex[MAXSIZE];							//����
	int arcs[MAXSIZE][MAXSIZE];					//��
private:
	bool visited[MAXSIZE];						//�Ƿ񱻷���
	void DFS(int v);							//�������
	void BFS(int v);							//�������
};


//�ڽӾ���(ʱ�临�Ӷ�O(n^2)
template<class T>
MGraph<T>::MGraph(T a[], int n, int e)	//nΪ������,eΪ����
{
	if (n > MAXSIZE)
		cout << "��ʼ��ʧ��,������󳤶�" << endl;
	else 
	{
		vNum = n;							//����
		arcNum = e;							//��

		for (int k = 0; k < n; ++k)
			vertex[k] = a[k];				//��ʼ������

		for (int k = 0; k < n; ++k)			//��ʼ����
		{
			for (int j = 0; j < n; j++)
			{
				arcs[k][j] = 0;
			}
		}

		for (int k = 0; k < e; k++)			//��ʼ������ͼ
		{
			int i, j, s;
			cin >> i >> j >> s;
			arcs[i][j] = arcs[i][j] = s;	
		}
	}
}

template<class T>
MGraph<T>::MGraph(T a[], int n, int e, int b[])
{
	vNum = n;							//����
	arcNum = e;							//��

	for (int k = 0; k < n; ++k)
		vertex[k] = a[k];				//��ʼ������

	
	for (int k = 0; k < n; k++)			//��b[][]��ʼ������ͼ
	{
		for (int j = 0; j < n; ++j)
		{
			arcs[k][j] = b[k*n + j];
		}
	}
}





//������ȱ���
template<class T>
void MGraph<T>::DFS_Travel(int v)
{
	for (int i = 0; i < vNum; ++i)
		visited[i] = false;
	DFS(v);
	cout << endl;
}

template<class T>
void MGraph<T>::DFS(int v)
{
	cout << vertex[v] << " ";
	visited[v] = true;
	for (int j = 0; j < vNum; j++)
	{
		if (arcs[v][j] != 0 && visited[j] == false)
			DFS(j);
	}
}


//������ȱ���
template<class T>
void MGraph<T>::BFS_Travel(int v)
{
	for (int i = 0; i < vNum; ++i)
		visited[i] = false;
	BFS(v);
	cout << endl;
}

template<class T>
void MGraph<T>::BFS(int v)
{
	int queue[MAXSIZE];
	int f = 0, r = 0;						//����һ���ն���

	cout << vertex[v] << " ";
	visited[v] = true;						//����v

	queue[++r] = v;							//v���
	while (f != r)
	{
		v = queue[++f];						//��ͷ����
		for (int j = 0; j < vNum; ++j)
		{
			if (arcs[v][j] != 0 && visited[j] == false)
			{
				cout << vertex[j] << " ";
				visited[j] = true;			//����j

				queue[++r] = j;				//j���
			}
		}
	}
}
