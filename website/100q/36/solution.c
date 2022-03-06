int comuns (int a[], int na, int b[], int nb) {
    int ans = 0;
    for(int i = 0; i < na; i++) {
        for(int j = 0; j < nb; j++) 
            if(a[i] == b[j]) {
                ans++;
                break; // mimimi eu sei, o JBB não gosta de breaks no meio de ciclos
                       // temos pena, assim é a forma mais eficiente de o fazer
                       // deixo a forma à JBB como exercício para casa
            }
    }
    return ans;
}