#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5 + 5;
int n;
vector<vector<int>> adj;
vector<int> c, euler;
vector<vector<pair<int, int>>> queries;
int timer = 0;
template <class T> struct segment_tree {
    int n;
    vector<T> stree;
    function<T(const T &, const T &)> merge;
    T identity = T();
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
void dfs(int v, int p) {
    euler.push_back(v);
    int x = ++timer;
    for (auto c : adj[v]) {
        if (c ^ p) {
            dfs(c, v);
        }
    }
    queries[timer].push_back({x, v});
}
map<int, int> last;
void solve() {
    cin >> n;
    adj.resize(n + 1);
    c.resize(n + 1);
    queries.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    euler.push_back(69);
    dfs(1, 0);
    segment_tree<int> st(n + 1, [](int a, int b) { return a + b; }, 0);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        st.update(i, 1);
        if (last.count(c[euler[i]]))
            st.update(last[c[euler[i]]], -1);
        for (auto [x, y] : queries[i]) {
            ans[y] = st.query(x, i);
        }
        last[c[euler[i]]] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}