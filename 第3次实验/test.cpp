#include"MGraph.h"			//MGraph类
#include"Prim.h"			//普里姆算法
#include"Kruskal.h"			//克鲁斯算法


using namespace std;

int main(void)
{
	cout << "测试数据" << endl
		<< "结点为：char a[6] = { 'A','B','C','D','E','F' };" << endl
		<< "使用邻接矩阵：" << endl
		<< "int b[36] =\n{0, 34, 46, 0, 0, 19,\n34, 0, 0, 0, 12, 0,\n46, 0, 0, 17, 0, 25,\n0, 0, 17, 0, 38, 25,\n0, 12, 0, 38, 0, 26,\n19, 0, 25, 25, 26, 0,\n}; " << endl<<endl;
	char a[6] = { 'A','B','C','D','E','F' };
	int b[36] =
	{
		 0,34,46, 0, 0,19,
		34, 0, 0, 0,12, 0,
		46, 0, 0,17, 0,25,
		 0, 0,17, 0,38,25,
		 0,12, 0,38, 0,26,
		19, 0,25,25,26, 0,
	};
	MGraph<char> G(a, 6, 9, b);
	
	cout << "广度优先遍历: ";
	G.BFS_Travel(0);
	
	cout << "深度优先遍历: ";
	G.DFS_Travel(0);

	cout << endl;

	cout << "普里姆算法的最小生成树: " << endl;
	Prim<char>(G);
	cout << endl;

	cout << "克鲁斯卡尔算法的最小生成树: " << endl;
	Kruskal<char>(G);

	system("pause");

	
}
