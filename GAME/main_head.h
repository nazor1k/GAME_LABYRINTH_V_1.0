

//#ifndef GAME_LABYRINTH_V_1_0_MAIN_HEAD_H
//#define GAME_LABYRINTH_V_1_0_MAIN_HEAD_H
//
//#endif //GAME_LABYRINTH_V_1_0_MAIN_HEAD_H
#pragma once
void add_score_points(int w_h[3][2], char* map[],int num);
void drawMaze(char us_in, bool* collect, int w_h[3][2], char* map[]);
void movePlayer(char userInput, int w_h[3][2], char* map[]);
void collect_key_or_exit(bool* c_k,int w_h[3][2],char* map[]);
void game();
