#include"Huffman.h"


using namespace std;


int Huffman::SelectMin(int n)
{
	float min = MAX;
	for (int i = 0; i < n; ++i)
	{
		if (HTree[i].Selected == false)
		{
			if (HTree[i].weight < min)
			{
				min = HTree[i].weight;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (HTree[i].Selected == false)
		{
			if (min == HTree[i].weight)
			{
				HTree[i].Selected = true;
				return i;
				break;
			}
		}
	}
}

void Huffman::PrintTree()
{
	cout << endl << "��Ȩ·������: " << CalculateWPL() << endl;

	//�������������ܵĴ洢�ռ�
	float All_Codecapacity = 0;
	for (int i = 0; i < n; i++)
	{
		All_Codecapacity += HCodeTable[i].Codecapacity;
	}

	cout << endl << "ѹ����: " << 8 * n / All_Codecapacity << endl << endl;

	cout << endl << "��̬���������ʾ��Huffman��" << endl << endl;

	
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		cout << "NO " << i << endl
			<< "	lchild: " << HTree[i].lchild << endl
			<< "	rchild: " << HTree[i].rchild << endl
			<< "	parent: " << HTree[i].parent << endl
			<< "	weight: " << HTree[i].weight << endl;
	}
}

float Huffman::CalculateWPL()
{
	float WPL = 0;
	for (int i = 0; i < n; ++i)
	{
		int path = 0;
		int p = i;
		while (HTree[p].parent != -1)
		{
			path++;
			p = HTree[p].parent;
		}
		WPL += HTree[i].weight*path;
	}
	return WPL;
}

//a[]�����ַ���Ȩֵ��or���ָ��ʣ�
void Huffman::CreateHTree(float a[])
{
	//�������Ľ��
	HTree = new HNode[2 * n - 1];

	//����Ȩֵ��ʼ��
	for (int i = 0; i < n; ++i)
	{
		HTree[i].weight = a[i];
		HTree[i].lchild = HTree[i].rchild = HTree[i].parent = -1;
	}
	
	//selected false
	for (int i = 0; i < (2 * n - 1); ++i)
	{
		HTree[i].Selected = false;
	}

	//�ҳ��Ѿ���ʼ���˵Ľڵ�����С��������㣬�����ǵ���Ÿ�ֵ��x��y
	for (int x, y, i = n; i < (2 * n - 1); ++i)
	{
		x = SelectMin(i);
		y = SelectMin(i);

		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].lchild = x;
		HTree[i].rchild = y;
		HTree[i].parent = -1;
		
		//test
		//cout << x << " " << y << endl;
	}
}


void Huffman::CreateCodeTable(char b[])
{
	//load the data
	HCodeTable = new Hcode[n];
	for (int i = 0; i < n; i++)
	{
		HCodeTable[i].data = b[i];
	}

	//create the code
	for (int i = 0; i < n; i++)
	{
		//temp memory
		char temp[100];

		int child = i;
		int parent = HTree[child].parent;

		int count = 0;
		while (parent != -1)
		{
			if (HTree[parent].lchild == child)
			{
				temp[count] = '0';
			}
			else
			{
				temp[count] = '1';
			}
			count++;
			child = parent;
			parent = HTree[child].parent;
		}
		HCodeTable[i].code[count] = '\0';
		HCodeTable[i].Codecapacity = count;

		//reverse the code
		for (int j = 0; j < count ; ++j)
		{
			HCodeTable[i].code[j] = temp[count - j - 1];
		}
	}

	//output the chart
	cout << "�ַ���Huffman����Ϊ��" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << HCodeTable[i].data << " " << HCodeTable[i].code << endl;
	}
}


