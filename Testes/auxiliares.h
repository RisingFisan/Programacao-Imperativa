typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

void getLine(char str[], int lim);
void getIntArray(int arr[], int lim);
void printArray(int arr[], int lim);
void getIntMatrix(int m, int n, int mat[m][n]);
void printIntMatrix(int m, int n, int mat[m][n]);
LInt getLInt(int len);
void printLInt(LInt l);
ABin getBTree();
void printBTreeUtil(ABin root, int space);
void printBTree(ABin root);