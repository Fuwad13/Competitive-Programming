#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2500;
struct Edge {
    int a, b;
    ll cost;
};
vector<int> adj[N + 1];
bitset<N + 1> vis;
vector<int> top_sort;
void ts_dfs(int v) {
    vis[v] = 1;
    for (auto c : adj[v]) {
        if (!vis[c])
            ts_dfs(c);
    }
    top_sort.push_back(v);
}
void dfs(int v) {
    vis[v] = 1;
    for (auto c : adj[v]) {
        if (!vis[c])
            dfs(c);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> v(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        v[i] = Edge{a, b, c};
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            ts_dfs(i);
    reverse(all(top_sort));
    vis.reset();
    // vector<int> heads;
    vector<ll> dist(n + 1, oo);
    for (int i = 0; i < (int)top_sort.size(); i++) {
        if (!vis[top_sort[i]]) {
            // heads.push_back(top_sort[i]);
            dist[top_sort[i]] = 0;
            dfs(top_sort[i]);
        }
    }
    // Bellman Ford
    vector<int> p(n + 1, -1);
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto [a, b, c] : v) {
            if (dist[a] < oo) {
                if (dist[a] + c < dist[b]) {
                    dist[b] = max(-oo, dist[a] + c);
                    p[b] = a;
                    x = b;
                }
            }
        }
    }
    if (x == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        x = p[x];
    vector<int> ans;
    for (int cur = x;; cur = p[cur]) {
        ans.push_back(cur);
        if (cur == x and ans.size() > 1)
            break;
    }
    reverse(all(ans));
    for (auto a : ans)
        cout << a << " ";
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