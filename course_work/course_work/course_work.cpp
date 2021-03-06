/*Написать программу учета заявок на авиабилеты. Каждая заявка содержит: пункт назначения, 
номер рейса, фамилию и инициалы пассажира, желаемую дату вылета.
Программа должна обеспечивать выбор с помощью меню и выполнение одной из следующих функций:
добавление заявок в список;
удаление заявок;
вывод заявок по заданному номеру рейса и дате вылета;
вывод всех заявок.
Для хранения данных использовать класс «коллекция ключ-значение» (с неуникальными ключами), 
в качестве ключа использовать «пункт назначения». Предусмотреть сохранение всех данных при выходе 
в файл и восстановление при повторном запуске программы.
*/
#include "stdafx.h"


#include <iostream>
#include <fstream>

using namespace std;

template <class TKey, class TValue>
class Element
{
public:
	TKey key;
	TValue value;
};


template <class TKey, class TValue>
class Map
{
private:
	int size;
	int count = 0;
public:
	Element<TKey, TValue> *array;
	Map(int  k)
	{
		size = k;
		array = new Element<TKey, TValue>[size];
	}
	~Map()
	{
		delete[] array;
	}

	void Expansion()//Расширение массива
	{
		int temp;
		temp = size * 2;
		Element<TKey, TValue> *tempArray = new Element<TKey, TValue>[temp];

		for (int i = 0; i < count; i++)
		{
			tempArray[i] = array[i];
		}

		delete[]array;
		array = tempArray;
		size = temp;
	}

	void Put(TKey Nkey, TValue Nvalue)
	{
		if (count == size)
		{
			Expansion();
		}
		array[count].key = Nkey;
		array[count].value = Nvalue;
		count++;
	}

	TValue* Get(int& _num) //Возвращение элемента по номеру
	{
		for (int i = 0; i < count; i++)
		{
			if (i == _num)
			{
				TValue *tmp = new TValue[1];
				tmp[0] = array[i].value;
				TValue *Arr = new TValue[1];
				Arr[0] = tmp[0];

				return Arr;
			}
		}
		return NULL;
	}

	void Del(TValue value)
	{
		for (int i = 0; i < count; i++)
		{
			if (value == array[i].value)
			{
				array[i] = array[count - 1];
				count--;
			}
		}
	}

	int Count()
	{
		return count;
	}

	void GetALL(TValue*& newArr)
	{
		newArr = new TValue[count];
		TValue *tmp = new TValue[count];
		for (int i = 0; i < count; i++)
		{
			tmp[i] = array[i].value;
			newArr[i] = tmp[i];
		}
	}
};




class Aeroflot
{
private:
	char FIO[100];
	char place[100];
	int number;
	char date[100];
public:
	Aeroflot()
	{
	};

	Aeroflot(char* fio, char* pl, int num, char* dd)
	{
		for (int i = 0; i < 100; i++)
			FIO[i] = fio[i];
		for (int i = 0; i < 100; i++)
			place[i] = pl[i];
		for (int i = 0; i < 100; i++)
			date[i] = dd[i];
		this->number = num;
	}

	~Aeroflot()
	{
	};

	void Add(char* fio, char* pl, int num, char* dd)
	{
		for (int i = 0; i < 100; i++)
			this->FIO[i] = fio[i];
		for (int i = 0; i < 100; i++)
			this->place[i] = pl[i];
		for (int i = 0; i < 100; i++)
			this->date[i] = dd[i];
		this->number = num;
	}

	char* Date()
	{
		return date;
	}

	char* Fio()
	{
		return FIO;
	}

	char* Place()
	{
		return place;
	}

	int Number()
	{
		return number;
	}

	int operator==(Aeroflot& tmp)
	{
		if (((strcmp(tmp.FIO, FIO)) == 0) &
			((strcmp(tmp.place, place)) == 0) &
			((strcmp(tmp.date, date)) == 0) &
			(tmp.number == number))
			return 1;
		else
			return 0;
	}

