#pragma once
#include <ctime>
#include <iostream>
using namespace std;
template <typename T>

class Matrix//�������� �������� ����� ��� �������� ������  �������
{
	int M, N; // ����� � ������ �������
	T* start; // ����� ������� ��������
public:
	Matrix(): M{0}, N{0}, start{nullptr}{} // ����������� �� ���������
	Matrix(int m) :Matrix(m, m) {} //�� ������ ���������� �������
	Matrix(int m, int n) // ����������� � �����������
	{
		M = m;
		N = n;
		start = new T[M * N];
	}
	
	Matrix Init_random() // ������������� ���������� ����������
	{
		for (size_t i = 0; i < length; i++)
		{

		}
	}

	int Size() { return M * N }; // ������ ������ �������
	
	~Matrix()
	{
		if (start)delete[]start;
	}
};

