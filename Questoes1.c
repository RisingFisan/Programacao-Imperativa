#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

// 1 - Maior da sequência

void one() {
    int maior;
    scanf("%d", &maior);
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
    int sz1 = 0, i;
    while(s1[sz1]) sz1++;
    for(i = 0; s2[i]; i++)
        s1[i + sz1] = s2[i];
    s1[sz1 + i + 1] = '\0';
    return s1;
}

// 8

char * mystrcpy(char * dest, char source[]) {
    int i;
    for(i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    while(dest[i] != '\0') {
        dest[i] = '\0';
        i++;
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
    int isContained = 1;
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

// 11

void mystrrev(char s[]) {
    int len = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        len++;    
    }
    char rev[len];
    for(int i = 0; i < len; i++) {
        rev[i] = s[len - i - 1];
    }
    for(int i = 0; i < len; i++) {
        s[i] = rev[i];
    }
}

// 12

void removeIndex(char s[], int n) {
    for(int j = n; s[j - 1] != '\0'; j++) {
        s[j] = s[j + 1];
    }
}

void strnoV (char s[]) {
    int i = 0;
    char c;
    while((c = s[i]) != '\0') {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a'
        || c == 'e' || c == 'i' || c == 'o' || c == 'u') removeIndex(s, i);
        else i++;
    }
}

// 13

void truncW (char t[], int n) {
    int wordLen = 0;
    int i = 0;
    char c;
    while((c = t[i]) != '\0') {
        if(c == ' ' || c == '\n' || c == '\t') {i++; wordLen = 0;}
        else {
            if(wordLen >= n) removeIndex(t, i);
            else {i++; wordLen++;}
        }
    } 
}

// 14

char charMaisfreq (char s[]) {
    int charFreq[256];
    int freqMax = 0;
    char maisFreq = s[0];
    for(int i = 0; i < 256; i++) charFreq[i] = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        int c = s[i];
        charFreq[c] += 1;
        if(charFreq[c] > freqMax) {
            freqMax = charFreq[c];
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

// 15

int iguaisConsecutivos (char s[]) {
    int consec = 0, max = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == s[i - 1]) consec++;
        else {
            if(consec > max) max = consec;
            consec = 1;
        }
    }
    if(consec > max) max = consec;
    return max;
}

// 16

int not_in(char c, char str[]) {
    int acc = 1;
    for(int i = 0; str[i]; i++) {
        if(c == str[i]) acc = 0;
        else continue;
    } 
    return acc;
}

int difConsecutivos (char s[]) {
    char acc[256];
    int differ = 0, max = 0;
    for(int i = 0; s[i]; i++) {
        if(not_in(s[i],acc)) acc[differ++] = s[i];
        else {
            if(differ > max) max = differ;
            for(int j = 0; acc[j]; j++) {
               acc[j] = '\0'; 
            }
            differ = 0;
            acc[differ++] = s[i];
        }
    }
    if(differ > max) max = differ;
    return max;
}

// 17

int maiorPrefixo (char s1 [], char s2 []) {
    int acc = 0;
    for(int i = 0; s1[i] && s2[i]; i++) {
        if(s1[i] == s2[i]) acc++;
        else break;
    }
    return acc;
}

// 18

int maiorSufixo (char s1 [], char s2 []) {
    mystrrev(s1);
    mystrrev(s2);
    return maiorPrefixo(s1,s2);
}

// 19

int sufPref (char s1[], char s2[]) {
    int ans = 1;
    char s1x[strlen(s1)];
    char s2x[strlen(s2)];
    for(int i = 0; s1[i] && s2[i]; i++) {
        mystrrev(s1);
        strncpy(s1x,s1,i + 1);
        mystrrev(s1);
        mystrrev(s1x);
        strncpy(s2x,s2,i + 1);
        if(strcmp(s1x,s2x) == 0) ans = i + 1;
    }
    return ans;
}

// 20

int contaPal (char s[]) {
    int inWord = 0;
    int total = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
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

// 21

int contaVogais (char s[]) {
    int total = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                total++;
        }
    }
    return total;
}

// 22

int contida (char a[], char b[]) {
    int cont = 1;
    for(int i = 0; a[i] != '\0'; i++) {
        int pertence = 0;
        for(int j = 0; b[j] != '\0'; j++) {
            if(a[i] == b[j]) pertence = 1;
        }
        if(!pertence) {
            cont = 0;
            break;
        }
    }
    return cont;
}

// 23

int palindrome (char s[]) {
    int len = 0, pal = 1;
    for(int i = 0; s[i] != '\0'; i++) len++;
    for(int i  =0; s[i] != '\0'; i++) if(s[i] != s[len - 1 - i]) pal = 0;
    return pal;
}

// 24

int remRep (char x[]) {
    int i = 1;
    char prev = x[0];
    while(x[i] != '\0') {
        if(x[i] == prev) removeIndex(x,i);
        else prev = x[i++];
    }
    return i;
}

