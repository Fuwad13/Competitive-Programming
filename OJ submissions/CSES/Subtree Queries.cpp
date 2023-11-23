#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
template<class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n"
#define pb push_back
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
// ll stree[2*N];
// void build(){
//     for(int i = n-1; i>0; i--){
//         stree[i] = min(stree[i<<1] , stree[i<<1|1]);
//     }
// }
// void update(int ind, int val){
//     for(stree[ind+=n]=val; ind>1; ind>>=1)
//         stree[ind>>1] = min(stree[ind] , stree[ind^1]);
// }
// ll query(int l, int r){ // range query [l, r)
//     ll res = INT_MAX;
//     for(l+=n, r+=n; l<r; l>>=1, r>>=1){
//         if(l&1)
//             res=min(stree[l++], res);
//         if(r&1)
//             res=min(res, stree[--r]);
//     }
//     return res;
// }
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1);
    for (int i = 0; i < n; i++)
        cin >> val[i + 1];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> start(n + 1), ssz(n + 1), euler_tour;
    vector<ll> segtree(2 * n);
    auto dfs = [&](auto dfs, int v, int p) -> void {
        ssz[v] = 1;
        start[v] = euler_tour.size();
        euler_tour.push_back(v);
        segtree[n + start[v]] = val[v];
        for (auto c : adj[v]) {
            if (c ^ p) {
                dfs(dfs, c, v);
                ssz[v] += ssz[c];
            }
        }
    };
    dfs(dfs, 1, 0);
    // building segtree
    for (int i = n - 1; i > 0; i--) {
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
    auto update = [&](int ind, int v) -> void {
        for (segtree[ind += n] = v; ind > 1; ind >>= 1) {
            segtree[ind >> 1] = segtree[ind] + segtree[ind ^ 1];
        }
    };
    auto query = [&](int l, int r) -> ll {
        ll ret = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ret += segtree[l++];
            if (r & 1)
                ret += segtree[--r];
        }
        return ret;
    };
    while (q--) {
        int tp;
        cin >> tp;
        if (tp & 1) {
            int x, y;
            cin >> x >> y;
            update(start[x], y);
        }
        else {
            int x;
            cin >> x;
            cout << query(start[x], start[x] + ssz[x] - 1) << endl;
        }
    }
}
//#define ONLINE_JUDGE
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " <<
         std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count()
         << " seconds" << endl;
    return 0;
}