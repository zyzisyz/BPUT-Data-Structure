#include"MGraph.h"			//MGraph��
#include"Prim.h"			//����ķ�㷨
#include"Kruskal.h"			//��³˹�㷨


using namespace std;

int main(void)
{
	cout << "��������" << endl
		<< "���Ϊ��char a[6] = { 'A','B','C','D','E','F' };" << endl
		<< "ʹ���ڽӾ���" << endl
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
	
	cout << "������ȱ���: ";
	G.BFS_Travel(0);
	
	cout << "������ȱ���: ";
	G.DFS_Travel(0);

	cout << endl;

	cout << "����ķ�㷨����С������: " << endl;
	Prim<char>(G);
	cout << endl;

	cout << "��³˹�����㷨����С������: " << endl;
	Kruskal<char>(G);

	system("pause");

	
}
