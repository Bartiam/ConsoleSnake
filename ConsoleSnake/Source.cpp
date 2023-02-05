#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

const int height = 26;
const int width = 100;
int score;
int continues = 3;
bool gameOver;
enum Dir {STOP = 0, LEFT, RIGHT, UP, DOWN};
Dir dir;
int indexTailX[(height - 1) * (width - 1)];
int indexTailY[(height - 1) * (width - 1)];
int countTail;

void Setup() {
	score = 0;
	gameOver = false;
	dir = STOP;
	countTail = 0;
}

class Snake {
private:
	int snakeX;
	int snakeY;
public:
	Snake() {
		snakeX = height / 2 - 1;
		snakeY = width / 2 - 1;
	}

	void setSnakeX(int snakeX) {
		this->snakeX = snakeX;
	}

	void setSnakeY(int snakeY) {
		this->snakeY = snakeY;
	}

	int getSnakeX() {
		return snakeX;
	}

	int getSnakeY() {
		return snakeY;
	}
};

class Fruit {
private:
	int fruitX;
	int fruitY;

public:
	Fruit() {
		fruitX = rand() % (height - 1) + 0;
		fruitY = rand() % (width - 1) + 0;
	}

	void setFruitX(int fruitX) {
		this->fruitX = fruitX;
	}

	void setFruitY(int fruitY) {
		this->fruitY = fruitY;
	}

	int getFruitX() {
		return fruitX;
	}

	int getFruitY() {
		return fruitY;
	}
};

void Draw(Snake& snake, Fruit& fruit) {
	
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width -1) {
				cout << "#";
			}
			else if (i == snake.getSnakeX() && j == snake.getSnakeY())
			{
				cout << "@";
			}
			else if (i == fruit.getFruitX() && j == fruit.getFruitY())
			{
				cout << "F";
			}
			else {
				bool print = false;
				for (int k = 0; k < score; k++)
				{
					if (i == indexTailX[k] && j == indexTailY[k])
					{
						print = true;
						cout << "o";
					}
				}
				if (!print)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	
	cout << endl << "Your score: " << score << endl;

	system("cls");
}

void Input(Snake& snake) {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			if (dir != RIGHT) {
				dir = LEFT;
			}
			break;
		case 'd':
			if (dir != LEFT) {
				dir = RIGHT;
			}
			break;
		case 'w':
			if (dir != DOWN)
			{
				dir = UP;
			}
			break;
		case 's':
			if (dir != UP)
			{
				dir = DOWN;
			}
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic(Snake& snake, Fruit& fruit) {
	int prevTailX = indexTailX[0];
	int prevTailY = indexTailY[0];
	int prevTailX2, prevTailY2;
	indexTailX[0] = snake.getSnakeX();
	indexTailY[0] = snake.getSnakeY();
	for (int i = 1; i < countTail; i++)
	{
		prevTailX2 = indexTailX[i];
		prevTailY2 = indexTailY[i];
		indexTailX[i] = prevTailX;
		indexTailY[i] = prevTailY;
		prevTailX = prevTailX2;
		prevTailY = prevTailY2;
	}
	switch (dir)
	{
	case LEFT:
		snake.setSnakeY(snake.getSnakeY() - 1);
		break;
	case RIGHT:
		snake.setSnakeY(snake.getSnakeY() + 1);
		break;
	case UP:
		snake.setSnakeX(snake.getSnakeX() - 1);
		break;
	case DOWN:
		snake.setSnakeX(snake.getSnakeX() + 1);
		break;
	}

	if (snake.getSnakeX() == height || snake.getSnakeY() == width -1
		|| snake.getSnakeX() == -1 || snake.getSnakeY() == 0)
	{
		while (true)
		{
			int way;
			cout << "\n\n\n\n\n\n\n\n\n\n\t\tВы проиграли. Хотите использовать жизнь и продолжить ? Введите ответ." << endl;
			cout << "\t\t\t\t\t\t1.Да " << endl << "\t\t\t\t\t\t2.Нет " << endl << "\t\t\t\t\t\t";
			cin >> way;
			system("cls");

			if (way == 1)
			{
				continues--;
				snake.setSnakeX(height / 2 - 1);
				snake.setSnakeY(width / 2 - 1);
				fruit.setFruitX(rand() % (height - 1) + 1);
				fruit.setFruitY(rand() % (width - 1) + 1);
				dir = STOP;
				break;
			}
			else if (way == 2)
			{
				gameOver = true;
				break;
			}

			if (way != 1 && way != 2)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\t\tХотите использовать жизнь и продолжить ? Введите 1 или 2." << endl;
				cout << "\t\t\t\t\t\t1.Да " << endl << "\t\t\t\t\t\t2.Нет " << endl << "\t\t\t\t\t\t";
				cin >> way;
				system("cls");

				if (way == 1)
				{
					continues--;
					snake.setSnakeX(height / 2 - 1);
					snake.setSnakeY(width / 2 - 1);
					fruit.setFruitX(rand() % (height - 1) + 1);
					fruit.setFruitY(rand() % (width - 1) + 1);
					dir = STOP;
					break;
				}
				else if (way == 2)
				{
					gameOver = true;
					break;
				}
				else
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\t\tВы дважды ввели несуществующее значение меню, завершение игры." << endl;
					gameOver = true;
				}
				break;
			}
		}

		if (continues == 0)
		{
			int way;
			cout << "\n\n\n\n\n\n\n\n\n\n\t\tУ вас закончились жизни, хотите начать сначала ? " << endl;
			cout << "\t\t\t\t\t\t1.Да " << endl << "\t\t\t\t\t\t2.Нет " << endl << "\t\t\t\t\t\t";
			cin >> way;
			system("cls");

			if (way == 2)
			{
				gameOver = true;
			}
			else if (way == 1)
			{
				continues = 3;
			}
			else
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\t\tВы ввели несуществующее значение меню, завершение игры." << endl;
				gameOver = true;
			}
		}
	}

	for (int i = 0; i < countTail; i++)
	{
		if (indexTailX[i] == snake.getSnakeX() && indexTailY[i] == snake.getSnakeY())
		{
			int way;
			cout << "\n\n\n\n\n\n\n\n\n\n\t\tВы проиграли. Хотите использовать жизнь и продолжить ? Введите ответ." << endl;
			cout << "\t\t\t\t\t\t1.Да " << endl << "\t\t\t\t\t\t2.Нет " << endl << "\t\t\t\t\t\t";
			cin >> way;
			system("cls");

			if (way == 1)
			{
				continues--;
				snake.setSnakeX(height / 2 - 1);
				snake.setSnakeY(width / 2 - 1);
				fruit.setFruitX(rand() % (height - 1) + 1);
				fruit.setFruitY(rand() % (width - 1) + 1);
				dir = STOP;
				break;
			}
			else if (way == 2)
			{
				gameOver = true;
				break;
			}
		}
	}

	if (snake.getSnakeX() == fruit.getFruitX()
		&& snake.getSnakeY() == fruit.getFruitY())
	{
		score += 10;
		countTail++;
		fruit.setFruitX(rand() % (height - 1) + 1);
		fruit.setFruitY(rand() % (width - 1) + 1);
	}
}

int main() {
	srand(time(NULL));
	Snake snake;
	Fruit fruit;
	Setup();
	while (!gameOver)
	{
		Draw(snake, fruit);
		Input(snake);
		Logic(snake, fruit);
	}











	
	return 0;
}