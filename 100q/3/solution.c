#include <limits.h>

void segundoMaior() {
    int biggest = INT_MIN, second_biggest = INT_MIN, num;
    while(1) {
        assert(scanf("%d",&num) == 1);
        if(num == 0) break;
        if(num > biggest) {
            second_biggest = biggest;
            biggest = num;
        } else if (num > second_biggest) second_biggest = num;
    }
    printf("Segundo maior número: %d\n", second_biggest);
}