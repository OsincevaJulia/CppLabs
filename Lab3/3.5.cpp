/*5.	В текстовом файле INPUT.TXT записаны целые числа через пробел, 
возможно, в несколько строк. За один просмотр файла сформировать список этих чисел.
Вставить новый элемент в список за каждым вхождением заданного с клавиатуры элемента. 
Полученный список занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
int main()
{
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	while (in.eof())
	{
		int n;
		cout << "Введите размер массива: ";
			cin >> n;
			char *A = new char[255];
			in.getline(A, 255);
			int *B = new int[255];
			int a, x;
			cout << "Введите число, после которого нужно поставить элемент: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> x;
			char*tmp = A;
			for (int i = 0; i < n; i++)
			{
				tmp = strchr(tmp, ' ') + 1;
				int t = atoi(tmp);
				for (int j = 0; j < n; j++)
				{
					if (t == a)
					{
						B[j + 2] = B[j + 1];
						B[j + 1] = x;
					}
					else
						B[j] = t;
				}
			}
			delete[]A;
			delete[]B;
	}
	in.close();
	out.close();
	return 0;
}