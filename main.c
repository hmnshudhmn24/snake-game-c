#include "game.h"

int main() {
    srand(time(0));
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }
    printf("Game Over! Final Score: %d\n", score);
    return 0;
}