#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
int n, m;
vector<int> adj[N + 10];
vector<int> par(N + 10, -1);
vector<bool> vis(N + 10);
int head;
bool printed = false;
void dfs(int v) {
    vis[v] = 1;
    for (auto c : adj[v]) {
        if (c == par[v])
            continue;
        if (vis[c]) {
            if (printed)
                continue;
            // debug("at", v, par[v]);
            vector<int> ans;
            // cout << c <<" ";
            ans.push_back(c);
            int temp = v;
            while (temp != c) {
                // cout << temp << " ";
                ans.push_back(temp);
                temp = par[temp];
            }
            // cout << c << "\n";
            ans.push_back(c);
            cout << ans.size() << "\n";
            for (auto x : ans)
                cout << x << " ";
            cout << "\n";
            printed = true;
        } else {
            par[c] = v;
            dfs(c);
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // debug(adj[1]);
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i);
    }
    if (!printed) {
        cout << "IMPOSSIBLE\n";
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