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
const int N = 1010;
int grid[N][N];
int pre[N][N];
void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      if (ch == '*') {
        grid[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + grid[i][j];
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    int temp = pre[y2][x2] - pre[y2][x1 - 1] - pre[y1 - 1][x2] + pre[y1 - 1][x1 - 1];
    cout << temp << endl;
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