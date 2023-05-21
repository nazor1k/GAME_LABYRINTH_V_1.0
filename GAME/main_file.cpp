#include <iostream>
#include <conio.h>
#include <windows.h>
#include "main_head.h"
#include<ctime>
#include<time.h>
using namespace std;

const int width = 10;
const int height = 10;

const int width2 = 20;
const int height2 = 19;

const int width3 = 20;
const int height3 = 20;


int playerX = 1;
int playerY = 1;


int exitX = 0;
int exitY = 1;
int keyX = 2;
int keyY = 3;

int exit_and_key[3][4] = { {4,3,8,8}, {18,17,1,16}, {18,18,18,7} };
					   
int portals[4] = { 16,2,9,18 };
			   //{ y1,x1,y2,x2}
double time_player=0;
int score_player = 0;

const char B = char(219);
const char E = ' ';

int  number_map = 0;
bool collect_key = false;

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

void add_score_points(int w_h[3][2], char* map[],int num) {
	for (size_t i = 0; i < 20; i++)
	{
		int point_x = rand() % w_h[num][1];
		int point_y = rand() % w_h[num][0];
		if (map[num][point_x * w_h[num][0] + point_y] != B) {
			map[num][point_x * w_h[num][0] + point_y] = '$';
		}
	}
}


void drawMaze(char us_in, bool* collect,int w_h[3][2] , char* map[]) {
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
		player = 'v';
		break;
	default:
		player = '>';
	}
	
	
	for (int i = 0; i < w_h[number_map][1]; i++) {//     height
		for (int j = 0; j < w_h[number_map][0]; j++) {//    width
			if (i == playerY && j == playerX) {
				cout << player;
			}
			else if (i == exit_and_key[number_map][keyY] && j == exit_and_key[number_map][keyX]) {
				cout << "\033[38;2;255;200;100m" << '*' << "\033[0m";
			}
			else if (number_map==2 && (i == portals[0]&& j == portals[1] || i == portals[2] && j == portals[3])) {
				cout<<"\033[37;45m" << 'O' << "\033[0m";
			}
			else if ((i == exit_and_key[number_map][exitY] && j == exit_and_key[number_map][exitX]) && collect[0] == true) {
				cout << "\033[31;2m" << 'X' << "\033[0m";
			}
			else {
				cout << (map[number_map][i * w_h[number_map][0] + j]);//map[number_map][i][j]
			}
		}
		cout << endl;
	}
}

void movePlayer(char userInput, int w_h[3][2], char* map[]) {
	if (userInput == 'w' && map[number_map][(playerY - 1) * w_h[number_map][0] + (playerX)] != B) {
		playerY--;
	}
	else if (userInput == 's' && map[number_map][(playerY + 1) * w_h[number_map][0] + (playerX)] != B) {
		playerY++;
	}
	else if (userInput == 'a' && map[number_map][(playerY) * w_h[number_map][0] + (playerX-1)] != B) {
		playerX--;
	}
	else if (userInput == 'd' && map[number_map][(playerY) * w_h[number_map][0] + (playerX+1)] != B) {
		playerX++;
	}
}




void collect_key_or_exit(bool* c_k,int w_h[3][2], char* map[]) {
	if (playerX == exit_and_key[number_map][keyX] && playerY == exit_and_key[number_map][keyY]) {
		map[number_map][(exit_and_key[number_map][keyY] * w_h[number_map][0]) + exit_and_key[number_map][keyX]] = ' ';

		c_k[0] = true;
		exit_and_key[number_map][keyX] = -1;
		exit_and_key[number_map][keyY] = -1;
	}

	if (playerX == exit_and_key[number_map][exitX] && playerY == exit_and_key[number_map][exitY] && c_k[0] == true) {
		map[number_map][(playerY * w_h[number_map][0]) + playerX] = ' ';
		c_k[0] = false;
		system("cls");
		playerX = 1;
		playerY = 1;
		cout << "\033[38;2;0;200;0m" << "\nYou complete LEVEL - "<<number_map+1<<"!\n\n"<< "\033[0m";
		number_map++;
		Sleep(1000);
		system("cls");
	}
	if(number_map != 3){
		if (map[number_map][(playerY * w_h[number_map][0]) + playerX] == '$') {
			map[number_map][(playerY * w_h[number_map][0]) + playerX] = ' ';
			score_player++;
		}
	
	}
	



	if (number_map == 2 && (playerY == portals[0] && playerX == portals[1] || playerY == portals[2] && playerX == portals[3])) {
		cout <<"\033[38;2;0;200;0m" <<
				"\n--------------------------------"
				"\n|                              |"
				"\n| PRESS ANY BUTTON TO CONTINUE |"
				"\n|                              |"
				"\n--------------------------------"
				"\033[0m";
		_getch();
		
		if (playerY == portals[0] && playerX == portals[1]) {
		playerX = portals[3];
		playerY = portals[2];
		}
		else if (playerY == portals[2] && playerX == portals[3]) {
			playerX = portals[1];
			playerY = portals[0];
		}
		
		
	}
}



	


void game() {
	srand(time(0));
	int w_h[3][2] = { {10,10}, {20,19},{20,20} };
	char* map[3] = { *maze, *maze2,*maze3 };
	/*int number_map = 0;
	int* ptr_number_map= &number_map ;*/
	char userInput = '>';
	bool* collect = new bool[1];
	collect[0] = false;
	for (size_t i = 0; i < 3; i++)
	{
		add_score_points(w_h, map, i);
	}
	int start = clock();
	while (number_map!=3) {
		
		drawMaze(userInput, collect,w_h,map);
		
		userInput = _getch();
		movePlayer(userInput,w_h, map);
		collect_key_or_exit(collect, w_h,map);

	}
	int end = clock();
	time_player = ((double(end) - double(start)) / CLOCKS_PER_SEC) - 2;
	/*system("cls");*/
	std::cout << " +-----------------------+"
		<< "\n     Congratulations !\n"
		<< "      You have passed \n"
		<< "         the game!\n\n"
		<< "     YOUR SCORE: " << score_player
		<< "\n     YOUR TIME: " << time_player
		<< "\n +-----------------------+" << std::endl;

	delete[] collect;
}
