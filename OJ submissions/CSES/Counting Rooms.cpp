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
int n, m;
int arr[1010][1010];
bool vis[1010][1010];
void dfs(int r, int c) {
  if (r == n or c == m or r < 0 or c < 0)
    return;
  if (arr[r][c] == 0 or vis[r][c])
    return;
  vis[r][c] = 1;
  dfs(r + 1, c);
  dfs(r - 1, c);
  dfs(r, c + 1);
  dfs(r, c - 1);
}
void solve() {
  cin >> n >> m;
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch;
      if (ch == '#')
        arr[i][j] = 0;
      else
        arr[i][j] = 1;
    }
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 1 and !vis[i][j]) {
        cc++;
        dfs(i, j);
      }
    }
  }
  cout << cc << endl;
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