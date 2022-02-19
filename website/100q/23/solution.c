int palindrome (char s[]) {
    int len = 0;
    for(int i = 0; s[i]; i++) len++;
    for(int i = 0; s[i]; i++)
        if(s[i] != s[len - 1 - i])
            return 0;
    return 1;
}