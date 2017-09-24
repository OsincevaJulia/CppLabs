#include <iostream>
using namespace std;
int main()
{
	double a, b, c;
	cout << "vvedite storony kyrpicha: ";
	cin >> a>> b>> c;
	double x>> y;
	cout << "vvedite storony otverstiya: ";
	cin >> x, y;
	if (a*b < x*y)
		cout << "Kyrpich proidyot v otverstie.";
	else
		if (b*c < x*y)
			cout << "Kyrpich proidyot v otverstie.";
		else
			if (a*c < x*y)
				cout << "Kyrpich proidyot v otverstie.";
			else cout << "Kyrpich ne proidyot v otverstie.";
			return 0;
}