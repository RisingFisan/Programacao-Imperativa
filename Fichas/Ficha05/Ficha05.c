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

void maxSort2(int v[], int N) {
    for(int j = N; j > 0; j--) {
        int maxI = 0;
        for(int i = 1; i < j; i++)
            if(v[i] > v[maxI]) maxI = i;
        int temp = v[j - 1];
        v[j - 1] = v[maxI];
        v[maxI] = temp;
    }
}

// Exercicio 6

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bubble(int v[], int N) {
    int i;
    for (i = 1; i < N; i++)
        if (v[i - 1] > v[i])
            swap(v, i - 1, i);
} 
/*
lista = 5,3,6,4,1
i = 1
5 > 3 True
lista = 3,5,6,4,1
i = 2
5 > 6 False
i = 3
6 > 4 True
lista = 3,5,4,6,1
i = 4
6 > 1 True
lista = 3,5,4,1,6
END
*/

// Exercicio 7

void bubbleSort(int v[], int N) {
    for(int i = 0; i < N; i++)
        bubble(v,N);
}

// Exercicio 8

int sorted(int v[], int N) {
    for(int i = 1; i < N; i++) {
        if(v[i - 1] > v[i]) return 0;
    }
    return 1;
}

void bubbleSortV2(int v[], int N) {
    for(int i = 0; i < N; i++) {
        if(sorted(v,N)) break;
        else bubble(v,N);
    }
}

// Exercicio 9

void merge(int r[], int a[], int na, int b[], int nb) {
    int i, j;
    i = j = 0;
    for(int x = 0; x < na + nb; x++) {
        if(a[i] < b[j] && i < na || j == nb) r[x] = a[i++];
        else r[x] = b[j++];
    }
}

void mergesort(int v[], int n, int aux[]) {
    int i, m;
    if (n > 1) {
        m = n / 2;
        mergesort(v, m, aux);
        mergesort(v + m, n - m, aux);
        merge(aux, v, m, v + m, n - m);
        for (i = 0; i < n; i++)
            v[i] = aux[i];
    }
}

// Exercicio 10

int partition(int v[], int a, int b) {
    int pivot = v[b - 1];
    int j = a;
    for(int i = a; i < b - 1; i++) {
        if(v[i] < pivot) {
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
            j++;
        }
    }
    v[b - 1] = v[j];
    v[j] = pivot;
    return j;
}

void qsortAux(int v[], int a, int b) {
    int p;
    if (a < b) {
        p = partition(v, a, b);
        qsortAux(v, a, p);
        qsortAux(v, p + 1, b);
    }
}

void quicksort(int v[], int n) { qsortAux(v, 0, n); }

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
    char optX[3];
    printf("Introduz o numero da pergunta: ");
    fgets(optX,3,stdin);
    if(optX[0] == '1' && optX[1] == '0') opt = 'A';
    else opt = optX[0];
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
            int nums[len];
            getIntArray(nums,len);
            insertionSort(nums,len);
            printIntArray(nums,len);
            break; }
        case '3': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len];
            getIntArray(nums,len);
            int resp = maxInd(nums,len);
            printf("Resposta: %d", resp);
            break; }
        case '4': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len];
            getIntArray(nums,len);
            maxSort(nums,len);
            printIntArray(nums,len);
            break; }
        case '5': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len];
            getIntArray(nums,len);
            maxSort2(nums,len);
            printIntArray(nums,len);
            break; }
        case '7': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len];
            getIntArray(nums,len);
            bubbleSort(nums,len);
            printIntArray(nums,len);
            break; }
        case '8': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len];
            getIntArray(nums,len);
            bubbleSortV2(nums,len);
            printIntArray(nums,len);
            break; }
        case '9': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len];
            int numsorted[len];
            getIntArray(nums,len);
            mergesort(nums,len,numsorted);
            printIntArray(numsorted,len);
            break; }
        case 'A': {
            printf("Tamanho da lista: ");
            scanf("%d",&len);
            int nums[len];
            getIntArray(nums,len);
            quicksort(nums,len);
            printIntArray(nums,len);
            break; }
    }
    return 0;
}