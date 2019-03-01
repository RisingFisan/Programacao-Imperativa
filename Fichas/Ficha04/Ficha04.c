#include <stdio.h>
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
    
}

int getLine(char str[], int lim) {
    char c;
    int i;
    for(i = 0; (c = getchar()) != '\n' && i < lim; i++) str[i] = c;
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
    int resp;
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

    }
    return 0;
}
