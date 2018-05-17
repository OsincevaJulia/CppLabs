/*Описать класс «записная книжка». Предусмотреть возможность работы с произвольным числом записей,
поиска записи по какому-либо признаку (например, по ФИО, дате рождения, номеру телефона), добавления
и удаления записей, сортировки по ФИО.Программа должна содержать меню, позволяющее осуществлять
проверку всех методов.*/
#include <iostream>
#include <string>
using namespace std;

class Person
{
	char* FIO;
	int date;
	char* phone;
public:
	/*Person(char* FIO, int date, char* phone)
	{
		this->FIO = FIO;
		this->date = date;
		this->phone = phone;
	};*/
};

class Notebook
{
	Person** Array;
	int size, index;
public:
	void Add(Person* p)
	{
	};
	void Show()
	{
	};
	void Delete_str(char* FIO)
	{
	};
	void Sort()
	{
	};
	void Search()
	{
	};
};



int Menu()
{
	
	int n = 0;


	cout << "Выберите пункт меню: " << endl;
	cout << "1.Добавить запись." << endl;
	cout << "2.Удалить запись." << endl;
	cout << "3.Сортировать по ФИО." << endl;
	cout << "4.Поиск записи по ФИО." << endl;
	cin >> n;
	switch (n)
	{

	case 1:
	{
		
		break;
	};
	case 2:
	{
		
	    break;
	};
	case 3:
		//cout << "3.Сортировать по ФИО." << endl;
		break;
	case 4:
		//cout << "4.Поиск записи по ФИО." << endl;
		break;
	default:
		cout << "Некорректный ввод." << endl;
	};
	system("pause");
	return 0;
};
int main()
{
	setlocale(LC_ALL, "Russian");
}


