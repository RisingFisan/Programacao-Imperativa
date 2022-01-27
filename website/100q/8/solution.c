char* strcpy(char* dest, char source[]) {
    int i;
    for(i = 0; source[i] != '\0'; i++)
        dest[i] = source[i];
    return dest;
}

char* strcpy2(char* dest, char source[]) {
    char* result = dest;
    while((*dest = *source)) { source++; dest++; }
    return result;
}