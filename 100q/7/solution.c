char* strcat(char s1[], char s2[]) {
    int sz1 = 0, j = 0;
    while(s1[sz1] != '\0')
        sz1++;
    while(s2[j] != '\0')
        s1[sz1++] = s2[j++];
    return s1;
}

char* strcat2(char s1[], char s2[]) {
    char* cat = s1;
    while(*s1) s1++;
    while((*s1 = *s2)) {s1++; s2++;}
    return cat;
}