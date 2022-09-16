#include <stdio.h>

/*
 * X - cord x
 * Y - cord y
 * Pxy - cord Player
 * cnt - move counter
 */
unsigned int X, Y, Px, Py, cnt;
_Bool playing = 1, interrupt;

void draw() {
    for(unsigned int i = 0; i < Y; i++) {
        for(unsigned int j = 0; j < X; j++)
            if(i == Py && j == Px)
                printf("@");
            else if(i == Y - 1 && j == X - 1)
                printf("o");
            else
                printf("-");
        printf("\n");
    }
}

_Bool validate(unsigned int newPx, unsigned int newPy) {
    cnt++;
    return newPx < X && newPy < Y && newPy >= 0 && newPx >= 0;
}

void left() {
    if(validate(Px - 1, Py))
        Px--;
}

void right() {
    if(validate(Px + 1, Py))
        Px++;
}

void up() {
    if(validate(Px, Py - 1))
        Py--;
}

void down() {
    if(validate(Px, Py + 1))
        Py++;
}

void run() {
    while(playing) {
        draw();
        int key;
        scanf("%d", &key);
        switch(key) {
            case 8: {
                up();
                break;
            }
            case 6: {
                right();
                break;
            }
            case 4: {
                left();
                break;
            }
            case 5: {
                down();
                break;
            }
            case 0: {
                playing = 0;
                interrupt = 1;
                break;
            }
            default:
                printf("Exit -> 0");
        }
        if(Px == X - 1 && Py == Y - 1)
            playing = 0;
    }
    printf("The game %s\nScore: %d", interrupt ? "was interrupted" : "has been completed", cnt);
}

int main() {
    unsigned int N;
    scanf("%d", &N);
    if(N < 2) {
        return 500;
    }
    X = Y = N;
    run();
    return 0;
}
