#include"Huffman.h"


using namespace std;


int main(void)
{
	cout << "Huffman" << endl << endl;
	char b[8] = { 'a','b','c','d','e','f','g','h' };
	float a[8] = { 0.07,0.09,0.02,0.06,0.32,0.03,0.21,10 };
	Huffman test(8);
	
	test.CreateHTree(a);
	test.CreateCodeTable(b);
	test.PrintTree();
	system("pause");
}