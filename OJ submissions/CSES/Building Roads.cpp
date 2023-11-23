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
const int N = 1e7;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> lead;
int cc = 0; // connected components
int n, m;
void dfs(int city) {
  visited[city] = 1;
  for (auto adjcity : graph[city]) {
    if (!visited[adjcity]) {
      dfs(adjcity);
    }
  }
}
void calculate_cc() {
  for (int i = 1 ; i <= n; i++) {
    if (!visited[i]) {
      cc++;
      lead.pb(i);
      dfs(i);
    }
  }
}
void solve() {
  cin >> n >> m;
  graph.resize(n + 1);
  visited.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  calculate_cc();
  cout << cc - 1 << endl;
  int cur = lead[0];
  if (cc > 1) {
    for (int i = 1; i < lead.size(); i++) {
      cout << cur << " " << lead[i] << endl;
      cur = lead[i];
    }
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
//cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}