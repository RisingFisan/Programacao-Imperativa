int maiorSufixo (char s1 [], char s2 []) {
    int i, j, ans = 0;
    for(i = 0; s1[i]; i++); // i é o tamanho de s1
    for(j = 0; s2[j]; j++); // j é o tamanho de s2
    while(s1[--i] == s2[--j]) ans++;
    return ans;
}
