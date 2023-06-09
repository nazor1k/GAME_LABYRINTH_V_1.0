

//#ifndef GAME_LABYRINTH_V_1_0_MAIN_HEAD_H
//#define GAME_LABYRINTH_V_1_0_MAIN_HEAD_H
//
//#endif //GAME_LABYRINTH_V_1_0_MAIN_HEAD_H
#pragma once
const int count_map = 4;
bool into_radius(int a, int b);
void enter_to_action();
char player_direction(char us_in);
void START_func(char us_in, int w_h[count_map][2], char* map[]);
void LEVELS_func(char us_in, int w_h[count_map][2], char* map[]);
void INFO_func();
void SETTINGS_func();
void main_menu();
void print_end_stats(int start, int end, int c_m );
void add_score_points(int w_h[count_map][2], char* map[],int num);
void drawMaze(char us_in, int w_h[count_map][2], char* map[]);
void movePlayer(char userInput, int w_h[count_map][2], char* map[]);
void collect_key_or_exit_or_teleport_or_point(int w_h[count_map][2],char* map[]);
void game();
