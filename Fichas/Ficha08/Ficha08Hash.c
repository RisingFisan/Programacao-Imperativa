#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HSIZE 1000

typedef struct entrada {
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras;

typedef Palavras Dicionario[HSIZE];

int hash(char *pal, int s) {
    int r;
    for (r = 0; *pal != '\0'; pal++)
        r += *pal;
    return (r % s);
}

void initDic (Dicionario* d) {
    for(int i = 0; i < HSIZE; i++) {
        Palavras dict = *d[i];
        while(dict) {
            Palavras temp = dict;
            dict = temp->prox;
            free(temp);
        }
    }
}

int acrescenta (Dicionario* d, char* pal) {
    int h = hash(pal,HSIZE);
    Palavras dict = (*d)[h];
    Palavras new = malloc(sizeof(struct entrada));
    new->palavra = malloc(strlen(pal));
    strcpy(new->palavra,pal);
    new->ocorr = 1;
    new->prox = NULL;
    if(!dict) {
        (*d)[h] = new;
        return 1;
    }
    while(dict->prox) {
        if(strcmp(dict->palavra,pal) == 0) {
            return ++(dict->ocorr);
        }
        dict = dict->prox;
    }
    if(strcmp(dict->palavra,pal) == 0) {
        return ++(dict->ocorr);
    } else {
        dict->prox = new;
        return 1;
    }
}

char *maisFreq (Dicionario d, int* c) {
    int max = 0;
    char* ans;
    for(int i = 0; i < HSIZE; i++) {
        Palavras dict = d[i];
        while(dict) {
            if(dict->ocorr > max) {
                ans = dict->palavra;
                *c = max = dict->ocorr;
            }
            dict = dict->prox;
        }
    }
    return ans;
}

int main(int argc, char *argv[]) {
    FILE *input;
    int r = 0, count = 0;
    char word[100];
    Dicionario d;
    for(int i = 0; i < HSIZE; i++) {
        d[i] = malloc(sizeof(struct entrada));
        d[i] = NULL;
    }
    if (argc == 1) input = stdin;
    else input = fopen(argv[1], "r");
    if (input == NULL) r = 1;
    else {
        while((fscanf(input, "%s", word) == 1)) {
            acrescenta(&d,word);
            count++;
        }
        fclose(input);
        printf("%d palavras\n", count);
    }

    int* c = malloc(sizeof(*c));
    printf("Palavra mais comum: %s - ",maisFreq(d,c));
    printf("aparece %d vez(es)",*c);
    return r;
}