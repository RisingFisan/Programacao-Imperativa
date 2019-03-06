#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 500

// Exercicio 1

int minusculas(char s[]) {
    int subs = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
            subs++; 
        }
    }
    return subs;
}

// Exercicio 2

int contalinhas (char s[]) {
    int lines = 0;
    for(int i = 0; s[i]; i++) if(s[i] == '\n') lines++;
    return lines + 1;
}

// Exercicio 3

int contaPal (char s[]) {
    int inWord = 0, total = 0;
    for(int i = 0; s[i]; i++) {
        if(isspace(s[i]) && inWord) {
            if(inWord) {
                total++;
                inWord = 0;
            }
        }
        else inWord = 1;
    }
    if(inWord) total++;
    return total;
}

// Exercicio 4

int procura (char *p, char *ps[], int N) {
    for(int i = 0; i < N; i++) {
        if(strcmp(p,ps[i]) == 0) return i + 1;
    }
    return 0;
}

// Exercicio 5

int procuraOrd (char *p, char *ps[], int N) {
    for(int i = 0; i < N; i++) {
        int x = strcmp(p,ps[i]);
        if(x < 0) return 0;
        else if(x == 0) return i + 1;
    }
    return 0;
}

// Exercicio 6

int procuraBinRec(char *p, char *ps[], int N, int offset) {
    if(N < 1) return 0;
    int xN = N / 2;
    int x = strcmp(p,ps[xN]);
    if(x == 0) return offset + xN + 1;
    char **ps1 = malloc(sizeof *ps1 * xN);
    for(int i = 0; i < xN; i++) {
        ps1[i] = malloc(MAX_LINE + 1);
        strcpy(ps1[i],ps[i]);
    }
    char **ps2 = malloc(sizeof *ps2 * (N - xN));
    for(int i = 0; i < N - xN - 1; i++) {
        ps2[i] = malloc(MAX_LINE + 1);
        strcpy(ps2[i],ps[i + xN + 1]);
    }
    if(x < 0) return procuraBinRec(p,ps1,xN,offset);
    else return procuraBinRec(p,ps2,N - xN - 1,offset + xN + 1);
}

int getLine(char str[], int lim) {
    char c;
    int i;
    for(i = 0; (c = getchar()) != '\n' && i < lim; i++) str[i] = c;
    str[i] = '\0';
    return i;
}

int getLines(char str[], int lim) {
    char c;
    int i;
    for(i = 0; (c = getchar()) != EOF && i < lim; i++) str[i] = c;
    return i; 
}

int main(int argc, char const *argv[]) {
    char buffer[MAX_LINE];
    char temp[MAX_LINE];
    int resp, num;
    printf("Introduz o número da pergunta: ");
    char opt = getchar();
    while((getchar()) != '\n');    
    switch (opt) {
        case '1':
            getLine(buffer,MAX_LINE);
            resp = minusculas(buffer);
            printf("%s\nLetras substituídas: %d\n",buffer,resp);
            break;
        case '2':
            getLines(buffer,MAX_LINE);
            resp = contalinhas(buffer);
            printf("\nNumero de linhas: %d\n", resp);
            break;
        case '3':
            getLine(buffer,MAX_LINE);
            resp = contaPal(buffer);
            printf("\nNumero de palavras: %d\n", resp);
            break;
        case '4':
        case '5':
        case '6': {
            getLine(buffer,MAX_LINE);
            printf("Número de strings: ");
            scanf("%d",&num);
            while((getchar()) != '\n');    
            char **frases = malloc(sizeof *frases * num);
            for(int i = 0; i < num; i++) {
                printf("Frase %d: ",i);
                frases[i] = malloc(sizeof *frases[i] * (MAX_LINE + 1));
                getLine(temp,MAX_LINE);
                strcpy(frases[i],temp);
            }
            printf("Que tipo de procura?\n1. Normal\n2. Ordenada\n3. Recursiva\n4. Iterativa\nR: ");
            opt = getchar();
            while((getchar()) != '\n');    
            if(opt == '1') resp = procura(buffer,frases,num);
            else if(opt == '2') resp = procuraOrd(buffer,frases,num);
            else if(opt == '3') resp = procuraBinRec(buffer,frases,num,0);
            if(resp) printf("A string '%s' e o %do elemento da lista.",buffer,resp);
            else printf("String não encontrada na lista."); 
            break; }
    }
    return 0;
}
