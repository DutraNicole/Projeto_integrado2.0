#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 20
#define HEIGHT 20

int gameOver;
int score;
int x, y, fruitX, fruitY;
int direction;

// Função para definir a entrada do teclado como não-bloqueante
void SetNonBlockingInput() {
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    ttystate.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

// Função para detectar as teclas pressionadas
int kbhit() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); // Assumindo que a entrada padrão é o teclado
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

void Setup() {
    gameOver = 0;
    score = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    direction = rand() % 4 + 1; // Inicia com uma direção aleatória
}

void Draw() {
    system("clear");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0 || j == WIDTH - 1)
                printf("#");
            else if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
    printf("Pontuação: %d\n", score);
}

void Input() {  //Direção da cobrinha
    if (kbhit()) {
        char input = getchar();
        switch (input) {
            case 'w':
                direction = 1;
                break;
            case 's':
                direction = 2;
                break;
            case 'a':
                direction = 3;
                break;
            case 'd':
                direction = 4;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void Logic() {
    switch (direction) {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;
    }

    if (x >= WIDTH)
        x = 0;
    else if (x < 0)
        x = WIDTH - 1;
    if (y >= HEIGHT)
        y = 0;
    else if (y < 0)
        y = HEIGHT - 1;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
}

int main() {
    SetNonBlockingInput();
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(100000); // Ajuste para controlar a velocidade do jogo
    }
    return 0;
}
