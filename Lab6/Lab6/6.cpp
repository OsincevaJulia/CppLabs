/*��������� �������� ������ ��� ��������-��������, ���������� ������� (�������) � 
����� ������������ ��� �������. ���������� �������� �������� � ��������� �������� � 
���������� ������ ������� (����� � ��������), ���������� ���������� ������������ ���� ��������.
��� �������� ����������� � ���� ���������� ����������.
��������� ������ ��������� ����, ����������� ������������ �������� ���� �������.
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
	Vector(double leght, double corner)// �����������
	{
		this->leght = leght;
		this->corner = corner;
	}
	Vector(const Vector &other) //����������� �����������
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

	friend ostream &operator<<(ostream &out, Vector &p) // ���������� ������ (!)
	{
		out  << p.leght  << p.corner <<  endl;
		return out;
	}

	friend istream &operator >> (istream &in, Vector &p) // ���������� ����� (!)
	{
		in >> p.leght >> p.corner;
		return in;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "�������� ����� ����: " << endl;
	cout << "1.�������� ��������." << endl;
	cout << "2.��������� ��������." << endl;
	cout << "3.���������� ���������� ������������ ��������." << endl;
	cin >> n;

		switch (n)
		{

		case 1:
		{
			cout << "������� ���������� ��������: ";
			int n;
			cin >> n;
			Vector *Add = new Vector[n];
			for (int i = 0; i < n; i++)
			{
				cout << "������� ����� � ����(�� 0 �� 360) " << i+1 << " �������: ";
				cin >> Add[i];
			};
			cout << "������� ����� ������� �������: ";
			int Number1, Number2;
			cin >> Number1;
			cout << "������� ����� ������� �������: ";
			cin >> Number2;
			Vector Sum = Add[Number1] + Add[Number2];
			cout << "����� �������� �����: " << Sum;
			break;
		};
		case 2:
		{
			cout << "������� ���������� ��������: ";
			int n;
			cin >> n;
			Vector *Add = new Vector[n];
			for (int i = 0; i < n; i++)
			{
				cout << "������� ����� � ����(�� 0 �� 360) " << i + 1 << " �������: ";
				cin >> Add[i];
			};
			cout << "������� ����� ������� �������: ";
			int Number1, Number2;
			cin >> Number1;
			cout << "������� ����� ������� �������: ";
			cin >> Number2;
			Vector Dif = Add[Number1] - Add[Number2];
			cout << "�������� �������� �����: " << Dif;
			break;
		};
		case 3:
		{
			cout << "������� ���������� ��������: ";
			int n;
			cin >> n;
			Vector *Add = new Vector[n];
			for (int i = 0; i < n; i++)
			{
				cout << "������� ����� � ����(�� 0 �� 360) " << i + 1 << " �������: ";
				cin >> Add[i];
			};
			cout << "������� ����� ������� �������: ";
			int Number1, Number2;
			cin >> Number1;
			cout << "������� ����� ������� �������: ";
			cin >> Number2;
			Vector Mul = Add[Number1] * Add[Number2];
			cout << "��������� ������������ �������� �����: " << Mul;
			break;
		};

		default:
			cout << "������������ ����." << endl;
		};
	system("pause");
	return 0;
}