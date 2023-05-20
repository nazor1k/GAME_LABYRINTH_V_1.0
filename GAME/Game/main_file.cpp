//
// Created by Nazar on 19.05.2023.
//


#include <iostream>
#include <conio.h>
#include <Windows.h>
const int width = 10;  // ширина лабіринту
const int height = 10;  // висота лабіринту

int playerX = 1;  // початкова позиція гравця по осі X
int playerY = 1;  // початкова позиція гравця по осі Y

int keyX = 8;  // позиція ключика по осі X
int keyY = 8;  // позиція ключика по осі Y

int exitX = 2;  // позиція виходу по осі X
int exitY = 8;  // позиція виходу по осі Y

void drawMaze(char maze[height][width]) {
    system("cls");  // очистити екран

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == playerY && j == playerX) {
                std::cout << ">";  // вивести гравця
            }
            else if (i == keyY && j == keyX) {
                std::cout << '*';  // вивести ключик
            }
            else {
                std::cout << maze[i][j];  // вивести стіну або вільне місце
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

        userInput = _getch();  // отримати введений символ без виводу на екран

        // Перевірити введений символ та перемістити гравця
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





        // Перевірити, чи гравець зібрав ключик
        if (playerX == keyX && playerY == keyY) {
            maze[keyY][keyX] = ' ';  // замінити ключик на вільне місце
            keyX = -1;  // прибрати ключик з мапи
            keyY = -1;
            // Тут ви можете додати додатковий код, що відбувається при збиранні ключика
        }
    }

    return 0;
}