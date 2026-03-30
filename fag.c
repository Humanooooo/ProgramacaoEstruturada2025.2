#include <stdio.h>

#define LIN 2
#define COL 3

int main() {
    int matriz[LIN][COL];
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}