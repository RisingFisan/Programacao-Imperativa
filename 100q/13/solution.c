void truncW (char t[], int n) {
    int wordLen = 0, i = 0;
    while(t[i]) {
        if(t[i] == ' ' || t[i] == '\n' || t[i] == '\t') {
            i++; 
            wordLen = 0;
        }
        else {
            if(wordLen++ >= n) 
                for(int j = i; t[j]; j++)
                    t[j] = t[j+1];
            else i++;
        }
    } 
}