// BankerAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"DataStructure.h"
using namespace std;
void BankerAlgorithm() {
	int* Available;
	int** Max;
	int** Allocation;
	int m;
	int* request;
	request = new int[res];
	Available = new int[res];
	Max = new int* [Proc];
	Allocation = new int* [Proc];
	for (int i = 0; i < Proc; i++) {
		Max[i] = new int[res];
		Allocation[i] = new int[res];
	}
	cout << "请初始化各资源的初始值（A B C）:" << endl;
	for (int i = 0; i < res; i++)
		cin >> Available[i];
	cout << "请初始化各进程的资源最大需求量（五个进程三个资源）" << endl;
	for (int i = 0; i < Proc; i++)
		for (int j = 0; j < res; j++)
			cin >> Max[i][j];
	cout << "请初始化各进程的资源初始分配量（五个进程三个资源）" << endl;
	for (int i = 0; i < Proc; i++)
		for (int j = 0; j < res; j++)
			cin >> Allocation[i][j];
	while (1)
	{
		cout << "请输入请求的进程及每种资源（3）请求量" << endl;
		cin >> m;
		for (int i = 0; i < res; i++)
			cin >> request[i];
		DataStructure data(Available, Max, Allocation);
		bool flag = data.Request(m, request);
		if (flag)
			cout << "请求成功！" << endl;
		else
			cout << "请求失败！" << endl;
		cout << "是否继续请求？(y/n)" << endl;
		char a;
		cin >> a;
		if (a == 'n' || a == 'N')
			break;
	}
	
	delete[]request;
	delete[]Available;
	for (int i = 0; i < Proc; i++)
	{
		delete[]Allocation[i];
		delete[]Max[i];
	}
	delete[]Allocation;
	delete[]Max;
}
int main()
{
	cout << "本程序实现了五个进程三种资源的银行家算法" << endl;
	BankerAlgorithm();
}

