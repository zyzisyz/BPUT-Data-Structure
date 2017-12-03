#pragma once
//��ͨԺ 2016211111�� 2016210318 ���� 20 ����

#include<iostream>
#define MAX 2147483647

//Huffman��㣨��̬��������
struct HNode
{
	float weight;
	int parent;
	int lchild;
	int rchild;
	bool Selected;
};


//Huffman�����
struct Hcode
{
	char data;
	char code[100];
	int Codecapacity;
};



class Huffman
{
private:
	HNode* HTree;
	Hcode* HCodeTable;
	int SelectMin(int n);
	int n;
public:
	Huffman(int i) { n = i; }
	void CreateHTree(float a[]);
	void CreateCodeTable(char b[]);
	float CalculateWPL();
	void PrintTree();
};