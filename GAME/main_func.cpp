#include <iostream>
#include <conio.h>
#include <windows.h>
#include "main_head.h"
#include<ctime>
#include<time.h>
using namespace std;

//player_position
int playerX = 1;
int playerY = 1;

bool play_stat = true;
int radius=3;

//EXIT AND KEY AND TELEPORT position
const int exitX = 0;
const int exitY = 1;
const int keyX = 2;
const int keyY = 3;
int exit_and_key[3][4] = { {4,3,8,8}, {18,17,1,16}, {18,18,18,7} };
const int portals[4] = { 16,2,9,18 };//{ y1,x1,y2,x2}


//player_stats
double time_player=0;
int score_player = 0;

//MAPS SYMBOL
const char B = char(219);
const char E = ' ';

int select_map = 2;
int selectedOption = 0;
int  number_map = 0;
bool collect_key = false;
//const int count_map = 3;

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


bool into_radius(int a, int b) {
	if (radius == 21) {
		return true;
	}
	int dy = abs(playerY - a);
	int dx = abs(playerX - b);
	return dy <= radius / 2 && dx <= radius / 2;
}




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


void START_func(char us_in, bool* collect, int w_h[count_map][2], char* map[]) {
	int start = clock();
	
	while (number_map != count_map) {

		drawMaze(us_in, collect, w_h, map);

		us_in = _getch();
		
		if (us_in == 8) {
			selectedOption = count_map;
			number_map = 0;
			*collect = false;
			playerX = 1;
			playerY = 1;
			score_player = 0;
			time_player = 0;
			return;
		}
		movePlayer(us_in, w_h, map);
		collect_key_or_exit_or_teleport_or_point(collect, w_h, map);

	}
	int end = clock();
	print_end_stats(start, end, count_map);
	system("pause");
}

void LEVELS_func(char us_in, bool* collect, int w_h[count_map][2], char* map[]) {
	int start = clock();
	int key = NULL;

	while (key != 13) {
		// Очищення екрану
		system("cls");

		// Вивід меню
		cout << "+======== MENU =======+" << endl;
		cout << "|                     |" << endl;
		cout << "| " << ((select_map == 0) ? "\033[7m> " : "  ") << "LEVEL 1" << "\033[0m" << "           |" << endl;
		cout << "| " << ((select_map == 1) ? "\033[7m> " : "  ") << "LEVEL 2" << "\033[0m" << "           |" << endl;
		cout << "| " << ((select_map == 2) ? "\033[7m> " : "  ") << "LEVEL 3" << "\033[0m" << "           |" << endl;
		cout << "|                     |" << endl;
		cout << "+=====================+" << endl;
		cout << "|                     |" << endl;
		cout << "| BACKSPACE TO MAIN   |" << endl;
		cout << "|      MENU ...       |" << endl;
		cout << "|                     |" << endl;
		cout << "+=====================+" << endl;

		// Зчитування введеного символу
		key = _getch();
		if (key == 8) {
			selectedOption = count_map;
			return;
		}
		// Перевірка натиснутої клавіші
		switch (key) {
		case 'w':
			select_map = (select_map - 1 + count_map) % count_map;  // Перехід до попереднього пункту
			break;
		case 's':
			select_map = (select_map + 1) % count_map;  // Перехід до наступного пункту
			break;

		}
	}
	

	
		
	number_map = select_map;
	add_score_points(w_h, map, select_map);
	while (number_map == select_map) {

		drawMaze(us_in, collect, w_h, map);
		if (us_in == 8) {
			selectedOption = count_map;
			number_map = 0;
			*collect = false;
			playerX = 1;
			playerY = 1;
			score_player = 0;
			time_player = 0;
			return;
		}
		us_in = _getch();
		movePlayer(us_in, w_h, map);
		collect_key_or_exit_or_teleport_or_point(collect, w_h, map);

	}
	int end = clock();
	number_map = 0;
	print_end_stats(start, end,1);
	system("pause");
}

