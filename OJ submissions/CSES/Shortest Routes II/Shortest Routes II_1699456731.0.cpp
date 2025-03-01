#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const int mod = 1e9 + 7; // 998244353;
const int N = 510;
const ll oo = 1e17;
int adj[N][N];
ll dist[N][N];
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        if (adj[x][y]) {
            adj[x][y] = adj[y][x] = min(adj[x][y], d);
            continue;
        }
        adj[x][y] = adj[y][x] = d;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (adj[i][j])
                dist[i][j] = adj[i][j];
            else
                dist[i][j] = oo;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (dist[x][y] == oo ? -1 : dist[x][y]) << endl;
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