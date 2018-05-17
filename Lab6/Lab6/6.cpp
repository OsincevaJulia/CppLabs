/*Составить описание класса для объектов-векторов, задаваемых модулем (длинной) и 
углом относительно оси абсцисс. Обеспечить операции сложения и вычитания векторов с 
получением нового вектора (суммы и разности), вычисления скалярного произведения двух векторов.
Все операции реализовать в виде перегрузки операторов.
Программа должна содержать меню, позволяющее осуществлять проверку всех методов.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Vector
{
private:
	double leght;
	double corner;
public:
	Vector()
	{
		leght = 0;
		corner = 0;
	}
	Vector(double leght, double corner)// конструктор
	{
		this->leght = leght;
		this->corner = corner;
	}
	Vector(const Vector &other) //конструктор копирования
	{
		this->leght = other.leght;
		this->corner = other.corner;
	}

	Vector & operator = (const Vector &other)
	{
		this->leght = other.leght;
		this->corner = other.corner;
		return *this;
	} 

	Vector operator +(const Vector &other)
	{
		Vector temp;
		temp.corner = 360-this->corner + other.corner;
		if (temp.corner > 180)
		{
			temp.corner = 360 - temp.corner;
		};
		temp.leght = sqrt((this->leght*this->leght) + (other.leght*other.leght) + (2 * this->leght*other.leght*temp.corner));
		return temp;
	}
	
	Vector operator -(const Vector &other)
	{
		Vector temp;
		double corner2 = other.corner;
		if (corner2 < 180)
			corner2 =corner2 + 180;
		else
			corner2 = corner2 - 180;

		temp.corner = 360 - this->corner + other.corner;
		if (temp.corner > 180)
		{
			temp.corner = 360 - temp.corner;
		};
		temp.leght = sqrt((this->leght*this->leght) + (other.leght*other.leght) + (2 * this->leght*other.leght*temp.corner));
		return temp;
	}

	Vector operator *(const Vector &other)
	{
		Vector temp;
		temp.corner = 360 - this->corner + other.corner;
		if (temp.corner > 180)
		{
			temp.corner = 360 - temp.corner;
		};
		temp.leght = this->leght*other.leght*temp.corner;
		return temp;
	}

	friend ostream &operator<<(ostream &out, Vector &p) // перегрузка вывода (!)
	{
		out  << p.leght  << p.corner <<  endl;
		return out;
	}

	friend istream &operator >> (istream &in, Vector &p) // перегрузка ввода (!)
	{
		in >> p.leght >> p.corner;
		return in;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "Выберите пункт меню: " << endl;
	cout << "1.Сложение векторов." << endl;
	cout << "2.Вычитание векторов." << endl;
	cout << "3.Вычисление скалярного произведения векторов." << endl;
	cin >> n;

		switch (n)
		{

		case 1:
		{
			cout << "Введите количество векторов: ";
			int n;
			cin >> n;
			Vector *Add = new Vector[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Введите длину и угол(от 0 до 360) " << i+1 << " вектора: ";
				cin >> Add[i];
			};
			cout << "Введите номер первого вектора: ";
			int Number1, Number2;
			cin >> Number1;
			cout << "Введите номер второго вектора: ";
			cin >> Number2;
			Vector Sum = Add[Number1] + Add[Number2];
			cout << "Сумма векторов равна: " << Sum;
			break;
		};
		case 2:
		{
			cout << "Введите количество векторов: ";
			int n;
			cin >> n;
			Vector *Add = new Vector[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Введите длину и угол(от 0 до 360) " << i + 1 << " вектора: ";
				cin >> Add[i];
			};
			cout << "Введите номер первого вектора: ";
			int Number1, Number2;
			cin >> Number1;
			cout << "Введите номер второго вектора: ";
			cin >> Number2;
			Vector Dif = Add[Number1] - Add[Number2];
			cout << "Разность векторов равна: " << Dif;
			break;
		};
		case 3:
		{
			cout << "Введите количество векторов: ";
			int n;
			cin >> n;
			Vector *Add = new Vector[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Введите длину и угол(от 0 до 360) " << i + 1 << " вектора: ";
				cin >> Add[i];
			};
			cout << "Введите номер первого вектора: ";
			int Number1, Number2;
			cin >> Number1;
			cout << "Введите номер второго вектора: ";
			cin >> Number2;
			Vector Mul = Add[Number1] * Add[Number2];
			cout << "Скалярное произведение векторов равно: " << Mul;
			break;
		};

		default:
			cout << "Некорректный ввод." << endl;
		};
	system("pause");
	return 0;
}