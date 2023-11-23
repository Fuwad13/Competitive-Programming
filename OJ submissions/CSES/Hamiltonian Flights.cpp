#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
ll dp[21][(1 << 20)];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    // dp(S, i) -> #ways to visit S ending at i
    // vector<vector<int>> dp(n+1, vector<int>(1<<n));
    dp[1][1] = 1;
    for (int mask = 1; mask < 1 << n - 1; mask++) {
        if (!(mask & 1)) continue;
        for (int i = 0; i < n; i++) {
            int v = i + 1;
            if (!(mask >> i & 1)) continue;
            if (v == n) continue;
            for (auto x : adj[v]) {
                if (mask & (1 << (x - 1)))
                    continue;
                int y = (mask | (1 << (x - 1)));
                dp[x][y] += dp[v][mask];
                dp[x][y] %= mod;
            }
        }
    }
    cout << dp[n][(1 << n) - 1];
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}