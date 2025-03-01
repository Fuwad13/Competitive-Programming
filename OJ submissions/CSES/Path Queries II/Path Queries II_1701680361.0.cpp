// cc : upobir
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int nmax = 5e5+10;
  int val[nmax];
int sub[nmax], par[nmax], depth[nmax];
vector<int> adj[nmax];
 void dfs_sz(int u, int p){
    sub[u] = 1;
    par[u] = p;
    depth[u] = (p == -1)? 0 : depth[p]+1;
    int mx = 0;
    for(auto &v: adj[u]){
        if(v == p) continue;
        dfs_sz(v, u);
        sub[u] += sub[v];
        if(sub[v] > mx) mx = sub[v], swap(v, adj[u][0]);
    }
}
 int head[nmax];
int st[nmax], en[nmax], clk;
int dfsarr[nmax];
 void dfs_hld(int u, int p){
    st[u] = ++clk;
    dfsarr[clk] = val[u];
    head[u] = (p != -1 && adj[p][0] == u)? head[p] : u;
    for(auto &v : adj[u]){
        if(v == p) continue;
        dfs_hld(v, u);
    }
    en[u] = clk;
}
 struct SegTree{
    #define lc (id<<1)
    #define rc ((id<<1)|1)
     ll tree[4*nmax];
     void build(int id, int l, int r)
    {
        if(l == r)
        {
            tree[id] = dfsarr[l];
            return;
        }
        int mid = (l+r)/2;
        build(lc, l, mid);
        build(rc, mid+1, r);
        tree[id] = max(tree[lc], tree[rc]);
    }
     ll query(int id, int l, int r, int L, int R)
    {
        if(R < l || r < L) return 0;    //Disjoint case, return identity
        if(L <= l && r <= R) return tree[id];   //Subinterval case, return value
         int mid = (l+r)/2;
        ll p = query(lc, l, mid, L, R);
        ll q = query(rc, mid+1, r, L, R);
        return max(p , q);
    }
     void update(int id, int l, int r, int k, int x)
    {
        if(l == r)
        {
            tree[id] = x;              //Assignment
            return;
        }
         int mid = (l+r)/2;
        if(k <= mid) update(lc, l, mid, k, x);
        else update(rc, mid+1, r, k, x);
         tree[id] = max(tree[lc] , tree[rc]);
    }
} ST;
  int n;
ll pathProcess(int a, int b, bool excl = false){
    ll ret = 0;
    for(; head[a] != head[b]; b = par[head[b]]){
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        ret =max(ret, ST.query(1, 1, n, st[head[b]], st[b]));
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret = max(ret, ST.query(1, 1, n, st[a]+excl, st[b]));
    return ret;
}
 int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     int q;
    cin>>n>>q;
     for(int i = 0; i<n; i++) cin>>val[i+1];
     for(int i = 1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
     dfs_sz(1, -1);
    dfs_hld(1, -1);
    ST.build(1, 1, n);
     for(int i = 0; i<q; i++){
        int t;
        cin>>t;
        if(t == 1){
            int u, x;
            cin>>u>>x;
            ST.update(1, 1, n, st[u], x);
        }
        else{
            int u, v;
            cin>>u>>v;
            cout<<pathProcess(u, v, false)<<" ";
        }
    }
       return 0;
}