﻿/*Описать структуру с именем aeroflot, содержащую следующие поля:
•	название пункта назначения рейса;
•	номер рейса (число);
•	тип самолета.
Написать программу, выполняющую следующие действия:
•	ввод с клавиатуры данных в массив, состоящий из максимум 7 элементов типа aeroflot, причем сделать возможность прервать ввод, чтобы можно было не вводить все 7 элементов; после окончания ввода отсортировать элементы массива в алфавитном порядке по названиям пунктов назначения;
•	вывод в консоль номеров рейсов и пунктов назначения, обслуживаемых самолетом, тип которого введен с клавиатуры;
•	если таких рейсов нет, вывести соответствующее сообщение;
*/
#include <iostream>
#include <cstdlib>

using namespace std;

struct aeroflot
{
	char name[100];
	int number;
	char type[50];
};
int main()
{
	aeroflot* A = new aeroflot[7];
	int n = 0;
	for (int i = 0; i < 7; i++)
	{
		cout << "Введите название пункта назначения рейса: " << endl;
		cout << "Для завершения введите 0.";
		cin >> A[i].name;
		if (A[i].name[0] == '0')
		{
			break;
		}
		n = n + 1;
		cout << "Введите номер рейса: ";
		cin >> A[i].number;
		cout << "Введите тип самолета: ";
		cin >> A[i].type;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (A[i].name[0] > A[i + 1].name[0])
		{
			swap(A[i], A[i + 1]);
		}
	}
	for (int i = 0; i < n; i++)
	cout << A[i].name << A[i].number << A[i].type<<endl;
	char t[50];
	cout << "Введите тип самолета: ";
	cin >> t;
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (*A[i].type == *t)
		{
			check = true;
			cout << A[i].name << A[i].number << endl;
		}
	}
	if(!check)
		cout << "Таких рейсов нет.";
	delete[]A;
}