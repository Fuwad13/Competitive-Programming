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
int ans[N];
void dfs(int node, int par) {
    ans[node] = 1;
    for (auto child : tree[node]) {
        if (child != par) {
            dfs(child, node);
            ans[node] += ans[child];
        }
    }
}
void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        tree[x].pb(i);
        tree[i].pb(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << " ";
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