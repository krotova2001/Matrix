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
	
	Matrix& Init_random() // ������������� ���������� ����������
	{
		for (int i = 0; i < M*N; i++)
		{
			start[i] = rand()%100;
		}
		return *this;
	}

	Matrix& Init_manual() // ���������� � ���������� ������������� 
	{
		for (int i = 0; i < M * N; i++)
		{
			T temp;
			cout << "Element #" << i + 1 << " ";
			cin >> temp;
			start[i] = temp;
		}
		return *this;
	}

	T Show_max() // ������������ ������� �������
	{
		T tmp=start[0];
		for (int i = 0; i < M*N; i++)
		{
			if (tmp <= start[i]) tmp = start[i];
		}
		return tmp;
	}

	T Show_min() // ����������� ������� �������
	{
		T tmp = start[0];
		for (int i = 0; i < M * N; i++)
		{
			if (tmp >= start[i]) tmp = start[i];
		}
		return tmp;
	}

	void Show() // �������� �������
	{
		if (start) // ���� ������� �� ������
		{
			cout << "\n";
			for (int i = 0; i < M*N;)
			{
				for (int j = 0; j < N; j++)
				{
					cout << start[i] <<"; ";
					i++;
				}
				cout << "\n";
			}
		}
		else
		{
			cout << "Empty\n";
		}
	}

	int Size() { return M * N; } // ������ ������ �������
	
	Matrix& operator+(Matrix &A) //���������� ��������
	{
		if (Size() == A.Size()) // ������ ������, ���� ������� ������ ����������
		{
			for (int i = 0; i < M*N; i++)
			{
				start[i] += A.start[i];
			}
			return *this;
		}
	}
	
	Matrix& operator-(Matrix& A) //���������� ����������
	{
		if (Size() == A.Size()) // ������ ������, ���� ������� ������ ����������
		{
			for (int i = 0; i < M * N; i++)
			{
				start[i] -= A.start[i];
			}
			return *this;
		}
	}

	Matrix& operator*(Matrix & A) //���������� ���������
	{
		if (Size() == A.Size()) // ������ ������, ���� ������� ������ ����������
		{
			for (int i = 0; i < M * N; i++)
			{
				start[i] = start[i] * A.start[i];
			}
			return *this;
		}
	};

	Matrix& operator/ (Matrix& A) //���������� ����������
	{
		if (Size() == A.Size()) // ������ ������, ���� ������� ������ ����������
		{
			for (int i = 0; i < M * N; i++)
			{
				start[i] /= A.start[i];
			}
			return *this;
		}
	}



		~Matrix() // ����������
		{
			if (start)delete[]start;
			start = nullptr;
		}
	};

