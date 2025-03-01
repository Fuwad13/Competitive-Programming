// cc : upobir
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int nmax = 5e5+10;
  int val[nmax];
int sub[nmax], par[nmax], depth[nmax];
vector<int> adj[nmax];
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
        for (stree[ind] = merge(val, stree[ind]); ind > 1; ind >>= 1){
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
 segment_tree<ll> ST(nmax, [](ll a, ll b){return max(a, b);}, 0LL);
 void dfs_sz(int u, int p){
    sub[u] = 1;
    par[u] = p;
    int mx = 0;
    for(auto &v: adj[u]){
        if(v == p) continue;
        depth[v] = 1+depth[u];
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
    // dfsarr[clk] = val[u];
    ST.set(st[u], val[u]);
    head[u] = (p != -1 && adj[p][0] == u)? head[p] : u;
    for(auto &v : adj[u]){
        if(v == p) continue;
        dfs_hld(v, u);
    }
    en[u] = clk;
}
   int n;
ll pathProcess(int a, int b, bool excl = false){
    ll ret = 0;
    for(; head[a] != head[b]; b = par[head[b]]){
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        ret =max(ret, ST.query(st[head[b]], st[b]));
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret = max(ret, ST.query(st[a]+excl, st[b]));
    return ret;
}
 void main_(){
    auto begin = std::chrono::high_resolution_clock::now();
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
    // ST.build(1, 1, n);
    // auto begin = std::chrono::high_resolution_clock::now();
     for(int i = 0; i<q; i++){
        int t;
        cin>>t;
        if(t == 1){
            int u, x;
            cin>>u>>x;
            ST.set(st[u], x);
        }
        else{
            int u, v;
            cin>>u>>v;
            cout<<pathProcess(u, v, false)<<" ";
        }
    }
     auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " << 
    std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
    << " seconds" << endl;
     // return 0;
}
 static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}
int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}