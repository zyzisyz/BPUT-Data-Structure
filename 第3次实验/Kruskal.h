#pragma once
#include"MGraph.h"



using namespace std;

struct VEdge {
	int fromV;
	int endV;
	int weight;
};


template<class T>
void GetSortEdge(MGraph<T> G, VEdge *EdgeList)
{

	for (int i = 0, k = 0; i < G.vNum; i++)
	{
		for (int j = i; j < G.vNum; j++)
		{
			if (G.arcs[i][j] != 0)
			{
				EdgeList[k].fromV = i;
				EdgeList[k].endV = j;
				EdgeList[k].weight = G.arcs[i][j];
				k++;
			}
		}
	}
	for (int i = 0; i < G.arcNum - 1; i++)						//冒泡排序,对权值从小到大排序
	{
		for (int j = 1; j < G.arcNum; j++)
			if (EdgeList[j - 1].weight > EdgeList[j].weight)
			{
				VEdge t = EdgeList[j - 1];
				EdgeList[j - 1] = EdgeList[j];
				EdgeList[j] = t;
			}
	}
}

template<class T>
void Kruskal(MGraph<T> G)
{
	VEdge *EdgeList = new VEdge[MAXSIZE];
	GetSortEdge(G, EdgeList);

	int vset[MAXSIZE];
	for (int i = 0; i < G.vNum; i++)
		vset[i] = i;						//用vest判断是否构成回路

	int k = 0, j = 0;
	while (k < G.vNum - 1)
	{
		int m = EdgeList[j].fromV,
			l = EdgeList[j].endV;
		int sn1 = vset[m];
		int sn2 = vset[l];
		if (sn1 != sn2)
		{
			cout << 'V' << G.vertex[m] << "->" <<"V"<< G.vertex[l] << endl;
			k++;
			for (int i = 0; i <= l; i++)
			{
				if (vset[i] == sn2)
					vset[i] = sn1;
			}
		}
		j++;
	}
	
}