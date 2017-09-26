#include <iostream>
#include <cmath>
using namespace std;
int main()//Дано натуральное число. Приписать к нему такое же число слева
{
	int x,y;
	cout << "Vvedite chislo: ";
	cin >> x;
	y = x;
	int r = 0;
	while (x != 0)
	{
		x = x / 10;
		r = r + 1;
	}
	int a;
	a = y*(pow(10, r));
	x = a + y;
	cout<< x;
}