// 25

int limpaEspacos (char t[]) {
    int i = 0;
    int prevSpace = 0;
    while(t[i] != '\0') {
        if(t[i] == ' ') {
            if(prevSpace) removeIndex(t,i);
            else {
                prevSpace = 1;
                i++;
            }
        }
        else { 
            prevSpace = 0;
            i++;
        }
    }
    return i;
}

// 26

void insere (int v[], int N, int x) {
    for(int i = 0; i < N; i++) {
        if(v[i] > x) {
            for(int j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
            v[i] = x;
            break;
        }
        if(i == N - 1) {
            v[i + 1] = x;
        }
    }
}

// 27

void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;
    while(k < na + nb) {
        if((a[i] < b[j] && i < na && j < nb) || j >= nb)
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
}

// 28

int crescente (int a[], int i, int j) {
    int cresc = 1;
    for(int k = i; k < j; k++) {
        if(a[k + 1] < a[k]) cresc = 0;
    }
    return cresc;
}

// 29

int retiraNeg (int v[], int N) {
    for(int i = 0; i < N; i++) {
        if(v[i] < 0) {
            for(int j = i; j < N; j++) v[j] = v[j + 1];
            N--;
        }
    }
    return N;
}

// 30

int menosFreq (int v[], int N) {
    int freq = 1, minFreq = N + 1, ans = v[0];
    for(int i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) {
            freq++;
        }
        if(v[i] != v[i + 1] || i == N - 1) {
            if(freq < minFreq) {
                minFreq = freq;
                ans = v[i];
            }
            freq = 1;
        }
    }
    return ans;
}

// 31

int maisFreq (int v[], int N) {
    int freq = 1, maxFreq = 0, ans = v[0];
    for(int i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1] || i == N - 1) {
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    return ans;
}

// 32

int maxCresc (int v[], int N) {
    int ans = 1, currAns = 1;
    for(int i = 1; i < N; i++) {
        if(v[i - 1] > v[i]) {
            ans = currAns > ans ? currAns : ans;
            currAns = 1;
        }
        else {
            currAns++;
        }
    }
    ans = currAns > ans ? currAns : ans;
    return ans;
}

// 33

int elimRep (int v[], int n) {
    for(int i = 1; i < n; i++) {
        int belongs = 0;
        for(int j = 0; j < i; j++) {
            if(v[i] == v[j]) belongs = 1;
        }
        if(belongs) {
            for(int j = i; j < n; j++) {
                v[j] = v[j + 1];
            }
            n--;
        }
    }
    return n;
}

