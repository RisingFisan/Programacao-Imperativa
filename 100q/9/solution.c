int strcmp(char s1[], char s2[]) {
    int i;
    for(i = 0; s1[i] != '\0'; i++)
        if(s1[i] != s2[i])
            break;
    return s1[i] - s2[i];
}

int strcmp2(char s1[], char s2[]) {
    while(*s1 == *s2 && *s1) { s1++; s2++; }
    return *s1 - *s2;
}