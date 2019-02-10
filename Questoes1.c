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
    printf("Maior: %d", maior);
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
    printf("%.5f",media);
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
    printf("Segundo maior numero: %d",sm);
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

void mystrcat(char s1[], char s2[]) {
    int sz1 = strlen(s1);
    int sz2 = strlen(s2);
    for(int i = 0; i < sz2; i++)
        s1[i + sz1] = s2[i];
}


void eight() {};
void nine() {};
void ten() {};
void eleven() {};
void twelve() {};
void thirteen() {};
void fourteen() {};
void fifteen() {};
void sixteen() {};
void seventeen() {};
void eighteen() {};

int main(int argc, char const *argv[])
{
    int opcao;
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
            int num;
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
        case 7:;
            char ar[] = "Hello ";
            char arr[] = "There!" ;
            //scanf("%s",&ar);
            //scanf("%s",&arr);
            mystrcat(ar,arr);
            printf("%s",ar);
            break;
        case 8:;
            eight();
            break;
        case 9:
            nine();
            break;
        case 10:
            ten();
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
