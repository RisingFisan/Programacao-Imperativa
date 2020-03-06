#include <stdio.h>

/* 
Exercício 1 

1)12 16
2)0 1 (uninitialized variable y)
3)A 65
  B 66 2 50
  b 98
4)100 200
5)128 -99
  129 -99

--------------------------------------------------------

Exercicio 2

1) a)3 5
   b)66
   c)... overflow
   d)_#_#_#_#_#_#_#_#_#_#
   e)abcdefg
     bcdefg
     cdefg
     defg
     efg
     fg
     g

   f)
     1
     10
     11
     100
     101
     110
     111
     1000
     1001
     1010
     1011
     1100
     1101
     1110
     1111


*/

// 2)

void quadrado(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}

// 3)

void xadrez(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i + j) % 2) putchar('_');
            else putchar('#');
        }
        putchar('\n');
    }
}

// 4)

void triang1(int n) {
    for(int i = 1; i < 2 * n; i++) {
        for(int j = 1; j <= 2 * n - i; j++) {
            if(j <= i) putchar('#');
        }
        putchar('\n');
    }
}

void triang2(int n) {
    for(int i = 1; i <= n; i++) {
        int j = i - 1;
        for(int k = 0; k < n - 1 - j; k++) putchar(' ');
        for(int k = 0; k < 1 + 2 * j; k++) putchar('#');
        putchar('\n');
    }
}

int main(int argc, char const *argv[])
{
    triang1(5);
    triang2(5);
    return 0;
}
