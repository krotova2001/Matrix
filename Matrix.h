#pragma once
#include <ctime>
#include <iostream>
using namespace std;

class Matrix
	//�������� �������� ����� ��� �������� ������ ���������� ������� (������� �� ����������)
	//����� ���������� ������ ������� ��� �������� �������, ������� ������ ����������� 
{
	int static lenth;
	static int mass[][];
	
public:
	Matrix(int lenth)
	{
		for (int i = 0; i < lenth; i++)
		{
			for (int j = 0; j < lenth; j++)
				mass[i][j] = rand() % 10;
		}
	}

};

