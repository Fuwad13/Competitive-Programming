struct matrix{
    vector<vector<ll>> mat;

    matrix(int n, int m){
        mat.resize(n, vector<ll>(m));
    }

    matrix(const vector<vector<ll>>& v){
        int n = v.size(), m = v.front().size();
        mat.resize(n, vector<ll>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                mat[i][j]=v[i][j];
    }

    matrix operator*(const matrix& a){
        int n = this->mat.size(), m = a.mat[0].size();
        assert(this->mat[0].size()==a.mat.size());
        matrix prod(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < (int)a.mat.size(); k++){
                    prod.mat[i][j] = (prod.mat[i][j]+mat[i][k]*a.mat[k][j])%mod;
                }
            }
        }
        return prod;
    }

};

matrix binexp(matrix base, ll exp){
    int n = base.mat.size();
    matrix ret(n, n);
    for(int i = 0; i < n; i++)
        ret.mat[i][i]=1;
    while(exp){
        if(exp&1)
            ret = ret*base;
        base = base*base;
        exp>>=1;
    }
    return ret;
}