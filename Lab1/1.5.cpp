#include <iostream>
using namespace std;
int main()//���� �������������� ����� a � ����������� ����� n. ��������� a(a+1)�(a+n-1).
{
	int a, n;
	cout << "a, n: ";
	cin >> a >> n;
	int r, b;
	r = 1;
	b = n - 1;
	for (n = 0; n <= b; n++)
		r = r*(a + n);
	cout << "Resultat: " << r;
}