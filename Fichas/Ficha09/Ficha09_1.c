#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct abin {
    char *pal;
    int ocorr;
    struct abin *esq, *dir;
} * Dicionario;

void initDic(Dicionario *d) {
    if((*d) != NULL) {
        Dicionario dict = (*d);
        initDic(&(dict->esq));
        initDic(&(dict->dir));
        dict->esq = dict->dir = NULL;
        free(dict);
        (*d) = NULL;
    }
}

int acrescenta (Dicionario* d, char* pal) {
    Dicionario new = malloc(sizeof(struct abin));
    new->pal = calloc(strlen(pal),1);
    strcpy(new->pal,pal);
    new->ocorr = 1;
    new->esq = new->dir = NULL;
    if(!(*d)) {
        (*d) = new;
        return 1;
    }
    int x = strcmp((*d)->pal,pal);
    if(x == 0) {
        return ++((*d)->ocorr);
    }
    else if(x > 0) {
        if((*d)->esq)
            acrescenta(&((*d)->esq),pal);
        else 
            (*d)->esq = new;
    }
    else {
        if((*d)->dir)
            acrescenta(&((*d)->dir),pal);
        else 
            (*d)->dir = new;
    }
    return 1;
}

char *maisFreq (Dicionario d, int *c) {
    if(!d) {
        *c = 0;
        return "";
    }
    int cl, cr;
    char *maisFreqLeft = maisFreq(d->esq,&cl);
    char *maisFreqRight = maisFreq(d->dir,&cr);
    if(d->ocorr > cl && d->ocorr > cr) {
        *c = d->ocorr;
        return d->pal;
    }
    else if(cl > cr) {
        *c = cl;
        return maisFreqLeft;
    }
    else {
        *c = cr;
        return maisFreqRight;
    }
}

void printDict(Dicionario d) {
    if(d != NULL) {
        printDict(d->esq);
        printf("%2d ocorrencias: %s\n",d->ocorr,d->pal);
        printDict(d->dir);
    } 
}

int main() {
    Dicionario dict = malloc(sizeof(struct abin));
    dict = NULL;
    acrescenta(&dict,"Sofia");
    acrescenta(&dict,"Filipa");
    acrescenta(&dict,"Santejo");
    acrescenta(&dict,"Luis");
    acrescenta(&dict,"Arya");
    acrescenta(&dict,"Daenerys");
    acrescenta(&dict,"Jon");
    acrescenta(&dict,"Sofia");
    acrescenta(&dict,"Luis");
    acrescenta(&dict,"Jon");
    acrescenta(&dict,"Sofia");
    printDict(dict);
    int c;
    char* palMaisFreq = maisFreq(dict,&c);
    printf("Palavra mais frequente: %s - aparece %d vezes",palMaisFreq,c);
}