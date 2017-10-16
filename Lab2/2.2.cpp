﻿/*Задан массив действительных чисел. 
Требуется домножить все члены последовательности на квадрат ее наименьшего члена, 
если первый элемент неотрицательный, и на квадрат ее наибольшего члена, в противном случае.*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int n, i;
	cout << "Введите размер массива: ";
	cin >> n;
	int *a = new int[n];
	for ( i = 0; i<n; i++) 
		a[i] = rand();
	cout << a[i];
	if (a [0]>= 0)
	{
		int min;
		min = a[0];
		for (i = 0; i < n; i++)
		{
			if (a[i + 1]<min )
				min = a[i + 1];
		}
		min = min*min;
		for (i = 0; i < n; i++)
			a[i] = a[i]*min;
	}
	else
	{
		int max;
		max = a[0];
		for (i = 0; i < n; i++)
		{
			if (a[i + 1]>max)
				max = a[i + 1];
		}
		max = max*max;
		for (i = 0; i < n; i++)
			a[i] = a[i]*max;
	}
	cout << a[i];
	delete[]a;
	return 0;
}
