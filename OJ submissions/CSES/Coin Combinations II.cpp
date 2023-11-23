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
const int N = 1e6 + 10;
ll dp[N];
void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> coins(n);
  read(coins);
//sort(all(coins));
//memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int j = 0; j < n; j++) {
    for (ll i = 1; i <= x; i++) {
      if (i >= coins[j]) {
        dp[i] += dp[i - coins[j]];
        dp[i] %= mod;
      }
    }
  }
  cout << dp[x] << endl;
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