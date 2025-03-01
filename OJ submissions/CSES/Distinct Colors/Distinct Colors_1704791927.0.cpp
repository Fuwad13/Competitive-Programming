#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5+69;
 int n, timer = -1;
vector<int> adj[N];
vector<int> col(N), in(N), out(N), euler(N);
 void dfs(int v, int p){
    in[v] = ++timer;
    euler[timer] = col[v];
    for(auto c: adj[v]){
        if(c^p){
            dfs(c,v);
        }
    }
    out[v] = timer;
}
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
 void solve(){
    cin>>n;
    for(int i = 1; i <=n; i++){
        cin>>col[i];
    }
    for(int i= 0; i < n-1; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    vector<vector<pair<int, int>>> queries(n);
    for(int i = 1; i <=n; i++){
        queries[out[i]].push_back({in[i], i});
    }
    vector<int> ans(n+1);
    segment_tree<int> st(n+5, [](int a, int b){return a+b;}, 0);
    map<int, int> last;
    for(int r = 0; r < n; r++){
        if(last.count(euler[r])){
            st.update(last[euler[r]], -1);
        }
        last[euler[r]] = r;
        st.update(r, 1);
        for(auto [l, id]: queries[r]){
            ans[id] = st.query(l, r);
        }
    }
    for(int i = 1; i <=n; i++)
        cout << ans[i] << " ";
 }
 signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    return 0;
}