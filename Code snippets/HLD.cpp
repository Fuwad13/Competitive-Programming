int n, q, timer = -1;
vector<vector<int>> adj;
vector<int> val, in, out, ssz, depth, parent, head;
vector<ll> euler;
 
void dfs_ssz(int v, int p){
    ssz[v]=1, parent[v]=p;
    int mx = 0;
    for(auto &c: adj[v]){
        if(c!=p){
            depth[c]=1+depth[v];
            dfs_ssz(c, v);
            ssz[v]+=ssz[c];
            if(mx < ssz[c]){
                mx = ssz[c];
                swap(adj[v][0], c);
            }
        }
    }
}
 
void dfs_hld(int v, int p){
    in[v]=++timer;
    euler[timer]=val[v];
    head[v] = (p and adj[p][0]==v) ? head[p] : v;
    for(auto c: adj[v]){
        if(c^p){
            dfs_hld(c, v);
        }
    }
    out[v]=timer;
}
// segtree template here
ll query(int a, int b, segment_tree<ll>& st){
    ll ret = 0;
    for(; head[a]!=head[b]; b = parent[head[b]]){
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        ret = max(ret, st.query(in[head[b]], in[b]));
    }
    if(depth[a]>depth[b]) swap(a, b);
    ret = max(ret, st.query(in[a], in[b]));
    return ret;
}

void update(int a, int b, segment_tree<ll>& st){
    for(; head[a]!=head[b]; b = parent[head[b]]){
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        st.update(in[head[b]], in[b], 1);
    }
    if(depth[a]>depth[b]) swap(a, b);
    st.update(in[a], in[b], 1);
}