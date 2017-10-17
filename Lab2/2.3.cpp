//В целочисленном массиве удалить все подряд идущие одинаковые элементы.
#include <iostream>
using namespace std;
int main()
{
	int n, i;
	cout << "Введите размер массива(последние два элемента не могут быть равны друг другу): ";
	cin >> n;
	int *a = new int[n];
	cout << "Введите массив(последние два элемента не могут быть равны друг другу): ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	for (i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			a[i + 1] = a[i + 2];
			k = n - 1;
		}
	}
	for (i = 0; i < k; i++)
		cout << a[i] << " ";
	delete[]a;
	return 0;
}