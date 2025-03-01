#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
template <class T> struct segment_tree {
    int n;
    vector<T> stree;
    function<T(const T &, const T &)> merge;
    T identity = T();
    segment_tree() : n(0), merge(nullptr), identity(0) {}
    segment_tree(int n, function<T(const T &, const T &)> merge, T identity)
        : n(n), merge(merge), identity(identity) {
        stree.resize(n << 1);
    }
    void build() {
        for (int i = n - 1; i > 0; i--)
            stree[i] = merge(stree[i << 1], stree[i << 1 | 1]);
    }
    segment_tree(const vector<T> &arr, function<T(const T &, const T &)> merge,
                 T identity)
        : n(arr.size()), merge(merge), identity(identity) {
        stree.resize(n << 1);
        for (int i = 0; i < n; i++)
            stree[i + n] = arr[i];
        build();
    }
    void set(int ind, T val) {
        ind += n;
        for (stree[ind] = val; ind > 1; ind >>= 1) {
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    void update(int ind, T val) {
        ind += n;
        for (stree[ind] = merge(val, stree[ind]); ind > 1; ind >>= 1) {
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    T query(int l, int r) { // closed interval [l,r]
        T ansl = identity;
        T ansr = identity;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ansl = merge(ansl, stree[l++]);
            }
            if (r & 1) {
                ansr = merge(stree[--r], ansr);
            }
        }
        return merge(ansl, ansr);
    }
};
template <class T> struct HLD {
    vector<int> in, out, ssz, depth, parent, head;
    vector<T> val, euler;
    int n, timer;
    vector<vector<int>> adj;
    segment_tree<T> st;
    HLD(int n)
        : n(n), timer(-1), in(n + 1), out(n + 1), ssz(n + 1), depth(n + 1),
          parent(n + 1), head(n + 1), val(n + 1), euler(n + 1) {
        adj.resize(n + 1);
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void assign_val(int v, T x) { val[v] = x; }
    void dfs_ssz(int v, int p) {
        ssz[v] = 1, parent[v] = p;
        int mx = 0;
        for (auto &c : adj[v]) {
            if (c != p) {
                depth[c] = 1 + depth[v];
                dfs_ssz(c, v);
                ssz[v] += ssz[c];
                if (mx < ssz[c]) {
                    mx = ssz[c];
                    swap(adj[v][0], c);
                }
            }
        }
    }
    void dfs_hld(int v, int p) {
        in[v] = ++timer;
        euler[timer] = val[v];
        head[v] = (p and adj[p][0] == v) ? head[p] : v;
        for (auto c : adj[v]) {
            if (c ^ p) {
                dfs_hld(c, v);
            }
        }
        out[v] = timer;
    }
    void decompose(function<T(const T &, const T &)> merge, T identity) {
        dfs_ssz(1, 0);
        dfs_hld(1, 0);
        st = segment_tree<T>(euler, merge, identity);
    }
    T query(int a, int b) {
        T ret = st.identity;
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            ret = st.merge(ret, st.query(in[head[b]], in[b]));
        }
        if (depth[a] > depth[b])
            swap(a, b);
        ret = st.merge(ret, st.query(in[a], in[b]));
        return ret;
    }
    void update(int a, int b, T val) {
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            st.update(in[head[b]], in[b], val);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        st.update(in[a], in[b], val);
    }
    void set(int a, T val) {
        // for(; head[a]!=head[b]; b = parent[head[b]]){
        //     if(depth[head[a]] > depth[head[b]]) swap(a, b);
        //     st.set(in[head[b]], in[b], val);
        // }
        // if(depth[a]>depth[b]) swap(a, b);
        // st.set(in[a], in[b], val);
        st.set(in[a], val);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    HLD<ll> hld(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        hld.assign_val(i, x);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        hld.add_edge(x, y);
    }
    hld.decompose([](ll a, ll b) { return max(a, b); }, -1);
    while (q--) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp & 1) {
            hld.set(l, r);
        } else {
            cout << hld.query(l, r) << " ";
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}