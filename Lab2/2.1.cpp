/*1.	Дан массив действительных чисел размером n.
Если в результате замены отрицательных членов последовательности их квадратами члены будут 
образовывать неубывающую последовательность, то получить сумму членов исходной последовательности.
В противном случае получить их произведение.*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, i, j;
	cout << "Введите размер массива: ";
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin>>a[i];
	int *x = new int[n];
	  for (int i = 0; i < n; i++)
	  if (a[i] < 0)
	  x[j] = a[i]*a[i];
	  int c = 1;
	  int s = 0;
	  int p = 1;
	  for (int j = 0; j < n; j++);
	  {
		  if (x[j] < x[j + 1])
		  {
			  c++;
			  if (c = n)
			  {
				  for (int i = 0; i < n; i++);
				  s = s + a[i];
			  }
		  }
		  else
		  {
			  for (i = 0; i < n; i++);
			  p = p*a[i];
		  }
		 
	  }
		delete[]a;
		delete[]x;
	return 0;
}