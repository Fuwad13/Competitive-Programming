#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, k, k2;
vector<int> tree[N];
// int cnt[N];
int subtree_size[N];
bool bad[N];
int mx;
ll ans = 0;
vector<ll> dists;
int stree[2 * N];
void build() {
    for (int i = n - 1; i > 0; i--)
        stree[i] = stree[i << 1] + stree[i << 1 | 1];
}
void update(int ind, int val) {
    for (stree[ind += n] = val; ind > 1; ind >>= 1)
        stree[ind >> 1] = stree[ind] + stree[ind ^ 1];
}
int query(int l, int r) { // range sum [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += stree[l++];
        if (r & 1)
            res += stree[--r];
    }
    return res;
}
void calc_ssz(int v, int p) {
    subtree_size[v] = 1;
    for (auto c : tree[v]) {
        if (!bad[c] and c != p) {
            calc_ssz(c, v);
            subtree_size[v] += subtree_size[c];
        }
    }
}
int get_centroid(int v, int p, int sz) {
    for (auto c : tree[v]) {
        if (!bad[c] and c != p and subtree_size[c] * 2 > sz)
            return get_centroid(c, v, sz);
    }
    return v;
}
void calc(int v, int p, int depth) {
    if (dists.size() == depth)
        dists.pb(0);
    dists[depth]++;
    for (auto c : tree[v]) {
        if (!bad[c] and c != p) {
            calc(c, v, depth + 1);
        }
    }
}
void decompose(int v, int p) {
    calc_ssz(v, p);
    int cen = get_centroid(v, p, subtree_size[v]);
    bad[cen] = 1;
    update(0, 1);
    int iter = 1;
    for (auto c : tree[cen]) {
        if (!bad[c]) {
            dists = vector<ll>(1);
            calc(c, cen, 1);
            for (int i = 0; i < dists.size(); i++) {
                if (k - i >= iter or k2 - i < 0)
                    continue;
                int l = max(0, k - i);
                int r = min(iter - 1, k2 - i);
                r++;
                ans += dists[i] * 1LL * query(l, r);
            }
            // update part
            for (int i = 0; i < dists.size(); i++) {
                if (iter == i) {
                    iter++;
                    update(i, dists[i]);
                }
                else {
                    update(i, query(i, i + 1) + dists[i]);
                }
            }
        }
    }
    for (auto c : tree[cen]) {
        if (!bad[c]) {
            decompose(c, cen);
        }
    }
}
void solve() {
    cin >> n >> k >> k2;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    // cnt[0]=1;
    if (k == 1 and k2 >= n - 1) {
        cout << (n * 1LL * (n - 1)) / 2 << endl;
        return;
    }
    decompose(1, 0);
    cout << ans << endl;
}
//#define ONLINE_JUDGE
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