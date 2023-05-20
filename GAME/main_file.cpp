#include <iostream>
#include <conio.h>
#include <windows.h>
#include "main_head.h"

const int width = 10;
const int height = 10;

const int width2 = 20;
const int height2 = 19;

const int width3 = 20;
const int height3 = 20;


int playerX = 1;
int playerY = 1;

int keyX = 8;
int keyY = 8;

int exitX = 4;
int exitY = 3;

const char B = 219;
const char E = ' ';






char maze[height][width] = {
   {B, B, B, B, B, B, B, B, B, B},
   {B, E, E, E, E, E, E, E, E, B},
   {B, E, B, B, B, B, E, B, E, B},
   {B, E, B, E, E, B, E, E, E, B},
   {B, E, B, E, B, B, B, B, E, B},
   {B, E, B, E, E, E, E, B, E, B},
   {B, E, B, B, B, B, E, B, E, B},
   {B, E, E, E, E, B, E, E, E, B},
   {B, B, E, B, E, E, E, B, E, B},
   {B, B, B, B, B, B, B, B, B, B}
};

char maze2[height2][width2] = {
		{B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
		{B, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, B, E, B},
		{B, E, B, B, B, B, B, B, B, B, B, B, B, B, B, B, E, B, E, B},
		{B, E, E, E, B, E, E, B, E, E, E, B, E, E, E, B, E, E, E, B},
		{B, B, B, E, B, B, E, B, E, B, E, E, E, B, E, B, B, B, E, B},
		{B, E, B, E, E, E, E, B, E, B, B, B, B, B, E, B, E, E, E, B},
		{B, E, E, E, B, E, E, E, E, E, E, E, E, B, E, B, B, B, E, B},
		{B, B, B, E, B, B, B, B, B, B, B, B, E, B, E, B, E, E, E, B},
		{B, E, E, E, E, E, E, E, E, E, E, B, E, B, E, B, E, E, B, B},
		{B, B, B, B, B, B, B, B, E, B, B, B, E, B, E, B, E, E, E, B},
		{B, E, E, B, E, E, E, E, E, B, E, E, E, B, E, B, E, B, E, B},
		{B, E, B, B, E, B, B, B, B, B, E, E, B, B, E, B, B, B, E, B},
		{B, E, B, E, E, E, E, B, E, B, B, E, E, B, E, B, E, E, E, B},
		{B, E, E, E, B, E, E, E, E, B, E, E, E, B, E, E, E, B, E, B},
		{B, E, E, E, B, B, B, E, E, B, E, B, B, B, B, B, B, B, E, B},
		{B, B, B, B, B, E, B, B, E, B, E, E, E, B, E, E, E, B, E, B},
		{B, E, B, E, E, E, E, E, E, B, E, E, E, E, E, E, B, E, E, B},
		{B, E, E, E, E, E, B, E, E, B, E, E, E, E, E, E, B, E, E, B},
		{B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}

};

char maze3[height3][width3] = {
		{B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
		{B, E, E, E, E, E, B, E, E, B, E, E, E, B, E, B, E, E, E, B},
		{B, E, B, B, B, E, B, B, E, B, E, B, E, B, E, B, E, B, E, B},
		{B, E, E, E, B, E, B, E, E, B, E, B, E, B, E, E, E, B, E, B},
		{B, B, B, E, B, E, E, E, E, B, E, B, E, E, E, B, B, B, E, B},
		{B, E, E, E, B, E, E, B, E, B, E, B, B, B, E, B, E, E, E, B},
		{B, B, B, B, B, E, E, B, E, B, E, B, E, E, E, B, E, B, E, B},
		{B, E, B, E, E, E, E, B, E, E, E, B, E, E, E, B, E, B, E, B},
		{B, E, B, E, E, B, B, B, B, B, E, B, B, E, E, B, E, B, B, B},
		{B, E, E, E, E, B, E, E, E, E, E, E, B, E, E, B, E, B, E, B},
		{B, E, B, E, E, B, E, B, B, B, B, B, B, B, B, B, E, B, E, B},
		{B, E, B, E, E, B, E, B, E, E, E, E, B, E, E, E, E, B, E, B},
		{B, E, B, B, B, B, E, B, E, B, B, E, B, E, B, B, B, B, E, B},
		{B, E, E, E, E, E, E, B, E, B, E, E, E, E, E, B, E, B, E, B},
		{B, E, E, E, E, E, E, B, E, B, E, E, B, E, E, B, E, B, E, B},
		{B, B, B, B, B, B, B, B, E, B, B, B, B, B, E, E, E, B, E, B},
		{B, E, E, B, E, E, E, E, E, E, E, E, E, B, B, B, E, B, E, B},
		{B, E, B, B, E, B, E, E, B, B, B, E, E, E, E, E, E, B, E, B},
		{B, E, E, E, E, B, E, E, B, E, E, E, E, E, E, B, E, B, E, B},
		{B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B}

};


void drawMaze(char us_in, bool* collect,char** map,int* w_h,int* number_map) {
	system("cls");
	char player;
	switch (us_in) {
	case 'w':
		player = '^';
		break;
	case 'a':
		player = '<';
		break;
	case 's':
		player = '.';
		break;
	case 'd':
		player = '>';
		break;
	default:
		player = '>';
	}
	 
	for (int i = 0; i < w_h[1]; i++) {
		for (int j = 0; j < width; j++) {
			if (i == playerY && j == playerX) {
				std::cout << player;
			}
			else if (i == keyY && j == keyX) {
				std::cout << '*';
			}
			else if ((i == exitY && j == exitX) && collect[0] == true) {
				std::cout << 'X';
			}
			else {
				std::cout << maze[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void movePlayer(char userInput,char* arr) {
	if (userInput == 'w' && arr[playerY - 1][playerX] != B) {
		playerY--;
	}
	else if (userInput == 's' && arr[playerY + 1][playerX] != B) {
		playerY++;
	}
	else if (userInput == 'a' && arr[playerY][playerX - 1] != B) {
		playerX--;
	}
	else if (userInput == 'd' && arr[playerY][playerX + 1] != B) {
		playerX++;
	}
}

void collect_key_or_exit(bool* c_k) {
	if (playerX == keyX && playerY == keyY) {
		maze[keyY][keyX] = ' ';
		c_k[0] = true;
		keyX = -1;
		keyY = -1;
	}
}

void game() {
	int w_h[3][2] = { {10,10}, {20,19},{20,20} };
	char* map[3] = { *maze, *maze2,*maze3 };
	int* number_map[1] = {0};
	char userInput = '>';
	bool* collect = new bool[2];
	collect[0] = false;

	while (true) {
		drawMaze(userInput, collect,map,w_h,number_map);
		userInput = _getch();
		movePlayer(userInput,map[0]);
		collect_key_or_exit(collect);
	}
}

int main() {
	game();
	return 0;
}
