#pragma once
#include<iostream>
#define Proc 5
#define res 3

bool compare(int* a,int* b,int num) {
	for (int i = 0; i < num; i++) {
		if (a[i] > b[i])
			return false;
		return true;
	}
}

class DataStructure {
private:
	int* Available;
	int** Max;
	int** Allocation;
	int** Need;
public:
	DataStructure(int* Available, int** Max, int** Allocation);
	~DataStructure();
	bool Request(int i, int* request);
	bool safeAlgorithm();
};

DataStructure::DataStructure(int* Available, int** Max, int** Allocation) {

	this->Available = new int[res];
	this->Max = new int* [Proc];
	this->Allocation = new int* [Proc];
	this->Need = new int* [Proc];
	for (int i = 0; i < Proc; i++) {
		this->Max[i] = new int[res];
		this->Allocation[i] = new int[res];
		this->Need[i] = new int[res];
	}
	for (int i = 0; i < res; i++)
	{
		this->Available[i] = Available[i];
	}
	for (int i = 0; i < Proc; i++)
	{
		for (int j = 0; j < res; j++)
		{
			this->Allocation[i][j] = Allocation[i][j];
			this->Max[i][j] = Max[i][j];
			this->Need[i][j] = this->Max[i][j] - this->Allocation[i][j];
		}
	}
}

DataStructure::~DataStructure() {
	delete[]Available;
	for (int i = 0; i < Proc; i++)
	{
		delete[]Allocation[i];
		delete[]Max[i];
		delete[]Need[i];
	}
	delete[]Allocation;
	delete[]Max;
	delete[]Need;
}

bool DataStructure::Request(int m, int* request) {
	if (!compare(request, Need[m - 1], res))
		return false;
	if (!compare(request, Available, res))
		return false;
	for (int i = 0; i < res; i++)
	{
		Available[i] -= request[i];
		Allocation[m-1][i]+= request[i];
		Need[m-1][i]-= request[i];
	}
	if (safeAlgorithm())
		return true;
	else
	{
		for (int i = 0; i < res; i++)
		{
			Available[i] += request[i];
			Allocation[m - 1][i] -= request[i];
			Need[m - 1][i] += request[i];
		}
	}

}
bool DataStructure::safeAlgorithm() {
	int* work = this->Available;
	bool finish[Proc];
	for (int i = 0; i < Proc; i++)
		finish[i] = false;
	for (int i = 0; i < Proc; i++)
	{
		if (!finish[i] && compare(Need[i], work, res)) {
			for (int j = 0; j < res; j++)
				work[j] += Allocation[i][j];
			finish[i] = true;
			i = 0;
		}
	}
	for (int i = 0; i < Proc; i++)
		if (!finish[i])
			return false;
	return true;
}

