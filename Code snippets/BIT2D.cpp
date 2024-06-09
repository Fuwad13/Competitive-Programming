template <class T>
struct fenwick2d{ // 1 based indexing
    int n, m;
    vector<vector<T>> bit;
    fenwick2d(int n, int m) : n(n), m(m) {bit = vector(n+1, vector<T>(m+1));}
    fenwick2d(const vector<vector<T>>& v) : n(v.size()), m(v[0].size()) {
        bit = vector(n+1, vector<T>(m+1));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                update(i+1, j+1, v[i][j]);
    }
    void update(int x, int y, T val){
        while(x<=n){
            for(int i = y; i <=n; i+=i&-i) bit[x][i]+=val;
            x+=x&-x;
        }
    }
    T query(int x, int y){
        T sum = 0;
        while(x>0){
            for(int i = y; i >0; i-=i&-i) sum+=bit[x][i];
            x-=x&-x;
        }
        return sum;
    }
    T query(int x1, int y1, int x2, int y2){
       T sum1 = query(x2, y2);
       T sum2 = query(x2, y1-1);
       T sum3 = query(x1-1, y2);
       T sum4 = query(x1-1, y1-1);
       return sum1 - sum2 - sum3 + sum4;
    }
};