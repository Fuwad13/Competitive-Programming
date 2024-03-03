template <class T>
struct sparse_table {
    int n, LG;
    vector<vector<T>> table;
    vector<int> lgs;
    function<T(const T&, const T&)> merge;

    sparse_table(vector<T>& v, function<T(const T&, const T&)> merge): n(v.size()), merge(merge){
        LG = __lg(n) + 1;
        table.assign(LG, vector<T>(n, 0));
        lgs.assign(n+1, 0);
        for(int i = 0; i < n; i++)
            table[0][i] = v[i];
        lgs[1] = 0;
        for(int i = 2; i <=n; i++)
            lgs[i] = lgs[i/2] + 1;
        for(int i = 1; i < LG; i++){
            for(int j = 0; j + (1<<i) - 1 < n; j++){
                table[i][j] = merge(table[i-1][j], table[i-1][j+(1<<(i-1))]);
            }
        }  
    }

    T query(int l, int r){
        int lg = lgs[r-l+1];
        return merge(table[lg][l], table[lg][r-(1<<lg)+1]);
    }
};