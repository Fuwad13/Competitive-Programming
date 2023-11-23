#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n;
vector<int> tree[N];
ll subtree_size[N], ans[N];
void dfs1(int node, int par, ll depth) {
  ans[1] += depth;
  subtree_size[node] = 1;
  for (auto child : tree[node]) {
    if (child != par) {
      dfs1(child, node, depth + 1);
      subtree_size[node] += subtree_size[child];
    }
  }
}
void dfs2(int node, int par) {
  for (auto child : tree[node]) {
    if (child != par) {
      ans[child] = ans[node] + n - 2 * subtree_size[child];
      dfs2(child, node);
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  dfs1(1, 0, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
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