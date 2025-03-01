#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 1e6 + 2;
const ll B = 31;
ll bpow[N];
void prec() {
    bpow[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        bpow[i] = (bpow[i - 1] * B) % mod;
}
struct Node {
    ll fwd, rev, len;
};
template <class T> struct segment_tree {
    int n;
    vector<T> stree;
    function<T(const T &, const T &)> merge;
    T identity = T();
    segment_tree(int n, function<T(const T &, const T &)> merge, T identity)
        : n(n), merge(merge), identity(identity) {
        stree.resize(4 * n + 5);
    }
    void build(const vector<T> &arr, int node, int b, int e) {
        if (b == e) {
            stree[node] = arr[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(arr, 2 * node, b, mid);
        build(arr, 2 * node + 1, mid + 1, e);
        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
    }
    segment_tree(const vector<T> &arr, function<T(const T &, const T &)> merge,
                 T identity)
        : n(arr.size()), merge(merge), identity(identity) {
        stree.resize(4 * n + 5);
        build(arr, 1, 0, n - 1);
    }
    void set(int node, int b, int e, int ind, T val) {
        if (ind > e or ind < b)
            return;
        if (ind <= b and ind >= e) {
            stree[node] = val;
            return;
        }
        int mid = (b + e) >> 1;
        set(2 * node, b, mid, ind, val);
        set(2 * node + 1, mid + 1, e, ind, val);
        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
    }
    void set(int ind, T val) { set(1, 0, n - 1, ind, val); }
    void update(int node, int b, int e, int ind, T val) {
        if (ind > e or ind < b)
            return;
        if (ind <= b and ind >= e) {
            stree[node] = merge(stree[node], val);
            return;
        }
        int mid = (b + e) >> 1;
        update(2 * node, b, mid, ind, val);
        update(2 * node + 1, mid + 1, e, ind, val);
        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
    }
    void update(int ind, T val) { update(1, 0, n - 1, ind, val); }
    T query(int node, int b, int e, int l, int r) {
        if (l > e or r < b)
            return identity;
        if (l <= b and r >= e)
            return stree[node];
        int mid = (b + e) >> 1;
        T c1 = query(2 * node, b, mid, l, r);
        T c2 = query(2 * node + 1, mid + 1, e, l, r);
        return merge(c1, c2);
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        v[i].fwd = v[i].rev = int(ch);
        v[i].len = 1;
    }
    segment_tree<Node> st(
        v,
        [](const Node &a, const Node &b) {
            Node ret;
            ret.fwd = ((a.fwd * bpow[b.len]) % mod + b.fwd) % mod;
            ret.rev = ((b.rev * bpow[a.len]) % mod + a.rev) % mod;
            ret.len = a.len + b.len;
            return ret;
        },
        Node{0, 0, 0});
    while (q--) {
        int tp;
        cin >> tp;
        if (tp & 1) {
            int ind, val;
            char ch;
            cin >> ind >> ch;
            ind--;
            val = int(ch);
            st.set(ind, Node{val, val, 1});
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto temp = st.query(l, r);
            if (temp.fwd == temp.rev) {
                cout << "YES\n";
            } else
                cout << "NO\n";
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    prec();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}