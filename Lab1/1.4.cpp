#include <iostream>
using namespace std;
int main()//Íàéòè êîëè÷åñòâî ÷åòíûõ öèôð â öåëîì ÷èñëå, ââåäåííîì ñ êëàâèàòóðû.
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
	return 0;
}
