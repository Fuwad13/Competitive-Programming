#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
int n, m;
vector<int> adj[N + 1];
bitset<N + 1> vis;
vector<int> dp(N + 1);
vector<int> to(N + 1);
void dfs(int v) {
    vis[v] = 1;
    if (v == n) {
        dp[v] = 1;
        return;
    }
    for (auto c : adj[v]) {
        if (!vis[c]) {
            dfs(c);
        }
        if (dp[c] and dp[c] + 1 > dp[v]) {
            dp[v] = dp[c] + 1;
            to[v] = c;
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    dfs(1);
    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << dp[1] << "\n";
    int now = 1;
    while (now != n) {
        cout << now << " ";
        now = to[now];
    }
    cout << n << "\n";
}
signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: "
         << std::chrono::duration_cast<std::chrono::duration<double>>(end -
                                                                      begin)
                .count()
         << " seconds" << endl;
    return 0;
}