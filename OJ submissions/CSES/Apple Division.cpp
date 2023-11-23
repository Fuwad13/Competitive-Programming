#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int n;
vector<int> v;
ll ans(int i , ll sum1, ll sum2) {
  if (i == n)
    return abs(sum1 - sum2);
  return min(
           ans(i + 1, sum1 + v[i], sum2), ans(i + 1, sum1, sum2 + v[i])
         );
}
void solve() {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << ans(0, 0, 0) << endl;
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