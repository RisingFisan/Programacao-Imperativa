int bitsUm (unsigned int n){
    int r = 0;
    while(n) {
        r += (n % 2);
        n >>= 1; // Desloca os bits em `n` um bit para a direita, faz o mesmo que n = n / 2
    }
    return r;
}