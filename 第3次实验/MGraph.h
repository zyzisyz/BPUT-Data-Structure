#pragma once
#include<iostream>
#define MAXSIZE 10
using namespace std;



template<class T> 
class MGraph
{
public:
	MGraph(T a[], int n, int e);				//构造函数(自己输入)
	MGraph(T a[], int n, int e, int b[]);		//构造函数(无需自己输入,为了好测试)
	void DFS_Travel(int v);
	void BFS_Travel(int v);
	int vNum, arcNum;							//顶点数，边数
	T vertex[MAXSIZE];							//顶点
	int arcs[MAXSIZE][MAXSIZE];					//弧
private:
	bool visited[MAXSIZE];						//是否被访问
	void DFS(int v);							//深度优先
	void BFS(int v);							//广度优先
};


//邻接矩阵(时间复杂度O(n^2)
template<class T>
MGraph<T>::MGraph(T a[], int n, int e)	//n为顶点数,e为边数
{
	if (n > MAXSIZE)
		cout << "初始化失败,超过最大长度" << endl;
	else 
	{
		vNum = n;							//定点
		arcNum = e;							//边

		for (int k = 0; k < n; ++k)
			vertex[k] = a[k];				//初始化顶点

		for (int k = 0; k < n; ++k)			//初始化边
		{
			for (int j = 0; j < n; j++)
			{
				arcs[k][j] = 0;
			}
		}

		for (int k = 0; k < e; k++)			//初始化无向图
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
	vNum = n;							//定点
	arcNum = e;							//边

	for (int k = 0; k < n; ++k)
		vertex[k] = a[k];				//初始化顶点

	
	for (int k = 0; k < n; k++)			//用b[][]初始化无向图
	{
		for (int j = 0; j < n; ++j)
		{
			arcs[k][j] = b[k*n + j];
		}
	}
}





//深度优先遍历
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


//广度优先遍历
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
	int f = 0, r = 0;						//生成一个空队列

	cout << vertex[v] << " ";
	visited[v] = true;						//访问v

	queue[++r] = v;							//v入队
	while (f != r)
	{
		v = queue[++f];						//对头出队
		for (int j = 0; j < vNum; ++j)
		{
			if (arcs[v][j] != 0 && visited[j] == false)
			{
				cout << vertex[j] << " ";
				visited[j] = true;			//访问j

				queue[++r] = j;				//j入队
			}
		}
	}
}
