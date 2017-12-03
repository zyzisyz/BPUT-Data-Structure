#pragma once
//信通院 2016211111班 2016210318 班内 20 张阳

#include<iostream>
#define MAX 2147483647

//Huffman结点（静态三叉链表）
struct HNode
{
	float weight;
	int parent;
	int lchild;
	int rchild;
	bool Selected;
};


//Huffman编码表
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