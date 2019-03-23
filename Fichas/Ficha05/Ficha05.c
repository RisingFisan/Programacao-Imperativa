#include <stdio.h>

// Exercicio 1

void insere (int v[], int N, int x) {
    for(int i = 0; i < N; i++) {
        if(v[i] > x) {
            for(int j = N; j > i; j--) v[j] = v[j - 1];
            v[i] = x;
            break;
        }
    }
    if(v[N - 1] < x) v[N] = x;
}

// Exercicio 2

void insertionSort(int v[], int N) {
    for(int i = 1; i < N; i++) {
        int x = v[i];
        int j;
        for(j = i; j > 0 && x < v[j - 1]; j--) v[j] = v[j - 1];
        v[j] = x;
    }
}

// Exercicio 3

int maxInd (int v[], int N) {
    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(v[i] > v[ans]) ans = i;
    }
    return ans;
}

// Exercicio 4

void maxSort(int v[], int N) {
    for(int x = N; x > 0; x--) {
        int maxindx = maxInd(v,x);
        int temp = v[x - 1];
        v[x - 1] = v[maxindx];
        v[maxindx] = temp;
    }
}

// Exercicio 5



void getIntArray(int arr[], int lim) {
    for(int i = 0; i < lim; i++) {
        printf("Insere um valor: ");
        scanf("%d", arr + i);
    }
}

void printIntArray(int arr[], int lim) {
    printf("[");
    for(int i = 0; i < lim; i++) {
        if(i == lim - 1) printf("%d",arr[i]);
        else printf("%d, ",arr[i]);
    }
    printf("]\n");
}

int main() {
    int len, num;
    char opt, c;
    printf("Introduz o numero da pergunta: ");
    opt = getchar();
    while((c = getchar()) != '\n');
    switch(opt) {
        case '1': {
            printf("Tamanho da lista ordenada: ");
            scanf("%d",&len);
            int nums[len + 1];
            getIntArray(nums,len);
            printf("Elemento a inserir: ");
            scanf("%d",&num);
            insere(nums,len++,num);
            printIntArray(nums,len);
            break; }
        case '2': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len + 1];
            getIntArray(nums,len);
            insertionSort(nums,len);
            printIntArray(nums,len);
            break; }
        case '3': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len + 1];
            getIntArray(nums,len);
            int resp = maxInd(nums,len);
            printf("Resposta: %d", resp);
            break; }
        case '4': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len + 1];
            getIntArray(nums,len);
            maxSort(nums,len);
            printIntArray(nums,len);
            break; }
    }
    return 0;
}