template <class T>
struct fenwick{ // 1 based indexing
    int n;
    vector<T> bit;
    fenwick(int n) : n(n) {bit.assign(n+1, 0);}
    fenwick(const vector<T>& v) : n(v.size()) {
        bit.assign(n+1, 0);
        for(int i = 0; i < n; i++) update(i+1, v[i]);
    }
    void update(int pos, T val){while(pos<=n)bit[pos]+=val,pos+=pos&-pos;}
    T query(int pos){
       T sum = 0;
       while(pos>0)sum+=bit[pos],pos-=pos&-pos;
       return sum;
    }
    T query(int l, int r){return query(r) - query(l-1);}
};