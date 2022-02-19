int maxCresc (int v[], int N) {
    int ans = 1, currAns = 1;
    for(int i = 1; i < N; i++) {
        if(v[i - 1] > v[i]) {
            ans = currAns > ans ? currAns : ans;
            currAns = 1;
        }
        else {
            currAns++;
        }
    }
    ans = currAns > ans ? currAns : ans;
    return ans;
}
