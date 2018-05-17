#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include <ctime>

using namespace std;


class Snake
{
public:
	bool gameOver;
	char name;
	const int width = 50;//ширина
	const int height = 30;//высота
	int x, y, fruitX, fruitY, score;
	Snake()
	{
		srand(width);
		srand(height);
		fruitX = rand() % width;
		fruitY = rand() % height;
		score = 0;
	}
};

class Game
{
public:
	Game()
	{
		dir = STOP;
		nTail = 0;
	}
	int tailX[100], tailY[100];
	int nTail;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;

	void Setup(Snake &snake);
	void Input();
	void Draw(Snake &snake);
	void Logic(Snake &snake);
};





void Game::Setup(Snake &snake)
{
	snake.gameOver = false;
	snake.x = snake.width / 2 - 1;
	snake.y = snake.height / 2 - 1;

	Draw(snake);
	Input();
	Logic(snake);

}

void Game::Draw(Snake &snake)
{
	system("cls");
	for (int i = 0; i < snake.width + 2; i++)
		cout << "x";
	cout << endl;

	for (int i = 0; i < snake.height; i++)
	{
		for (int j = 0; j < snake.width; j++)
		{
			if (j == 0)
				cout << "x";

			if (i == snake.y && j == snake.x)
				cout << "O";

			else if (i == snake.fruitY && j == snake.fruitX)
				cout << "*";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << 'o';
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == snake.width - 1)
				cout << "x";
		}
		cout << endl;
	}

	for (int i = 0; i < snake.width + 2; i++)
		cout << "x";
	cout << endl;
	cout << "Score: " << snake.score << endl;

}

void Game::Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			dir = STOP;
			break;
		}
	}
}

void Game::Logic(Snake &snake)
{
	if (dir != STOP)
	{
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = snake.x;
		tailY[0] = snake.y;
		for (int i = 1; i < nTail; i++) {
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		switch (dir)
		{
		case LEFT:
			snake.x--;
			break;
		case RIGHT:
			snake.x++;
			break;
		case UP:
			snake.y--;
			break;
		case DOWN:
			snake.y++;
			break;
		}

		if (snake.x > snake.width || snake.x < 0 || snake.y > snake.height || snake.y < 0)
			snake.gameOver = true;

		for (int i = 0; i < nTail; i++) {
			if (tailX[i] == snake.x && tailY[i] == snake.y)
				snake.gameOver = true;
		}


		if (snake.x == snake.fruitX && snake.y == snake.fruitY) {
			snake.score += 10;
			snake.fruitX = rand() % snake.width;
			snake.fruitY = rand() % snake.height;
			nTail++;
		}
	}
}

int main() {
	Snake snake;
	Game Sn;
	Sn.Setup(snake);
	while (!snake.gameOver)
	{
		Sn.Draw(snake);
		Sn.Input();
		Sn.Logic(snake);
		Sleep(300);
	}
	Sn.Setup(snake);
	char n;
	cout << "Enter the name" << endl;
	cin >> n;
	cout << "Your score: " << snake.score << endl;
	system("pause");
	return 0;
}