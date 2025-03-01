#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
vector<vector<int>> adj;
int n;
vector<int> dp1, dp2;
void dfs(int v, int p) {
    for (auto c : adj[v]) {
        if (c ^ p) {
            dfs(c, v);
            dp2[v] += max(dp1[c], dp2[c]);
        }
    }
    for (auto c : adj[v]) {
        if (c ^ p)
            dp1[v] = max(dp1[v], 1 + dp2[c] + dp2[v] - max(dp1[c], dp2[c]));
    }
}
void solve() {
    cin >> n;
    adj.resize(n + 1);
    dp1.resize(n + 1), dp2.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << max(dp1[1], dp2[1]) << "\n";
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