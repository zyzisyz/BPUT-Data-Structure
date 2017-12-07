#include"binary_tree.h"
using namespace std;

int main(void)
{
	//测试数据
	int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//测试构造函数
	BiTree<int> Test_1(data, 10);
	//测试复制构造函数
	BiTree<int> Test_2(Test_1);

	cout << "tree depth" << endl << "	" << Test_2.Depth(Test_2.root, 0) << endl;
	cout << "path(1 to 10)： " << endl << "	";
	Test_2.Path(Test_2.root, 10);
	cout << endl;

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