void INFO_func() {
	system("cls");
	cout << "+======================== INFO ========================+" << endl;
	cout << "|                                                      |" << endl;
	cout << "|         Greetings, you are in the game Labyrinth     |" << endl;
	cout << "|           Small hints for passing the maze           |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|    1) '" << "\033[38;2;255;200;100m" << "*" << "\033[0m'-is a key, yellow in color, which is        |" << endl;
	cout << "|    necessary to go to the next level                 |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|    2) '" << "\033[31;2m" << "X" << "\033[0m' will appear after picking up the key,      |" << endl;
	cout << "|    and will be red color                             |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|    3) '$' is the coins you can raise for the best    |" << endl;
	cout << "|    score,at the end of the game you will see your    |" << endl;
	cout << "|    score                                             |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|    4) The '"<<"\033[37;45m" << "O" << "\033[0m' is a portal that will help             |" << endl;
	cout << "|    send you to closed areas of the maze              |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|    Game made by Hus Artem and Korobchyk Nazar        |" << endl;
	cout << "|                                                      |" << endl;
	cout << "|    Git Hub repository:                               |" << endl;
	cout << "|    "<<"\033[4;34m"<<"https://github.com/nazor1k/GAME_LABYRINTH_V_1.0"<<"\033[0m" << "   |" << endl;
	cout << "|                                                      |" << endl;
	/*cout << "|    For exit, press any button                        |" << endl;*/
	cout << "|                                                      |" << endl;
	cout << "+======================================================+\n" << endl;
	system("pause");
}

void SETTINGS_func()
{
	int minRadius = 3;
	int maxRadius = 21;
	/*radius = minRadius;*/  // Початкове значення радіусу

	while (true)
	{
		system("cls");  // Очищення екрану

		// Вивід меню
		cout << "+=======================+" << endl;
		cout << "|     SETTINGS MENU     |" << endl;
		cout << "+=======================+" << endl;
		cout << "| Radius: " << ((radius > 9) ? "" : "0"); 
		if (radius <= 20) cout<<(radius)<<"     "; else cout << "ALL_MAP";
		cout<<"       |" << endl;
		cout << "|                       |" << endl;
		cout << "| [A] Decrease radius   |" << endl;
		cout << "| [D] Increase radius   |" << endl;
		cout << "|                       |" << endl;
		cout << "| [ENTER] Save and exit |" << endl;
		cout << "+=======================+" << endl;



		
		char key = _getch();  // Зчитування введеного символу

		if (key == 'a')
		{
			// Зменшення радіусу
			if (radius > minRadius)
				radius--;
		}
		else if (key == 'd')
		{
			// Збільшення радіусу
			if (radius < maxRadius)
				radius++;
		}
		else if (key == 13 || key == 8)
		{
			// Збереження радіусу і вихід з функції
			cout << "Radius set to: " << radius <<"!" << endl;
			Sleep(1000);
			break;
		}
		
	}
}



void main_menu() {
	selectedOption = 0;
	int key=NULL;

	while (key!=13) {
		// Очищення екрану
		system("cls");

		// Вивід меню
		cout << "+=======================+" << endl;
		cout << "|        MENU           |" << endl;
		cout << "+=======================+" << endl;
		cout << "|                       |" << endl;
		cout << "| " << ((selectedOption == 0) ? "\033[7m\t> START   \033[0m" : "\t> START   ") << "      |" << endl;
		cout << "| " << ((selectedOption == 1) ? "\033[7m\t> LEVELS  \033[0m" : "\t> LEVELS  ") << "      |" << endl;
		cout << "| " << ((selectedOption == 2) ? "\033[7m\t> INFO    \033[0m" : "\t> INFO    ") << "      |" << endl;
		cout << "| " << ((selectedOption == 3) ? "\033[7m\t> SETTINGS\033[0m" : "\t> SETTINGS") << "      |" << endl;
		cout << "| " << ((selectedOption == 4) ? "\033[7m\t> EXIT    \033[0m" : "\t> EXIT    ") << "      |" << endl;
		cout << "|                       |" << endl;
		cout << "+=======================+" << endl;


		
		// Зчитування введеного символу
		key = _getch();
		
		// Перевірка натиснутої клавіші
		switch (key) {
		case 'w':
		case 'W':
			selectedOption = (selectedOption - 1 + 5) % 5;  // Перехід до попереднього пункту
			break;
		case 's':
		case 'S':
			selectedOption = (selectedOption + 1) % 5;  // Перехід до наступного пункту
			break;
		}
		
	}
}



void print_end_stats(int start,int end,int c_m) {
	time_player = ((double(end) - double(start)) / CLOCKS_PER_SEC) - c_m;
	cout << "+-----------------------+" << endl;
	cout << "|                       |" << endl;
	cout << "|   Congratulations !   |" << endl;
	cout << "|    You have passed    |" << endl;
	cout << "|       the game!       |" << endl;
	cout << "|                       |" << endl;
	cout << "|   YOUR SCORE: "  << score_player << " points" << endl;
	cout << "|   YOUR TIME: "  << time_player << " seconds" << endl;
	cout << "|                       |" << endl;
	cout << "+-----------------------+" << endl;
	score_player = 0;
	time_player = 0;
	number_map = 0;
}




