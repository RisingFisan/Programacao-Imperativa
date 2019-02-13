#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1 - Maior da sequência

void one() {
    int maior = 0;
    while(1) {
        int num;
        scanf("%d", &num);
        if(num == 0) break;
        if(num > maior) maior = num;
    }
    printf("Maior: %d\n", maior);
}

// 2 - Média da sequência

void two() {
    double soma = 0;
    int n = 0;
    while(1) {
        int num;
        scanf("%d", &num);
        if(num == 0) break;
        soma += num;
        n++;
    }
    double media = soma / n;
    printf("Media: %.5f\n",media);
}

// 3 - Segundo maior da sequência

void three() {
    int m, sm, num;
    scanf("%d", &m);
    scanf("%d", &num);
    if(num > m) {
        sm = m;
        m = num;
    } else sm = num;
    while(1) {
        scanf("%d", &num);
        if(num == 0) break;
        if(num > m) {
            sm = m;
            m = num;
        } else if (num > sm) sm = num;
    }
    printf("Segundo maior numero: %d\n",sm);
}

// 4 - Nº de bits iguais a 1 na representação binária de n

int bitsUm (unsigned int n){
    int r = 0;
    while(n > 0) {
        r += (n % 2);
        n /= 2;
    }
    return r;
}

// 5

int trailingZ (unsigned int n) {
    if(n % 2) return 0;
    else return 1 + trailingZ(n / 2);
}

// 6

int qDig (unsigned int n) {
    if(n / 10 < 1) return 1;
    else return 1 + qDig(n / 10);
}

// 7

char * mystrcat(char s1[], char s2[]) {
    int sz1 = 0, sz2 = 0;
    char c;
    // As seis linhas abaixo são o mesmo que sz1 = strlen(s1) e sz2 = strlen(s2)
    while((c = s1[sz1]) != '\0') {
        sz1++;
    }
    while((c = s2[sz2]) != '\0') {
        sz2++;
    }
    for(int i = 0; i < sz2; i++)
        s1[i + sz1] = s2[i];
    return s1;
}

// 8

char * mystrcpy(char * dest, char source[]) {
    for(int i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    return dest;
}

// 9

int mystrcmp(char s1[], char s2[]) {
    int i = 0;
    while(s1[i] != '\0' || s2[i] != '\0') {
        if(s1[i] > s2[i]) return 1;
        else if(s2[i] > s1[i]) return -1;
        i++;
    }
    return 0;
}

// 10

char *mystrstr (char haystack[], char needle[]) {
    int i = 0, j = 0, startnum = 0;
    int isContained = 0;
    while(needle[i] != '\0' && haystack[j] != '\0') {
        if(haystack[j] == needle[i]) {
            if(!isContained) {
                isContained = 1;
                startnum = j;
            }
            i++;
        }
        else isContained = 0;
        j++;
    }
    if (isContained) return &haystack[startnum];
    else return NULL;
}

void eleven() {};
void twelve() {};
void thirteen() {};
void fourteen() {};
void fifteen() {};
void sixteen() {};
void seventeen() {};
void eighteen() {};

void getLine(char str[]) {
    char c;
    int i = 0;
    while((c = getchar()) != '\n' || strlen(str) <= 1) {
        str[i] = c;
        i++;
    }
    if(c == '\n') {
        str[i] = '\0';
    }
}

int main(int argc, char const *argv[])
{
    char s1[1000];
    char s2[1000];
    int opcao;
    int num;
    printf("Insere o numero correspondente ao exercicio: ");
    scanf("%d",&opcao);
    switch (opcao)
    {
        case 1:
            one();
            break;
        case 2:
            two();
            break;
        case 3:
            three();
            break;
        case 4:
            printf("Introduz um valor: ");
            scanf("%d",&num);
            int n = bitsUm(num);
            printf("Resposta: %d",n);
            break;
        case 5:
            printf("Introduz um valor: ");
            scanf("%d",&num);
            printf("Resposta: %d",trailingZ(num));
            break;
        case 6:
            printf("Introduz um valor: ");
            scanf("%d",&num);
            printf("Resposta: %d",qDig(num));
            break;
        case 7:
            getLine(s1);
            getLine(s2);
            mystrcat(s1,s2);
            printf("%s",s1);
            break;
        case 8:;
            getLine(s1);
            getLine(s2);
            mystrcpy(s1,s2);
            printf("%s",s1);
            break;
        case 9:
            getLine(s1);
            getLine(s2);
            num = mystrcmp("abc","def");
            printf("Resposta: %d", num);
            break;
        case 10:
            printf("Haystack: ");
            getLine(s1);
            printf("Needle: ");
            getLine(s2);
            char * ans = mystrstr(s1,s2);
            printf("%s",ans);
            break;
        case 11:
            eleven();
            break;
        case 12:
            twelve();
            break;
        case 13:
            thirteen();
            break;
        case 14:
            fourteen();
            break;
        case 15:
            fifteen();
            break;
        case 16:
            sixteen();
            break;
        case 17:
            seventeen();
            break;
        case 18:
            eighteen();
            break;
        default:
            break;
    }
    return 0;
}
