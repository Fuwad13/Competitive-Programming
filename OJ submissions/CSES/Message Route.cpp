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
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> graph[n + 1];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  vector<int> dist(n + 1, -1);
  queue<int> q;
  q.push(1);
  vector<int> pre(n + 1, -1);
  dist[1] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto adj : graph[cur]) {
      if (dist[adj] == -1) {
        dist[adj] = 1 + dist[cur];
        pre[adj] = cur;
        q.push(adj);
      }
    }
  }
  if (dist[n] == -1)
    cout << "IMPOSSIBLE\n";
  else {
    cout << dist[n] + 1 << endl;
    vector<int> ans;
    int i = n;
    ans.pb(n);
    while (pre[i] != -1) {
      ans.pb(pre[i]);
      i = pre[i];
    }
    reverse(all(ans));
    write(ans);
  }
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