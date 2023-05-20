//
// Created by Nazar on 19.05.2023.
//


#include <iostream>
#include <conio.h>
#include <Windows.h>
const int width = 10;  // ������ ��������
const int height = 10;  // ������ ��������

int playerX = 1;  // ��������� ������� ������ �� �� X
int playerY = 1;  // ��������� ������� ������ �� �� Y

int keyX = 8;  // ������� ������� �� �� X
int keyY = 8;  // ������� ������� �� �� Y

int exitX = 2;  // ������� ������ �� �� X
int exitY = 8;  // ������� ������ �� �� Y

void drawMaze(char maze[height][width]) {
    system("cls");  // �������� �����

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == playerY && j == playerX) {
                std::cout << ">";  // ������� ������
            }
            else if (i == keyY && j == keyX) {
                std::cout << '*';  // ������� ������
            }
            else {
                std::cout << maze[i][j];  // ������� ���� ��� ����� ����
            }
        }
        std::cout << std::endl;
    }
}

int main() {

    char userInput;
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

    while (true) {
        drawMaze(maze);

        userInput = _getch();  // �������� �������� ������ ��� ������ �� �����

        // ��������� �������� ������ �� ���������� ������
        if (userInput == 'w' && maze[playerY - 1][playerX] != B) {
            playerY--;
        }
        else if (userInput == 's' && maze[playerY + 1][playerX] != B) {
            playerY++;
        }
        else if (userInput == 'a' && maze[playerY][playerX - 1] != B) {
            playerX--;
        }
        else if (userInput == 'd' && maze[playerY][playerX + 1] != B) {
            playerX++;
        }





        // ���������, �� ������� ����� ������
        if (playerX == keyX && playerY == keyY) {
            maze[keyY][keyX] = ' ';  // ������� ������ �� ����� ����
            keyX = -1;  // �������� ������ � ����
            keyY = -1;
            // ��� �� ������ ������ ���������� ���, �� ���������� ��� ������� �������
        }
    }

    return 0;
}