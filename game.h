#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

extern int gameOver, x, y, fruitX, fruitY, score, tailX[100], tailY[100], tailLength, speed, level, highScore;
extern char direction;

void setup();
void draw();
void input();
void logic();

#endif