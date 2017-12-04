#include"binary_tree.h"
using namespace std;

int main(void)
{
	//��������
	int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//���Թ��캯��
	BiTree<int> Test_1(data, 10);
	//���Ը��ƹ��캯��
	BiTree<int> Test_2(Test_1);

	cout << "PreOrder:" << endl << "	";
	Test_2.PreOrder(Test_2.root);
	cout << endl;

	cout << "PreOrder:" << endl << "	";
	Test_2.InOrder(Test_2.root);
	cout << endl;

	cout << "PreOrder:" << endl << "	";
	Test_2.PostOrder(Test_2.root);
	cout << endl;

	cout << "LevelOrder:" << endl << "	";
	Test_2.LevelOrder(Test_2.root);
	cout << endl;

	cout << "Nodes number of this Binary tree:" << endl << "	" << Test_2.GetNodesNumber() << endl;
	system("pause");
}