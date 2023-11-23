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
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9 + 7;
const int N = 2e5;
void solve() {
    int n, q;
    cin >> n >> q;
    int l = ceil(log2(n));
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> level(n + 1);
    vector<array<int, 20>> ancs(n + 1);
    auto dfs = [&](auto dfs, int v, int p) -> void {
        ancs[v][0] = p;
        for (int i = 1; i <= l; i++) {
            ancs[v][i] = ancs[ancs[v][i - 1]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c ^ p) {
                level[c] = 1 + level[v];
                dfs(dfs, c, v);
            }
        }
    };
    dfs(dfs, 1, 0);
    auto lca = [&](int x, int y) -> int {
        if (level[x] < level[y])
            swap(x, y);
        for (int i = l; i >= 0; i--) {
            if (level[y] + (1 << i) <= level[x]) {
                x = ancs[x][i];
            }
        }
        if (x == y)
            return x;
        for (int i = l; i >= 0; i--) {
            if (ancs[x][i] != ancs[y][i]) {
                x = ancs[x][i];
                y = ancs[y][i];
            }
        }
        return ancs[x][0];
    };
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << level[x] + level[y] - 2 * level[lca(x, y)] << endl;
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
    //cin >> t;
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