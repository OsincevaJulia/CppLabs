/*������� ����� ��������� ������. ������������� ����������� ������ � ������������ ������ �������,
������ ������ �� ������-���� �������� (��������, �� ���, ���� ��������, ������ ��������), ����������
� �������� �������, ���������� �� ���.��������� ������ ��������� ����, ����������� ������������
�������� ���� �������.*/
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


	cout << "�������� ����� ����: " << endl;
	cout << "1.�������� ������." << endl;
	cout << "2.������� ������." << endl;
	cout << "3.����������� �� ���." << endl;
	cout << "4.����� ������ �� ���." << endl;
	cin >> n;
	switch (n)
	{

	case 1:
	{
		Notebook New_point;
		char* FIO;
		char* date;
		char* phone;
		cout << "������� ���: ";
		cin >> FIO;
		cout << "������� ���� ��������: ";
		cin >> date;
		cout << "������� ����� ��������: ";
		cin >> phone;
		New_point.Add(FIO, date, phone);
		break;
	};
	case 2:
	{

		break;
	};
	case 3:
		//cout << "3.����������� �� ���." << endl;
		break;
	case 4:
		//cout << "4.����� ������ �� ���." << endl;
		break;
	default:
		cout << "������������ ����." << endl;
	};
	system("pause");
	return 0;
}