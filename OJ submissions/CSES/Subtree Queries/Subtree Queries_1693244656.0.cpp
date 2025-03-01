#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v)                                                                \
    for (auto &_ : v)                                                          \
    cin >> _
#define write(v)                                                               \
    for (auto &_ : v)                                                          \
        cout << _ << ' ';                                                      \
    cout << '\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 2e5 + 69;
int n, q;
vector<int> tree[N];
vector<int> raw_val, subtree_size, trav_arr, indexes;
int ind = 0;
// segtree
ll stree[2 * N];
void build() {
    for (int i = n - 1; i > 0; i--)
        stree[i] = stree[i << 1] + stree[i << 1 | 1];
}
void update(int ind, int val) {
    for (stree[ind += n] = val; ind > 1; ind >>= 1)
        stree[ind >> 1] = stree[ind] + stree[ind ^ 1];
}
ll query(int l, int r) { // range sum [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += stree[l++];
        if (r & 1)
            res += stree[--r];
    }
    return res;
}
void dfs(int v, int p) {
    subtree_size[v] = 1;
    indexes[v] = ind;
    trav_arr[ind++] = v;
    for (auto c : tree[v]) {
        if (c != p) {
            dfs(c, v);
            subtree_size[v] += subtree_size[c];
        }
    }
}
void solve() {
    cin >> n >> q;
    raw_val.resize(n);
    trav_arr.resize(n);
    subtree_size.resize(n + 1);
    indexes.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> raw_val[i];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(1, 0);
    for (int i = 0; i < n; i++) {
        stree[i + n] = raw_val[trav_arr[i] - 1];
    }
    build();
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y;
            cin >> x >> y;
            ind = indexes[x];
            update(ind, y);
        } else {
            int x;
            cin >> x;
            ind = indexes[x];
            int r = subtree_size[x];
            cout << query(ind, ind + r) << endl;
        }
    }
}
// #define ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}