#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve() {
// solution for each test case here
  int n;
  cin >> n;
  vector<int> v(n);
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mx = max(mx, v[i]);
  }
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] < v[i - 1]) {
      ans += v[i - 1] - v[i];
      v[i] = v[i - 1];
    }
  }
  cout << ans << endl;
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
}