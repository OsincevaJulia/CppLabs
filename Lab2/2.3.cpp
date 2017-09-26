//3.	В целочисленном массиве удалить все подряд идущие одинаковые элементы.
#include <iostream>
using namespace std;
int main()
{
	int n, i;
	cout << "Введите размер массива: ";
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	for (i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
		{
			a[i] = a[i + 1];
		     k = n - 1;
		}
	}
	for (i = i + 2; i < k; i++)
		a[i + 1] = a[i + 2];
	cout << a[i];
}