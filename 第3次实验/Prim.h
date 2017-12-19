#pragma once
#include"MGraph.h"
using namespace std;

//辅助数组
int adjvex[MAXSIZE];				//已经落在生成树的节点
int lowcost[MAXSIZE];				//最小权值边


//选择adjvex到lowcosst权值边集合最小权值的边
template<class T>
int mininum(MGraph<T> G, int lowcost[])
{
	int min = INT_MAX;
	int k = 0;
	for (int i = 1; i < G.vNum; i++)
	{
		if (lowcost[i] != 0 && lowcost[i] < min)
		{
			min = lowcost[i];
			k = i;
		}
	}
	return k;
}

//普里姆算法(不断选最小权值的边)
template<class T>
void Prim(MGraph<T> G)
{
	for (int i = 1; i < G.vNum; ++i)
	{
		adjvex[i] = 0;
		lowcost[i] = G.arcs[0][i];
	}
	lowcost[0] = 0;							//辅助数组存储到所有到v的边

	for (int j = 0; j < G.vNum; j++)
	{
		int k = mininum(G, lowcost);
		cout << "V" << G.vertex[adjvex[k]] << "->V" << G.vertex[k] << endl;
		lowcost[k] = 0;
		for (int j = 0; j < G.vNum; ++j)
		{
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;
			}
		}
	}
}