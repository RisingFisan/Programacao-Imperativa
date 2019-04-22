#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entrada {
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras;

typedef Palavras Dicionario;

void initDic (Dicionario* d) {
    while(*d) {
        Dicionario temp = *d;
        *d = temp->prox;
        free(temp);
    }
}

int acrescenta (Dicionario* d, char* pal) {
    Dicionario new = malloc(sizeof(struct entrada));
    Dicionario prev = *d;
    new->palavra = malloc(strlen(pal));
    strcpy(new->palavra,pal);
    new->ocorr = 1;
    new->prox = NULL;
    if(!(*d))
        *d = new;
    else {
        Dicionario curr = (*d);
        prev = NULL;
        while(curr) {
            if(strcmp(curr->palavra,pal) == 0) {
                curr->ocorr++;
                return curr->ocorr;
            }
            if(strcmp(curr->palavra,pal) > 0) {
                new->prox = curr;
                if(!prev) *d = new;
                else prev->prox = new;
                return 1;
            }
            prev = curr;
            curr = curr->prox;
        }
        prev->prox = new;
    }
    return 1;
}

char *maisFreq (Dicionario d, int* c) {
    int max = 0;
    char* ans;
    while(d) {
        if(d->ocorr > max) {
            ans = d->palavra;
            *c = max = d->ocorr;
        }
        d = d->prox;
    }
    return ans;
}

void printDict(Dicionario d) {
    printf("***DICIONARIO***\n");
    while(d) {
        printf("%s: %d\n",d->palavra,d->ocorr);
        d = d->prox;
    }
}

int main(int argc, char *argv[]) {
    FILE *input;
    int r = 0, count = 0;
    char word[100];
    Dicionario d = malloc(sizeof(struct entrada));
    d = NULL;
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