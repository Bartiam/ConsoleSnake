#include <iostream>

using namespace std;


const int height = 26;
const int Width = 100;
int x, y, score, snakeIndex;

void Setup() {
	
}

void Draw() {
	for (int i = 0; i < Width; i++)
	{
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < Width; j++) {
			if (j == 0 || j == Width -1) {
				cout << "#";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < Width; i++)
	{
		cout << "#";
	}
	system("cls");
}



int main() {
	
	
	while (true)
	{
		Draw();
	}













	return 0;
}