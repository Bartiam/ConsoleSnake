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

void Setup() {
	score = 0;
	gameOver = false;
	dir = STOP;
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
		fruitX = rand() % height - 1;
		fruitY = rand() % width - 1;
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
				cout << " ";
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
}

void Logic(Snake& snake, Fruit& fruit) {
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
			gameOver = true;
			break;
		}
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
				break;
			}
			else if (way == 2)
			{
				gameOver = true;
				break;
			}
			else
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
					break;
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
			if (way == 2)
			{
				gameOver = true;
			}
			else
			{
				continues = 3;
			}
		}
	}
	if (snake.getSnakeX() == fruit.getFruitX()
		&& snake.getSnakeY() == fruit.getFruitY())
	{
		score++;
		fruit.setFruitX(rand() % height - 1);
		fruit.setFruitY(rand() % width - 1);
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
		Logic(snake, fruit);
		Input(snake);
	}













	return 0;
}