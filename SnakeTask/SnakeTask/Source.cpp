#include <iostream>
using namespace std;
bool gameOver;
int w = 30;
int h = 30;
int x, y, appleX, appleY, schet;
enum commands { STOP = 0, LEFT, RIGHT, UP, DOWN };
commands a;

void Param()
{
	gameOver = false;
	a = STOP;
	x = 40;
	y = 15;
	appleX = rand() % 29+1;
	appleY = rand() % 29+1;
	schet = 0;
}

void Pole()
{
	system("cls");
	for (int i = 0; i < w; i++)
	{
		cout << "x";
	}
	    cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (j == 0)
			{
				if (j == w - 1)
					cout << "x";
			}
			else
			cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < w; i++)
		cout << "x";
}

void Command() 
{

}

void Logic()
{

}

int main()
{
	void Param();
	if (!gameOver)
	{
		void Pole();
		void Command();
	}
	else
		system("pause");
	return 0;
}