void add_score_points(int w_h[count_map][2], char* map[],int num) {
	map[number_map][(exit_and_key[number_map][keyY] * w_h[number_map][0]) + exit_and_key[number_map][keyX]] = '*';
	
	//очищуємо карту від старих поінтів
	for (int i = 0; i < w_h[num][1]; i++) {//     height
		for (int j = 0; j < w_h[num][0]; j++) {//    width
			if (map[num][i * w_h[num][0] + j] == '$') {
				map[num][i * w_h[num][0] + j] = ' ';
			}
		}
		
	}
	
	//генеруємо нові поінти
	for (size_t i = 0; i < 10; i++)
	{
		int point_x = rand() % w_h[num][1];
		int point_y = rand() % w_h[num][0];
		if (map[num][point_x * w_h[num][0] + point_y] != B) {
			map[num][point_x * w_h[num][0] + point_y] = '$';
		}
	}
}


void drawMaze(char us_in, bool* collect,int w_h[count_map][2] , char* map[]) {
	system("cls");
	char player= player_direction(us_in);

	for (int i = 0; i < w_h[number_map][1]; i++) {//     height
		for (int j = 0; j < w_h[number_map][0]; j++) {//    width
			if (into_radius(i,j)) {
				if (i == playerY && j == playerX) {
					cout << player;
				}
				else if (i == exit_and_key[number_map][keyY] && j == exit_and_key[number_map][keyX] && *collect == false) {
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
			else {
				cout << " ";
			}
			
		}
		cout << endl;
	}

	cout << "\n+=====================+" << endl;
	cout << "|                     |" << endl;
	cout << "| BACKSPACE TO MAIN   |" << endl;
	cout << "|      MENU ...       |" << endl;
	cout << "|                     |" << endl;
	cout << "+=====================+" << endl;
}







void movePlayer(char userInput, int w_h[count_map][2], char* map[]) {
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




void collect_key_or_exit_or_teleport_or_point(bool* c_k,int w_h[count_map][2], char* map[]) {


	//ПЕРЕВІРКА НА ТЕ ЧИ ВИ НАСТУПИЛИ НА КЛЮЧ
	if (playerX == exit_and_key[number_map][keyX] && playerY == exit_and_key[number_map][keyY]) {
		map[number_map][(exit_and_key[number_map][keyY] * w_h[number_map][0]) + exit_and_key[number_map][keyX]] = ' ';
		*c_k = true;
		/*exit_and_key[number_map][keyX] = -1;
		exit_and_key[number_map][keyY] = -1;*/
	}

	//ПЕРЕВІРКА НА ТЕ ЧИ Є У ВАС КЛЮЧ І НА ТЕ ЧИ ВИ НАСТУПИЛИ НА ВИХІД
	if (playerX == exit_and_key[number_map][exitX] && playerY == exit_and_key[number_map][exitY] && *c_k == true) {
		map[number_map][(playerY * w_h[number_map][0]) + playerX] = ' ';
		*c_k = false;
		system("cls");
		playerX = 1;
		playerY = 1;
		cout << "\033[38;2;0;200;0m" << "\nYou complete LEVEL - "<<number_map+1<<"!\n\n"<< "\033[0m";
		number_map++;
		Sleep(1000);
		system("cls");
	}
	//КОЛИ НАСТУПИЛИ НА ПОІНТ
	if(number_map != 3){
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
	int w_h[count_map][2] = { {10,10}, {20,19},{20,20} };
	char* map[count_map] = { *maze, *maze2,*maze3 };
	char userInput = '>';
	bool* collect = new bool[1];
	*collect = false;

	while (play_stat == true) {
		system("cls");
		main_menu();

		

		switch (selectedOption) {
		case 0:
			for (size_t i = 0; i < count_map; i++)
			{
				add_score_points(w_h, map, i);
			}
			START_func(userInput, collect, w_h, map);
			
			break;
			
		case 1:
			LEVELS_func(userInput, collect, w_h, map);		
			break;
		case 2:
			INFO_func();
			break;
		case 3:
			SETTINGS_func();
			break;
		case 4:
			play_stat = false;
			break;
		}
		
		
		
	}
	

	delete[] collect;
}
