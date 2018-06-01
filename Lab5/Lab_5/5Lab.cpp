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
	char* date;
	char* phone;
public:
	Person()
	{
		FIO = nullptr;
		date = nullptr;
		phone = nullptr;
	};
	Person(char* FIO, char* date, char* phone)
	{
		this->FIO = FIO;
		this->date = date;
		this->phone = phone;
	};
};

class Notebook
{
	Person** Array;
	int size = 0, index;
public:
	void Add(char* FIO, char* date, char* phone)
	{
		Person* person = new Person(FIO, date, phone);
		Array[index++] = person;
		size++;
	};
	void Delete_str(int index)
	{

	};
	void Sort()
	{
	};
	void Search()
	{
	};
};


int main()
{
	setlocale(LC_ALL, "Russian");
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
		Notebook New_point;
		char* FIO;
		char* date;
		char* phone;
		cout << "Введите ФИО: ";
		cin >> FIO;
		cout << "Введите дату рождения: ";
		cin >> date;
		cout << "Введите номер телефона: ";
		cin >> phone;
		New_point.Add(FIO, date, phone);
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
}