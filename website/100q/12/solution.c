void strnoV (char s[]) {
    int i = 0;
    while(s[i]) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a'
        || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') 
            for(int j = i; s[j]; j++)
                s[j] = s[j+1];
        else i++;
    }
}