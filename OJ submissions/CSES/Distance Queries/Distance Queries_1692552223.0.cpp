#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v)                                                                \
    for (auto &_ : v)                                                          \
    cin >> _
#define write(v)                                                               \
    for (auto &_ : v)                                                          \
        cout << _ << ' ';                                                      \
    cout << '\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, q;
vector<int> tree[N];
int ancs[N][20];
vector<int> tin, tout;
int timer{};
int L;
vector<int> dist;
void dfs(int node, int par) {
    tin[node] = ++timer;
    ancs[node][0] = par;
    for (int i = 1; i <= L; i++) {
        ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
    }
    for (auto child : tree[node]) {
        if (child != par) {
            dist[child] = 1 + dist[node];
            dfs(child, node);
        }
    }
    tout[node] = ++timer;
}
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}
int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L; i >= 0; i--) {
        if (!is_ancestor(ancs[u][i], v))
            u = ancs[u][i];
    }
    return ancs[u][0];
}
void solve() {
    cin >> n >> q;
    L = ceil(log2(n));
    dist.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs(1, 1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << endl;
    }
}
#define ONLINE_JUDGE
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