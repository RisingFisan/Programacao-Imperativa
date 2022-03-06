int limpaEspacos (char t[]) {
    int i = 0;
    int prevSpace = 0;
    while(t[i]) {
        if(t[i] == ' ') {
            if(prevSpace) {
                for(int j = i; t[j]; j++)
                    t[j] = t[j+1];
                continue;
            }
            else prevSpace = 1;
        }
        else prevSpace = 0;
        i++;
    }
    return i;
}