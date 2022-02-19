int retiraNeg (int v[], int N) {
    int i = 0;
    while(i < N) {
        if(v[i] < 0) {
            for(int j = i; j < N - 1; j++) v[j] = v[j + 1];
            N--;
        }
        else i++;
    }
    return N;
}