#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define SIZE 5

int snakeX = 2, snakeY = 2;
int foodX, foodY;
int score = 0;
int gameover = 0;
void placeFood() {
    foodX = rand() % SIZE;
    foodY = rand() % SIZE;
    while (foodX == snakeX && foodY == snakeY) {
        foodX = rand() % SIZE;
        foodY = rand() % SIZE;
    }
}
void draw() {
    system("cls");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == snakeY && j == snakeX)
                printf("O ");
            else if (i == foodY && j == foodX)
                printf("F ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\nScore: %d\n", score);
    printf("Use W/A/S/D to move. Press X to quit.\n");
}
void input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'a') snakeX--;
        else if (ch == 'd') snakeX++;
        else if (ch == 'w') snakeY--;
        else if (ch == 's') snakeY++;
        else if (ch == 'x') gameover = 1;
    }
}
void logic() {
    if (snakeX < 0 || snakeX >= SIZE || snakeY < 0 || snakeY >= SIZE)
        gameover = 1;

    if (snakeX == foodX && snakeY == foodY) {
        score += 10;
        placeFood();
    }
}
int main() {
    srand(time(0));
    placeFood();

    while (!gameover) {
        draw();
        input();
        logic();
        _sleep(300);
    }

    printf("\nGame Over! Final Score: %d\n", score);
    return 0;
}
