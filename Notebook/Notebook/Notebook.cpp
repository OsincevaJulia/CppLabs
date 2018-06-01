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
	Person* next;
	Person* prev;
	Person()
	{
		FIO = nullptr;
		date = nullptr;
		phone = nullptr;
	};
	char* getFIO()
	{
		char * newFio = new char[strlen(FIO) + 1];
		strcpy(newFio, FIO);

		return newFio;
	}
	char* getdate()
	{
		char * newdate = new char[strlen(FIO) + 1];
		strcpy(newdate, FIO);

		return newdate;
	}
	char* getphone()
	{
		char * newphone = new char[strlen(FIO) + 1];
		strcpy(newphone, FIO);

		return newphone;
	}
	Person(char* FIO, char* date, char* phone)
	{
		this->FIO = FIO;
		this->date = date;
		this->phone = phone;
	};
};

class Notebook
{
	Person* head;
	Person* bottom;
public:
	Notebook()
	{
		head = nullptr;
		bottom = nullptr;
	};
	void Add(char* FIO, char* date, char* phone)
	{
		Person* p = new Person(FIO, date, phone);
		if (head == nullptr)
		{
			head = p;
			bottom = p;
		}
		else
		{
			p->prev = bottom;
			bottom->next = p;
		}
	};
	void Delete_str(char*FIO)
	{
		Delete_strTo(head, FIO);
	};
	void Sort()
	{
		bool isSort = true;
		while (isSort)
		{
			isSort = false;
			SortTo(head, isSort);
		}
	};
	void Search(char*FIO)
	{
		SearchTo(head, FIO);
	};

private:

	void SortTo(Person *p, bool isSort)
	{
		if (p->next == nullptr)
			return;
		if (strcmp(p->getFIO, p->next->getFIO) < 0)
		{
			Person a;
			a = *p;
			*p = *p->next;
			*p->next = a;

			isSort = true;
		}
		SortTo(p->next, isSort);
	}
	void Delete_strTo(Person *p, char* FIO)
	{
		if (p == nullptr)
		{
			cout << "Not Found";
			return;
		}
		if (strcmp(p->getFIO, FIO) == 0)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			return;
		}
		else
		{
			SearchTo(p->next, FIO);
		}
	}

	void SearchTo(Person *p, char* FIO)
	{
		if (p == nullptr)
		{
			cout << "Not Found";
			return;
		}
		if (strcmp(p->getFIO, FIO) == 0)
		{
			cout << p->getFIO << endl;
			cout << p->getdate << endl;
			cout << p->getphone << endl;
			return;
		}
		else
		{
			SearchTo(p->next, FIO);
		}
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;

	Notebook note;
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
		char* FIO=new char[250];
		char* date=new char[250];
		char* phone=new char[250];
		cout << "Введите ФИО: ";
		cin >> FIO;
		cout << "Введите дату рождения: ";
		cin >> *date;
		cout << "Введите номер телефона: ";
		cin >> *phone;
		note.Add(FIO, date, phone);
		break;
	};
	case 2:
	{
		char* FIO = new char[250];
		cout << "Введите ФИО: ";
		cin >> FIO;
		note.Delete_str(FIO);
		break;
	};
	case 3:
		note.Sort();
		break;
	case 4:
		char* FIO = new char[250];
		cout << "Введите ФИО: ";
		cin >> FIO;
		note.Search(FIO);
		break;
	default:
		cout << "Некорректный ввод." << endl;
	};
	system("pause");
	return 0;
}