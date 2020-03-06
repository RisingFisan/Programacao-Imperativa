#include <stdio.h>

void triangulo(int n) {
    for(int i = 1; i <= n; i++) {
        int j = i - 1;
        for(int k = 0; k < n - 1 - j; k++) putchar(' ');
        for(int k = 0; k < 1 + 2 * j; k++) putchar('#');
        putchar('\n');
    }
}