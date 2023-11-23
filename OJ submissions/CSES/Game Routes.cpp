#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> toposort;
    vector<bool> vis(n + 1);
    auto dfs = [&](auto dfs, int v) -> void {
        vis[v] = 1;
        for (auto c : adj[v]) {
            if (!vis[c])
                dfs(dfs, c);
        }
        toposort.push_back(v);
    };
    dfs(dfs, 1);
    vector<ll> dp(n + 2);
    dp[1] = 1;
    reverse(all(toposort));
    for (int i = 0; i < (int)toposort.size(); i++) {
        for (auto c : adj[toposort[i]]) {
            dp[c] += dp[toposort[i]];
            dp[c] %= mod;
        }
    }
    cout << dp[n] << endl;
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