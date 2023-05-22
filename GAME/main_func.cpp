#include <iostream>
#include <conio.h>
#include <windows.h>
#include<ctime>
#include<time.h>
using namespace std;

//player_position
int playerX = 1;
int playerY = 1;

bool play_stat = true;

//EXIT AND KEY AND TELEPORT position
const int exitX = 0;
const int exitY = 1;
const int keyX = 2;
const int keyY = 3;
int exit_and_key[3][4] = { {4,3,8,8}, {18,17,1,16}, {18,18,18,7} };
const int portals[4] = { 16,2,9,18 };//{ y1,x1,y2,x2}


//player_stats
double time_player = 0;
int score_player = 0;

//MAPS SYMBOL
const char B = char(219);
const char E = ' ';

int select_map = 2;
int selectedOption = 0;
int  number_map = 0;
bool collect_key = false;


char maze[10][10] = {
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

char maze2[19][20] = {
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

char maze3[20][20] = {
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


void enter_to_action() {
	cout << "\033[38;2;0;200;0m" <<
		"\n--------------------------------"
		"\n|                              |"
		"\n|PRESS ENTER BUTTON TO TELEPORT|"
		"\n|                              |"
		"\n--------------------------------"
		"\033[0m";
}

char player_direction(char us_in) {
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
	return player;
}


void START_func(char us_in, bool* collect, int w_h[3][2], char* map[]) {
	int start = clock();

	while (number_map != 3) {

		drawMaze(us_in, collect, w_h, map);

		us_in = _getch();
		movePlayer(us_in, w_h, map);
		collect_key_or_exit_or_teleport_or_point(collect, w_h, map);

	}
	int end = clock();

	print_end_stats(start, end);
}

void LEVELS_func(char us_in, bool* collect, int w_h[3][2], char* map[]) {
	int start = clock();
	int key = NULL;

	while (key != 13) {
		// Очищення екрану
		system("cls");

		// Вивід меню
		cout << "+======== MENU ========+" << endl << endl;
		cout << "\t" << ((select_map == 0) ? "\033[30;47m> " : "  ") << "LEVEL 1" << "\033[0m" << endl;
		cout << "\t" << ((select_map == 1) ? "\033[30;47m> " : "  ") << "LEVEL 2" << "\033[0m" << endl;
		cout << "\t" << ((select_map == 2) ? "\033[30;47m> " : "  ") << "LEVEL 3" << "\033[0m" << endl;
		cout << "\n+======================+" << endl << endl;
		// Зчитування введеного символу
		key = _getch();

		// Перевірка натиснутої клавіші
		switch (key) {
		case 'w':
			select_map = (select_map - 1 + 3) % 3;  // Перехід до попереднього пункту
			break;
		case 's':
			select_map = (select_map + 1) % 3;  // Перехід до наступного пункту
			break;

		}
	}
	number_map = select_map;
	while (number_map == select_map) {

		drawMaze(us_in, collect, w_h, map);

		us_in = _getch();
		movePlayer(us_in, w_h, map);
		collect_key_or_exit_or_teleport_or_point(collect, w_h, map);

	}
	int end = clock();

	print_end_stats(start, end);
}

void INFO_func() {
	system("cls");
		cout << "+======================== INFO ========================+" << endl << endl;
		cout << "\033[37m " << "  " << "Greetings, you are in the game Labyrinth" << "\033[0m" << endl;
		cout << "\033[37m " << "  " << "Small hints for passing the maze" << "\033[0m" << endl;
		cout << "\033[37m " << "  " << "1) '*'-is a key, yellow in color, which is\n necessary to go to the next level" << "\033[0m" << endl;
		cout << "\033[37m " << "  " << "2) 'X' will appear after picking up the key,\n and will be red color" << "\033[0m" << endl;
		cout << "\033[37m " << "  " << "3) '$' is the coins you can raise for the best\n score,at the end of the game you will see your score" << "\033[0m" << endl;
		cout << "\033[37m " << "  " << "4) The 'Purple Icon' is a portal that will help\n send you to closed areas of the maze" << "\033[0m" << endl;
		cout << "\033[37m " << "  " << "Game made by Hus Artem and Korobchyk Nazar" << "\033[0m" << endl;
		cout << "\033[37m " << "  " << "For exit, press any button" << "\033[0m" << endl;
		cout << "\n+====================================================+" << endl << endl;
	
}



void main_menu() {
	selectedOption = 0;
	int key = NULL;

	while (key != 13) {
		// Очищення екрану
		system("cls");

		// Вивід меню
		cout << "+======== MENU ========+" << endl << endl;
		cout << "\t" << ((selectedOption == 0) ? "\033[30;47m> " : "  ") << "START" << "\033[0m" << endl;
		cout << "\t" << ((selectedOption == 1) ? "\033[30;47m> " : "  ") << "LEVELS" << "\033[0m" << endl;
		cout << "\t" << ((selectedOption == 2) ? "\033[30;47m> " : "  ") << "INFO" << "\033[0m" << endl;
		cout << "\t" << ((selectedOption == 3) ? "\033[30;47m> " : "  ") << "EXIT" << "\033[0m" << endl;
		cout << "\n+======================+" << endl << endl;
		// Зчитування введеного символу
		key = _getch();

		// Перевірка натиснутої клавіші
		switch (key) {
		case 'w':
		case 'W':
			selectedOption = (selectedOption - 1 + 4) % 4;  // Перехід до попереднього пункту
			break;
		case 's':
		case 'S':
			selectedOption = (selectedOption + 1) % 4;  // Перехід до наступного пункту
			break;

		}
	}
}



void print_end_stats(int start, int end) {
	time_player = ((double(end) - double(start)) / CLOCKS_PER_SEC) - number_map;
	cout << " +-----------------------+"
		<< "\n     Congratulations !\n"
		<< "      You have passed \n"
		<< "         the game!\n\n"
		<< "     YOUR SCORE: " << score_player
		<< "\n     YOUR TIME: " << time_player
		<< "\n +-----------------------+" << std::endl;
}




void add_score_points(int w_h[3][2], char* map[], int num) {
	for (size_t i = 0; i < 20; i++)
	{
		int point_x = rand() % w_h[num][1];
		int point_y = rand() % w_h[num][0];
		if (map[num][point_x * w_h[num][0] + point_y] != B) {
			map[num][point_x * w_h[num][0] + point_y] = '$';
		}
	}
}


void drawMaze(char us_in, bool* collect, int w_h[3][2], char* map[]) {
	system("cls");
	char player = player_direction(us_in);

	for (int i = 0; i < w_h[number_map][1]; i++) {//     height
		for (int j = 0; j < w_h[number_map][0]; j++) {//    width
			if (i == playerY && j == playerX) {
				cout << player;
			}
			else if (i == exit_and_key[number_map][keyY] && j == exit_and_key[number_map][keyX]) {
				cout << "\033[38;2;255;200;100m" << '*' << "\033[0m";
			}
			else if (number_map == 2 && (i == portals[0] && j == portals[1] || i == portals[2] && j == portals[3])) {
				cout << "\033[37;45m" << 'O' << "\033[0m";
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
	else if (userInput == 'a' && map[number_map][(playerY)*w_h[number_map][0] + (playerX - 1)] != B) {
		playerX--;
	}
	else if (userInput == 'd' && map[number_map][(playerY)*w_h[number_map][0] + (playerX + 1)] != B) {
		playerX++;
	}
}




void collect_key_or_exit_or_teleport_or_point(bool* c_k, int w_h[3][2], char* map[]) {


	//ПЕРЕВІРКА НА ТЕ ЧИ ВИ НАСТУПИЛИ НА КЛЮЧ
	if (playerX == exit_and_key[number_map][keyX] && playerY == exit_and_key[number_map][keyY]) {
		map[number_map][(exit_and_key[number_map][keyY] * w_h[number_map][0]) + exit_and_key[number_map][keyX]] = ' ';
		*c_k = true;
		exit_and_key[number_map][keyX] = -1;
		exit_and_key[number_map][keyY] = -1;
	}

	//ПЕРЕВІРКА НА ТЕ ЧИ Є У ВАС КЛЮЧ І НА ТЕ ЧИ ВИ НАСТУПИЛИ НА ВИХІД
	if (playerX == exit_and_key[number_map][exitX] && playerY == exit_and_key[number_map][exitY] && *c_k == true) {
		map[number_map][(playerY * w_h[number_map][0]) + playerX] = ' ';
		*c_k = false;
		system("cls");
		playerX = 1;
		playerY = 1;
		cout << "\033[38;2;0;200;0m" << "\nYou complete LEVEL - " << number_map + 1 << "!\n\n" << "\033[0m";
		number_map++;
		Sleep(1000);
		system("cls");
	}
	//КОЛИ НАСТУПИЛИ НА ПОІНТ
	if (number_map != 3) {
		if (map[number_map][(playerY * w_h[number_map][0]) + playerX] == '$') {
			map[number_map][(playerY * w_h[number_map][0]) + playerX] = ' ';
			score_player++;
		}

	}



	//ТЕЛЕПОРТ
	if (number_map == 2 && (playerY == portals[0] && playerX == portals[1] || playerY == portals[2] && playerX == portals[3])) {
		enter_to_action();
		int temp = _getch();
		if (temp == 13) {
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
}






void game() {
	srand(time(0));
	int w_h[3][2] = { {10,10}, {20,19},{20,20} };
	char* map[3] = { *maze, *maze2,*maze3 };
	char userInput = '>';
	bool* collect = new bool[1];
	*collect = false;

	while (play_stat == true) {
		system("cls");
		main_menu();

		for (size_t i = 0; i < 3; i++)
		{
			add_score_points(w_h, map, i);
		}

		switch (selectedOption) {
		case 0:
			START_func(userInput, collect, w_h, map);
			break;
		case 1:
			LEVELS_func(userInput, collect, w_h, map);
			break;
		case 2:
			INFO_func();
			break;
		case 3:
			play_stat = false;
			break;
		}

		system("pause");

	}


	delete[] collect;
}
