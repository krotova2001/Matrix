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
	
	Matrix& Init_random() // инициализация случайными значениями
	{
		for (int i = 0; i < M*N; i++)
		{
			start[i] = rand()%100;
		}
		return *this;
	}

	Matrix& Init_manual() // заполнение с клавиатуры пользователем 
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

	T Show_max() // максимальный элемент матрицы
	{
		T tmp=start[0];
		for (int i = 0; i < M*N; i++)
		{
			if (tmp <= start[i]) tmp = start[i];
		}
		return tmp;
	}

	T Show_min() // минимальный элемент матрицы
	{
		T tmp = start[0];
		for (int i = 0; i < M * N; i++)
		{
			if (tmp >= start[i]) tmp = start[i];
		}
		return tmp;
	}

	void Show() // показать матрицу
	{
		if (start) // если матрица не пустая
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

	int Size() { return M * N; } // узнать размер матрицы
	
	Matrix& operator+(Matrix &A) //перегрузка сложения
	{
		if (Size() == A.Size()) // делаем только, если размеры матриц одинаковые
		{
			for (int i = 0; i < M*N; i++)
			{
				start[i] += A.start[i];
			}
			return *this;
		}
	}
	
	Matrix& operator-(Matrix& A) //перегрузка вычинтания
	{
		if (Size() == A.Size()) // делаем только, если размеры матриц одинаковые
		{
			for (int i = 0; i < M * N; i++)
			{
				start[i] -= A.start[i];
			}
			return *this;
		}
	}

	Matrix& operator*(Matrix & A) //перегрузка умножения
	{
		if (Size() == A.Size()) // делаем только, если размеры матриц одинаковые
		{
			for (int i = 0; i < M * N; i++)
			{
				start[i] = start[i] * A.start[i];
			}
			return *this;
		}
	};

	Matrix& operator/ (Matrix& A) //перегрузка вычинтания
	{
		if (Size() == A.Size()) // делаем только, если размеры матриц одинаковые
		{
			for (int i = 0; i < M * N; i++)
			{
				start[i] /= A.start[i];
			}
			return *this;
		}
	}



		~Matrix() // деструктор
		{
			if (start)delete[]start;
			start = nullptr;
		}
	};

