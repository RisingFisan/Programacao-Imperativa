#include <limits.h> 
// Permite-nos usar o INT_MIN, que é o menor valor inteiro que existe para o tipo int.

void maior() {
    int largest = INT_MIN;
    puts("Maior de uma sequência\nInsere uma lista de números (um por linha) terminada em 0:");
    while(1) {
        int num;
        assert(scanf("%d",&num) == 1);
        if(num == 0) break;
        if(num > largest) largest = num;
    }
    printf("Maior: %d\n", largest);
}