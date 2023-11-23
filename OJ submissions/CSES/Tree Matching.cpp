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
const int N = 2e5 + 5;
int n;
vector<int> tree[N];
vector<int> a;
int cnt = 0;
void dfs(int node, int par) {
    for (auto child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
    if (tree[node].size() == 0 and node != 1) {
        if (a[par] == 0) {
            cnt++;
            //cout << node << " " << par << endl;
            a[node]++;
            a[par]++;
        }
    }
    else {
        if (a[node] == 0 and a[par] == 0 and par != 0) {
            cnt++;
            //cout << node << " " << par << endl;
            a[node]++;
            a[par]++;
        }
    }
}
void solve() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(1, 0);
    cout << cnt << endl;
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