char* strstr (char haystack[], char needle[]) {
    int i = 0, j = 0, isContained = 1;
    char* ans = haystack;
    while(needle[i] && haystack[j]) {
        if(haystack[j] != needle[i]) isContained = i = 0;
        if(haystack[j] == needle[i]) {
            if(!isContained) {
                isContained = 1;
                ans = haystack + j;
            }
            i++;
        }
        j++;
    }
    if (isContained && !needle[i]) return ans;
    else return '\0';
}