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
const int N = 1e7;
void solve() {
    int n;
    cin >> n;
    vector<int> tree[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    vector<int> s_size(n + 1);
    function<void(int, int)> dfs = [&](int node, int par) {
        s_size[node] = 1;
        for (auto child : tree[node]) {
            if (child != par) {
                dfs(child, node);
                s_size[node] += s_size[child];
            }
        }
    };
    dfs(1, 0);
    function<int(int, int)> get_centroid = [&](int node, int par) {
        for (auto child : tree[node]) {
            if (child != par) {
                if (s_size[child] * 2 > n)
                    return get_centroid(child, node);
            }
        }
        return node;
    };
    cout << get_centroid(1, 0) << endl;
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