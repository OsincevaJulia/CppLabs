#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "x, y, z: ";
	int x, y, z;
	cin >> x >> y >> z;
	double a, b;
	a = y + (x / (y*y + fabs(x*x / (y + (x*x*x / 3)))));
	b = (1 + tan(z / 2)*tan(z / 2));
	cout << "a= " << a<<"\n";
	cout << "b= " << b << "\n";
	return 0;
}