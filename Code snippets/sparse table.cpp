const int LG = 25; // floor(log2(N)) + 1]
int st[LG][N+1], lgs[N+1];

void sparse_table(vector<int>& v, int n){
    for(int i = 0; i < n; i++)
        st[0][i] = v[i];
    lgs[1] = 0;
    for(int i = 2; i <=n; i++)
        lgs[i] = lgs[i/2] + 1;
    for(int i = 1; i < LG; i++){
        for(int j = 0; j + (1<<i) - 1 < n; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }  
}

int rmq(int l, int r){
    int lg = lgs[r-l+1];
    return min(st[lg][l], st[lg][r-(1<<lg)+1]);
}