#include "game.h"

int gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tailLength;
char direction;
int speed = 100;
int level = 1;
int highScore = 0;

void setup() {
    gameOver = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    tailLength = 0;
    speed = 100;
    level = 1;
}

void draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");
            
            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                int print = 0;
                for (int k = 0; k < tailLength; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print) printf(" ");
            }
            
            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }
    
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\nScore: %d  Level: %d  High Score: %d\n", score, level, highScore);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': direction = 'L'; break;
            case 'd': direction = 'R'; break;
            case 'w': direction = 'U'; break;
            case 's': direction = 'D'; break;
            case 'x': gameOver = 1; break;
        }
    }
}

void logic() {
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    
    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
    switch (direction) {
        case 'L': x--; break;
        case 'R': x++; break;
        case 'U': y--; break;
        case 'D': y++; break;
    }
    
    if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0) gameOver = 1;
    
    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == x && tailY[i] == y) gameOver = 1;
    }
    
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        tailLength++;
        
        if (score % 50 == 0) {
            level++;
            speed -= 10;
            if (speed < 50) speed = 50;
        }
    }
    
    if (score > highScore) highScore = score;
    
    Sleep(speed);
}