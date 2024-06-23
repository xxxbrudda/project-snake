#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;



struct snakeBlock {
    int x, y;
};
void SetZero(short x, short y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { x, y };
    SetConsoleCursorPosition(hStdOut, coord);
}

void printBorder(vector<snakeBlock>& Snake)
{
    system("cls");
    for (int x = 0; x < 50; x++)
    {
        SetZero(x, 0);
        printf("#");
    }
    for (int x = 0; x < 49; x++)
    {
        SetZero(x, 24);
        printf("#");
    }

    for (int y = -1; y < 25; y++)
    {
        SetZero(0, y);
        printf("#");
    }
    for (int y = -1; y < 25; y++)
    {
        SetZero(49, y);
        printf("#");
    }
    for (int i = 0; i < Snake.size();i++)
    {
        SetZero(Snake[i].x, Snake[i].y);
        cout << "@";
    }
}

snakeBlock snakebuff()
{
    srand(time(0));
    snakeBlock apple;
    apple.x = rand() % 20 + 1;
    apple.y = rand() % 20 + 1;
    SetZero(apple.x, apple.y);
    cout << "*";
    return apple;

}
void SnakeInit(int x, int y, vector<snakeBlock>& Snake) {
    snakeBlock newSnake;
    newSnake.x = x;
    newSnake.y = y;
    Snake.push_back(newSnake);
}
void SnakePrint(vector<snakeBlock>& Snake) {

    for (int i = 0; i < Snake.size();i++)
    {
        SetZero(Snake[i].x, Snake[i].y);
        cout << "@";
    }

}
bool SnakeMove(vector<snakeBlock>& Snake, int moveMass[])
{

    for (int i = 0; i < Snake.size();i++) {
        SetZero(Snake[i].x, Snake[i].y);
        cout << " ";

    }
    Snake[0].x += moveMass[0];
    Snake[0].y += moveMass[1];
    //  printBorder(Snake);
    SnakePrint(Snake);
    if (((Snake[0].x >= 0) && (Snake[0].x <= 50)) && (Snake[0].y == 0))
    {
        system("cls");
        return false;
    }
    if (((Snake[0].x >= 0) && (Snake[0].x <= 50)) && (Snake[0].y == 24))
    {
        system("cls");
        return false;
    }
    if (((Snake[0].y >= -1) && (Snake[0].y <= 24)) && (Snake[0].x == 0))
    {
        system("cls");
        return false;
    }
    if (((Snake[0].y >= -1) && (Snake[0].y <= 24)) && (Snake[0].x == 49))
    {
        system("cls");
        return false;
    }

    return true;
}
bool check(vector<snakeBlock>& Snake, snakeBlock apple)
{
    //  for (int i = 0; i < Snake.size();i++)
     // {
    if ((Snake[0].x == apple.x) && (Snake[0].y == apple.y))
    {

        int oldx, oldy;
        oldx = apple.x;
        oldy = apple.y;
        SetZero(oldx, oldy);
        cout << " ";
        snakeBlock newSnake;
        Snake.push_back(newSnake);
        return true;
    }
    else return false;


    //  }
}
int main()
{
    vector<snakeBlock> Snake;
    bool run = true;
    SnakeInit(3, 3, Snake);
    printBorder(Snake);
    int moveMass[2] = { 0,1 };
    snakeBlock h = snakebuff();

    while (run)
    {

        run = SnakeMove(Snake, moveMass);
        if (check(Snake, h) == true)
        {
            h = snakebuff();
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            moveMass[0] = 1;
            moveMass[1] = 0;
        }
        if (GetAsyncKeyState(VK_DOWN)) {

            moveMass[0] = 0;
            moveMass[1] = 1;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            moveMass[0] = -1;
            moveMass[1] = 0;
        }
        if (GetAsyncKeyState(VK_UP)) {
            moveMass[0] = 0;
            moveMass[1] = -1;
        }


        Sleep(150);

    }

    if (run == false)
    {
        system("cls");
        cout << ".................................................................Game....Over.........................................................................";

    }
}