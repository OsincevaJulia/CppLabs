#include <iostream>
using namespace std;
int main()//����� ���������� ������ ���� � ����� �����, ��������� � ����������.
{
	int x;
	cout << "Vvedite chislo: ";
	cin >> x;
	int b = 0;
	while (x > 0)
	{
		int z;
		z = x % 10;
		if (z % 2 == 0)
			b = b + 1;
		else b = b;
		x = x / 10;
	}
	cout << b;
}