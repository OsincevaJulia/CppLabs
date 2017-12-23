/*Описать класс «записная книжка». Предусмотреть возможность работы с произвольным числом записей,
поиска записи по какому-либо признаку (например, по ФИО, дате рождения, номеру телефона), добавления
и удаления записей, сортировки по ФИО.Программа должна содержать меню, позволяющее осуществлять
проверку всех методов.*/
#include <iostream>
#include <string>
using namespace std;

class List
{
public:
	List()
	{
		Size = 0;
		Head = nullptr;
	};
	void new_str(char* FIO, int date, int number);
	void show();
	void delete_str();
	~List()
	{

	};
	int GetSize() 
	{ 
		return Size; 
	};
private:
	class Person
	{
	public:
		Person *next_elem;
		char* FIO;
		int date;
		int number;
		Person(char* FIO = nullptr, int date = 0, int number = 0, Person* next_elem = nullptr)
		{
			this->FIO = FIO;
			this->date = date;
			this->number = number;
			this->next_elem = next_elem;
		};
	};
	Person *Head;
	int Size;
};
/*
public:
void new_str(char* FIO, int date, int number)
{
this->FIO = FIO;
this->date = date;
this->number = number;
cout << "Введите новые ФИО: ";
cin >> FIO;
cout << "Введите новую дату рождения: ";
cin >> date;
cout << "Введите новый номер телефона: ";
cin >> number;
cout << FIO << "   " << date << "   " << number << endl;
};

void delete_str()
{
};

void sort()
{
};

void search_FIO()
{
};

void search_date()
{
};

void search_number()
{
};*/
};

void List::new_str(char * FIO, int date, int number)
{
	if (Head == nullptr)
	{

		Head = new Person(FIO, date, number);
	}
	else
	{
		Person* this_elem = this->Head;
		while (this_elem->next_elem != nullptr)
		{
			this_elem = this_elem->next_elem;
		};
		this_elem->next_elem = new Person(FIO, date, number);
	};
	Size++;
}
void List::show()
{
	Person *this_elem = this->Head;
	while (this_elem != nullptr)
	{
		cout << this_elem->FIO<<"-----";
		cout << this_elem->date<<"-----";
		cout << this_elem->number<<endl;
		this_elem = this_elem->next_elem;
	};
}
void List::delete_str()
{
	Person* this_elem = Head;
	Person* last_elem = this_elem;
	if (this_elem->next_elem != nullptr)
	{
		last_elem = last_elem->next_elem;
		delete this_elem;
	}
	else
	{
		last_elem = last_elem->this_elem;
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
	cout << "5.Поиск записи по дате рождения." << endl;
	cout << "6.Поиск записи по номеру телефона." << endl;
	cin >> n;
	switch (n)
	{

	case 1:
	{
		List new_person;
		char * FIO, int date, int number;
		cout << "Введите новые ФИО: ";
		cin >> FIO;
		cout << "Введите новую дату рождения: ";
		cin >> date;
		cout << "Введите новый номер телефона: 8- ";
		cin >> number;
		new_person.new_str(FIO, date, number);
		new_person.show();
		break;
	};
	case 2:
	{
		List delete_person;
		char*FIO;
		cout << "Введите ФИО удаляемого человека: ";
		cin >>FIO;
		delete_person.delete_str();
		delete_person.show();
	    break;
	};
	case 3:
		//cout << "3.Сортировать по ФИО." << endl;
		break;
	case 4:
		//cout << "3.Сортировать по ФИО." << endl;
		break;
	case 5:
		//cout << "5.Поиск записи по дате рождения." << endl;
		break;
	case 6:
		//cout << "6.Поиск записи по номеру телефона." << endl;
		break;
	default:
		cout << "Некорректный ввод." << endl;
	};
	system("pause");
	return 0;
}

