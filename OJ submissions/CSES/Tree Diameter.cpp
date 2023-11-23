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
int mx = 0, mxVertex = 0;
int dist[N];
void dfs(int node, int par) {
//dist[node] = 1+dist[par];
  if (dist[node] >= mx) {
    mx = dist[node];
    mxVertex = node;
  }
  for (auto child : tree[node]) {
    if (child == par)
      continue;
    dist[child] = 1 + dist[node];
    dfs(child, node);
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  mx = 0, mxVertex = 0;
  memset(dist, -1, sizeof(dist));
  dist[1] = 0;
  dfs(1, 0);
  mx = 0;
  memset(dist, -1, sizeof(dist));
  dist[mxVertex] = 0;
  dfs(mxVertex, 0);
  cout << mx << endl;
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