	friend ostream &operator<<(ostream &out, Aeroflot& d)//Дружественная функция перегрузки опереатора вывода
	{
		out << d.FIO << " " << d.place << " " << d.number << " " << d.date << " ";
		return out;
	}
};


void Show(Aeroflot* array, int count)//Функция вывода всех элементов на экран
{
	setlocale(LC_ALL, "Russian");
	system("CLS");
	if (count == 0)
	{
		cout << "Заявок не создано" << endl;
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << (i + 1) << ") ";
			cout << array[i].Fio() << " ";
			cout << array[i].Place() << " ";
			cout << array[i].Date() << " ";
			cout << array[i].Number() << endl;
		}
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");
	char Menu[] = "Menu:\n1) Добавть заявку\n2) Удалить заявку\n3) Выйти\n";
	Map<char*, Aeroflot> MY(4);
	ifstream File("C:\\Exp\\Save.txt");
	char simvol[128];
	File.get(simvol, 128, ' ');
	char* fio = new char[100];
	char* pl = new char[100];
	int number;
	char* dd = new char[100];
	int i = 0;

	//Получение данных из файла
	while (simvol[0] != '\0')
	{
		if (i == 4)
		{
			i = 0;
			Aeroflot aero_save;
			MY.Put(fio, Aeroflot(fio, pl, number, dd));
			if (simvol[0] == '\n')
			{
				break;
			}
		}
		if (i == 0)
		{
			strcpy_s(fio, 100, simvol);
		}
		else
			if (i == 1)
			{
				strcpy_s(pl, 100, simvol);
			}
			else
				if (i == 2)
				{
					number = atoi(simvol);
				}
				else
					if (i == 3)
					{
						strcpy_s(dd, 100, simvol);
					}
		i++;
		File.get(simvol[0]);
		int a = 1;
		while (simvol[a] != '\0')
		{
			simvol[a] = NULL;
			a++;
		}
		File.get(simvol, 128, ' ');
		delete[] fio;
		delete[] pl;
		delete[] dd;
	}
	File.close();

	while (1)
	{
		system("CLS");
		Aeroflot* aero_flot = nullptr;
		MY.GetALL(aero_flot);
		Show(aero_flot, MY.Count());
		cout << Menu;
		int d;
		cin >> d;

		switch (d)
		{
		case 1:
		{
			Aeroflot aero;
			char* _fio = new char[100];
			char* _pl = new char[100];
			char* _dd = new char[100];
			int _num;
			cout << "Введите Фамилию и инициалы: ";
			cin >> _fio;
			cout << "Введите пункт назначения: ";
			cin >> _pl;
			cout << "Введите желаюмую дату вылета: ";
			cin >> _dd;
			cout << "Введите номер рейса: ";
			cin >> _num;
			aero.Add(_fio, _pl, _num, _dd);
			MY.Put(_fio, aero);
			delete[] _fio;
			delete[] _pl;
			delete[] _dd;
			break;
		}

		case 2:
		{
			cout << "Выберете № заявки, которую хотите удалить: ";
			int n;
			cin >> n;
			if (n > MY.Count())
			{
				cout << "Выбрана не существующая заявка";
				break;
			}

			for (int i = 0; i < MY.Count(); i++)
			{
				if ((n - 1) == i)
				{
					Aeroflot h = *MY.Get(i);
					MY.Del(h);
				}
			}
			break;
		}

		case 3:
		{
			ofstream Exit("C:\\Exp\\Save.txt");
			Aeroflot* arr_save = nullptr;
			MY.GetALL(arr_save);
			for (int i = 0; i < MY.Count(); i++)
			{
				Exit << arr_save[i];
			}
			Exit << "\n";
			Exit.close();
			return 0;
		}
		default:
		{
			cout << "Неверный номер";
			break;
		}
		}
	}
	return 0;
}