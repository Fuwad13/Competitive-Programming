template <class T>
struct segment_tree{
    int n;
    vector<T> stree;
    function<T(const T&, const T&)> merge;
    T identity = T();
    segment_tree(int n, function<T(const T&, const T&)> merge, T identity): n(n), merge(merge), identity(identity){
        stree.resize(4*n+5);
    }
    void build(const vector<T>& arr, int node, int b, int e){
        if(b==e){
            stree[node] = arr[b];
            return;
        }
        int mid = (b+e)>>1;
        build(arr, 2*node, b, mid);
        build(arr, 2*node+1, mid+1, e);
        stree[node] = merge(stree[2*node],stree[2*node+1]);
    }
    segment_tree(const vector<T>& arr, function<T(const T&, const T&)> merge, T identity): n(arr.size()), merge(merge), identity(identity){
        stree.resize(4*n+5);
        build(arr, 1, 0, n-1);
    }
    void set(int node, int b, int e, int ind, T val){
        if(ind > e or ind < b)
            return;
        if(ind<=b and ind>=e){
            stree[node] = val; 
            return;
        }
        int mid = (b+e)>>1;
        set(2*node, b, mid, ind, val);
        set(2*node+1, mid+1, e, ind, val);
        stree[node] = merge(stree[2*node],stree[2*node+1]);
    
    }
    void set(int ind, T val){set(1, 0, n-1, ind, val);}

    void update(int node, int b, int e, int ind, T val){
        if(ind > e or ind < b)
            return;
        if(ind<=b and ind>=e){
            stree[node] = merge(stree[node], val);
            return;
        }
        int mid = (b+e)>>1;
        update(2*node, b, mid, ind, val);
        update(2*node+1, mid+1, e, ind, val);
        stree[node] = merge(stree[2*node],stree[2*node+1]);
    }
    void update(int ind, T val){update(1, 0, n-1, ind, val);}

    T query(int node, int b, int e, int l, int r){
        if(l > e or r < b)
            return identity;
        if(l<=b and r>=e)
            return stree[node];
        int mid = (b+e)>>1;
        T c1 = query(2*node, b, mid, l, r);
        T c2 = query(2*node+1, mid+1, e, l, r);
        return merge(c1,c2);
    }
    T query(int l, int r){return query(1, 0, n-1, l, r);}
};


// iterative

template <class T>
struct segment_tree{
    int n;
    vector<T> stree;
    function<T(const T&, const T&)> merge;
    T identity = T();
    segment_tree(int n, function<T(const T&, const T&)> merge, T identity): n(n), merge(merge), identity(identity){
        stree.resize(n<<1);
    }
    void build(){
        for (int i = n - 1; i > 0; i--)
            stree[i] = merge(stree[i << 1], stree[i << 1 | 1]);
    }
    segment_tree(const vector<T>& arr, function<T(const T&, const T&)> merge, T identity): n(arr.size()), merge(merge), identity(identity){
        stree.resize(n<<1);
        for(int i=0; i<n; i++)
            stree[i+n] = arr[i];
        build();
    }
    void set(int ind, T val){
        ind+=n;
        for (stree[ind] = val; ind > 1; ind >>= 1){
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    void update(int ind, T val){
        ind+=n;
        for (stree[ind] += val; ind > 1; ind >>= 1){
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    T query(int l, int r){ // closed interval [l,r]
        T ansl = identity;
        T ansr = identity;
        for (l+=n, r+=n+1; l<r; l>>=1, r>>=1)
        {
            if (l&1){
                ansl = merge(ansl, stree[l++]);
            }
            if (r&1){
                ansr = merge(stree[--r], ansr);
            }
        }
        return merge(ansl, ansr);
    }
};