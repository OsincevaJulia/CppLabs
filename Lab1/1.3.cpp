#include <iostream>
#include <cmath>
using namespace std;
int main()//Äàíî íàòóðàëüíîå ÷èñëî. Ïðèïèñàòü ê íåìó òàêîå æå ÷èñëî ñëåâà
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
	return 0;
}
