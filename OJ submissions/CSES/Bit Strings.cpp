#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod = 1e9 + 7;
ll ans(ll n) {
  if (n == 0)
    return 1;
  ll res = ans(n / 2);
  if (n & 1) {
    res = ((res % mod) * (res % mod)) % mod;
    res = ((res % mod) * 2) % mod;
  }
  else
    res = ((res % mod) * (res % mod)) % mod;
  return res;
}
void solve() {
// solution for each test case here
  ll n;
  cin >> n;
  cout << ans(n) << endl;
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