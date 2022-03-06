void media() {
    double soma = 0;
    int n = 0;
    while(1) {
        int num;
        assert(scanf("%d",&num) == 1);
        if(num == 0) break;
        soma += num;
        n++;
    }
    double media = soma / n;
    printf("Média: %.5f\n", media);
}