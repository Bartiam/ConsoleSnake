#include <iostream>
#include <ctime>

using namespace std;

const int height = 26;
const int width = 100;
int score;
bool gameOver;

enum Dir {
	STOP = 0, LEFT, RIGHT, UP, DOWN
};

void Setup() {
	score = 0;
	gameOver = false;
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

	void setFruitY() {
		this->fruitY = fruitY;
	}

	int getFruitX() {
		return fruitX;
	}

	int getFruitY() {
		return fruitY;
	}
};

void Draw(Snake &snake, Fruit &fruit) {
	
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
	
	cout << endl << score << endl;

	system("cls");
}



int main() {
	srand(time(NULL));
	Snake snake;
	Fruit fruit;
	while (true)
	{
		Draw(snake, fruit);
	}













	return 0;
}