void getLine(char str[], int lim) {
    char c;
    int i = 0;
    while((c = getchar()) != '\n' && i < lim) {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
}

void getIntArray(int arr[], int lim) {
    for(int i = 0; i < lim; i++) {
        printf("Insere um valor: ");
        scanf("%d",&arr[i]);
    }
}

void printArray(int arr[], int lim) {
    printf("[");
    for(int i = 0; i < lim; i++) {
        if(i == lim - 1) printf("%d",arr[i]);
        else printf("%d ,",arr[i]);
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    char s1[MAXLINE];
    char s2[MAXLINE];
    int opcao, num, num1, num2, resp;
    printf("Insere o numero correspondente ao exercicio: ");
    scanf("%d",&opcao);
    char c;
    while((c= getchar()) != '\n' && c != EOF) {} // Ao usar o scanf, o caracter '\n' permanece no buffer. Este while vê-se livre do '\n', para não estragar os getLine em baixo.
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
            printf("Resposta: %d\n",n);
            break;
        case 5:
            printf("Introduz um valor: ");
            scanf("%d",&num);
            printf("Resposta: %d\n",trailingZ(num));
            break;
        case 6:
            printf("Introduz um valor: ");
            scanf("%d",&num);
            printf("Resposta: %d\n",qDig(num));
            break;
        case 7:
            getLine(s1,MAXLINE);
            getLine(s2,MAXLINE);
            mystrcat(s1,s2);
            printf("%s",s1);
            break;
        case 8:
            getLine(s1,MAXLINE);
            getLine(s2,MAXLINE);
            mystrcpy(s1,s2);
            printf("%s",s1);
            break;
        case 9:
            getLine(s1,MAXLINE);
            getLine(s2,MAXLINE);
            num = mystrcmp(s1,s2);
            printf("Resposta: %d", num);
            break;
        case 10:
            printf("Haystack: ");
            getLine(s1,MAXLINE);
            printf("Needle: ");
            getLine(s2,MAXLINE);
            char * ans = mystrstr(s1,s2);
            printf("%s",ans);
            break;
        case 11:
            getLine(s1,MAXLINE);
            mystrrev(s1);
            printf("%s",s1);
            break;
        case 12:
            getLine(s1,MAXLINE);
            strnoV(s1);
            printf("%s",s1);
            break;
        case 13:
            getLine(s1,MAXLINE);
            scanf("%d",&num);
            truncW(s1,num);
            printf("%s",s1);
            break;
        case 14:
            getLine(s1,MAXLINE);
            printf("%c",charMaisfreq(s1));
            break;
        case 15:
            getLine(s1,MAXLINE);
            printf("%d",iguaisConsecutivos(s1));
            break;
        case 16:
            getLine(s1,MAXLINE);
            printf("%d\n",difConsecutivos(s1));
            break;
        case 17:
            getLine(s1,MAXLINE);
            getLine(s2,MAXLINE);
            printf("%d\n",maiorPrefixo(s1,s2));
            break;
        case 18:
            getLine(s1,MAXLINE);
            getLine(s2,MAXLINE);
            printf("%d\n",maiorSufixo(s1,s2));
            break;
        case 19:
            getLine(s1,MAXLINE);
            getLine(s2,MAXLINE);
            printf("%d\n",sufPref(s1,s2));
            break;
        case 20:
            getLine(s1,MAXLINE);
            printf("%d\n",contaPal(s1));
            break;
        case 21:
            getLine(s1,MAXLINE);
            printf("%d\n",contaVogais(s1));
            break;
        case 22:
            getLine(s1,MAXLINE);
            getLine(s2,MAXLINE);
            resp = contida(s1,s2);
            if(resp) printf("Verdadeiro.\n");
            else printf("Falso.\n");
            break;
        case 23:
            getLine(s1,MAXLINE);
            resp = palindrome(s1);
            if(resp) printf("Verdadeiro.\n");
            else printf("Falso.\n");
            break;
        case 24:
            getLine(s1,MAXLINE);
            resp = remRep(s1);
            printf("%s - length: %d", s1, resp);
            break;
        case 25:
            getLine(s1,MAXLINE);
            resp = limpaEspacos(s1);
            printf("%s - length: %d", s1, resp);
            break;
        case 26: {
            printf("Tamanho da lista ordenada: ");
            scanf("%d",&num);
            int nums[num];
            getIntArray(nums,num);
            printf("Valor a inserir: ");
            scanf("%d",&resp);
            insere(nums,num,resp);
            for(int i = 0; i <= num; i++) printf("%d ", nums[i]);
            break; }
        case 27: {
            printf("Tamanho da lista ordenada 1: ");
            scanf("%d", &num1);
            int nums1[num1];
            getIntArray(nums1,num1);
            printf("Tamanho da lista ordenada 2: ");
            scanf("%d", &num2);
            int nums2[num2];
            getIntArray(nums2,num2);
            int r[num1+num2];
            merge(r,nums1,nums2,num1,num2);
            for(int i = 0; i < num1 + num2; i++) printf("%d ",r[i]);
            break; }
        case 28: {
            printf("Tamanho da lista: ");
            scanf("%d", &num);
            int nums[num];
            getIntArray(nums,num);
            printf("Limite mínimo e máximo: ");
            scanf("%d %d",&num1,&num2);
            resp = crescente(nums,num1,num2);
            if(resp) printf("Verdadeiro.\n");
            else printf("Falso.\n");
            break; }
        case 29: {
            printf("Tamanho da lista: ");
            scanf("%d", &num);
            int nums[num];
            getIntArray(nums,num);
            resp = retiraNeg(nums,num);
            printArray(nums,resp);
            printf("Resposta: %d", resp);
            break; }
        case 30: {
            printf("Tamanho da lista crescente: ");
            scanf("%d", &num);
            int nums[num];
            getIntArray(nums,num);
            resp = menosFreq(nums,num);
            printf("Resposta: %d", resp);
            break; }
        case 31: {
            printf("Tamanho da lista crescente: ");
            scanf("%d", &num);
            int nums[num];
            getIntArray(nums,num);
            resp = maisFreq(nums,num);
            printf("Resposta: %d", resp);
            break; }
        case 32: {
            printf("Tamanho da lista: ");
            scanf("%d", &num);
            int nums[num];
            getIntArray(nums,num);
            resp = maxCresc(nums,num);
            printf("Resposta: %d", resp);
            break; }
        case 33: {
            printf("Tamanho da lista: ");
            scanf("%d", &num);
            int nums[num];
            getIntArray(nums,num);
            resp = elimRep(nums,num);
            printArray(nums,resp);
            printf("Resposta: %d", resp);
            break; }
            break;
        case 34:
            break;
        case 35:
            break;
        case 36:
            break;
        case 37:
            break;
        case 38:
            break;
        case 39:
            break;
        case 40:
            break;
        case 41:
            break;
        case 42:
            break;
        case 43:
            break;
        case 44:
            break;
        case 45:
            break;
        case 46:
            break;
        case 47:
            break;
        case 48:
            break;
        case 49:
            break;
    }
    printf("\n");
    return 0;
}
