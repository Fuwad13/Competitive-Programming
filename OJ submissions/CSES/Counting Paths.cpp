#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int ancs[N][20];
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> tree[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    int lg = ceil(log2(n));
    vector<int> level(n + 1);
    function<void(int, int)> dfs = [&](int v, int p) -> void {
        ancs[v][0] = p;
        for (int i = 1; i <= lg; i++) {
            ancs[v][i] = ancs[ancs[v][i - 1]][i - 1];
        }
        for (auto c : tree[v]) {
            if (c != p) {
                level[c] = 1 + level[v];
                dfs(c, v);
            }
        }
    };
    auto lca = [&](int x, int y) -> int {
        if (level[x] < level[y])
            swap(x, y);
        for (int i = lg; i >= 0; i--) {
            if (level[y] + (1 << i) <= level[x])
                x = ancs[x][i];
        }
        if (x == y)
            return x;
        for (int i = lg; i >= 0; i--) {
            if (ancs[x][i] != ancs[y][i]) {
                x = ancs[x][i];
                y = ancs[y][i];
            }
        }
        return ancs[x][0];
    };
    dfs(1, 0);
    vector<ll> val(n + 1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        val[x]++;
        val[y]++;
        int l = lca(x, y);
        val[l]--;
        val[ancs[l][0]]--;
    }
    // write(val);
    function<void(int, int)> dfs2 = [&](int v, int p) -> void {
        for (auto c : tree[v]) {
            if (c != p) {
                dfs2(c, v);
                val[v] += val[c];
            }
        }
    };
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
}
//#define ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}