int not_in_prev(char str[], int k, int n) {
    int ans = 1;
    for(int i = k; i < n; i++)
        if(str[i] == str[n])
            return 0;
    return ans;
}

int difConsecutivos(char s[]) {
    int ans = 0;
    for(int i = 0; s[i]; i++) {
        int consec = 0;
        for(int j = i; s[j]; j++) {
            if(not_in_prev(s,i,j))
                consec++;
            else break;
        }
        if (consec > ans) 
            ans = consec;
    }
    return ans;
}