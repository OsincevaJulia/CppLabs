/*5.	В текстовом файле INPUT.TXT записаны целые числа через пробел, 
возможно, в несколько строк. За один просмотр файла сформировать список этих чисел.
Вставить новый элемент в список за каждым вхождением заданного с клавиатуры элемента. 
Полученный список занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	if (!in)
	{
		cout << "Файл не найден";
		system("pause");
		return 0;
	}
	if (!out)
	{
		cout << "Файл не найден";
		system("pause");
		return 0;
	}
	int m = 0;
	int* A = new int[255];
    for (int i = 0; !in.eof(); i++)
	{
		in >> A[i];
		m = m + 1;;
	}
	int a = 0;
	int x = 0;
	int n = 0;

	cout << "Введите элемент после которого нужно ввести новое число: ";
	cin >> a;

	cout << "Введите новый элемент: ";
	cin >> x;
	int* B = new int[255];
	for (int i = 0, j = 0; i < m; i++, j++)
	{
		if (A[i] == a)
		{
			B[j] = A[i];
			B[j+1] = x;
			n = j+1;
			continue;
		}
		B[j] = A[i];
		n = j;
	}
	for (int j = 0; j < n; j++)
	{
		out << B[j]<<" ";
	}
	delete[]A;
	delete[]B;
	in.close();
	out.close();
	return 0;
}