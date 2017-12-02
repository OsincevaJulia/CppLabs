/*Дан файл INPUT.txt. В нем записаны данные работников компании: 
ФИО, год рождения и зарплата. За один просмотр файла найдите ФИО и
возраст самого высокооплачиваемого работника,
который младше 35 лет. Ответ выведите в файл OUTPUT.txt*/
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
	char* A = new char[255];
	for (int i = 0; !in.eof(); i++)
	{
		in >> A[i];
	}
	char* B = new char[255];
	for (int i = 0; i < 255; i++)
	{
		if (A[i] == 1)
		{
			for (int j = 0; j < 4; j++)
				B[j] = A[i];
		}
	}
	int a;
	int v;
	a = atoi(B);
	v = 2017 - a;
	if (v < 35)
	{
		for (int i = 0; i < 255; i++)
		{
			while (A[i] != 1)
			out << A[i];
		}
		out << "Возраст: "<<v;
}
	delete[]A;
	delete[]B;
	in.close();
	out.close();
	return 0;
}