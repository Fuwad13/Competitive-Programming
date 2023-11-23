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
int n;
vector<int> tree[N];
int mxdist{};
int farthestNode{};
vector<int> dist, dist2;
void dfs(int node, int par, vector<int>& dis) {
    for (auto child : tree[node]) {
        if (child != par) {
            dis[child] = 1 + dis[node];
            if (mxdist < dis[child]) {
                mxdist = dis[child];
                farthestNode = child;
            }
            dfs(child, node, dis);
        }
    }
}
void solve() {
    cin >> n;
    dist.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1, 0, dist);
    dist.assign(n + 1, 0);
    mxdist = 0;
    int temp = farthestNode;
    dfs(farthestNode, 0, dist);
    int temp2 = farthestNode;
    dist2.resize(n + 1);
    dfs(farthestNode, 0, dist2);
    for (int i = 1; i <= n; i++) {
        cout << max(dist[i], dist2[i]) << " ";
    }
    cout << endl;
}
// #define ONLINE_JUDGE
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