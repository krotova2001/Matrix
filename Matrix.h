#pragma once
#include <ctime>
#include <iostream>
using namespace std;
template <typename T>

class Matrix//создадим основной класс для хранения данных  матрицы
{
	int M, N; // длина и высота матрицы
	T* start; // адрес первого элемента
public:
	Matrix(): M{0}, N{0}, start{nullptr}{} // конструктор по умолчанию
	Matrix(int m) :Matrix(m, m) {} //на случай квадратной матрицы
	Matrix(int m, int n) // конструктор с параметрами
	{
		M = m;
		N = n;
		start = new T[M * N];
	}
	
	Matrix Init_random() // инициализация случайными значениями
	{
		for (size_t i = 0; i < length; i++)
		{

		}
	}

	int Size() { return M * N }; // узнать размер матрицы
	
	~Matrix()
	{
		if (start)delete[]start;
	}
};

