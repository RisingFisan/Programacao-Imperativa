int remRep (char x[]) {
    if(!(*x)) return 0;
    int i = 1;
    char prev = x[0];
    while(x[i]) {
        if(x[i] == prev) 
            for(int j = i; x[j]; j++)
                x[j] = x[j+1];
        else prev = x[i++];
    }
    return i;
}