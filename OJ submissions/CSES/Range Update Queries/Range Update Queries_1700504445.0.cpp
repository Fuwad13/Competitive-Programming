#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5 + 5;
ll arr[N], segtree[4 * N];
int n, q;
void build(int node, int b, int e) {
    if (b == e) {
        segtree[node] = arr[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(node * 2, b, mid);
    build(node * 2 + 1, mid + 1, e);
    // segtree[node] = segtree[node*2]+segtree[node*2+1];
}
void update(int node, int b, int e, int l, int r, int val) {
    if (l > e or r < b)
        return;
    if (b >= l and e <= r) {
        segtree[node] += val;
        return;
    }
    int mid = (b + e) >> 1;
    update(node * 2, b, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
}
ll query(int node, int b, int e, int ind) {
    if (ind > e or ind < b)
        return 0;
    if (ind <= b and ind >= e) {
        return segtree[node];
    }
    int mid = (b + e) >> 1;
    return segtree[node] + query(node * 2, b, mid, ind) +
           query(node * 2 + 1, mid + 1, e, ind);
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp & 1) {
            int l, r, u;
            cin >> l >> r >> u;
            l--, r--;
            update(1, 0, n - 1, l, r, u);
        } else {
            int k;
            cin >> k;
            k--;
            cout << query(1, 0, n - 1, k) << endl;
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