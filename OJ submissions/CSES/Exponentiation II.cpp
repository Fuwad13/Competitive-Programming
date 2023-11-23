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
ll binexp(ll base, ll exp, ll M) {
  if (exp == 0)
    return 1;
  ll ret = binexp(base, exp / 2, M);
  ret = ((ret % M) * (ret % M)) % M;
  if (exp & 1)
    return ((ret % M) * (base % M)) % M;
  return ret;
}
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll temp = binexp(b, c, mod - 1);
  cout << binexp(a, temp, mod) << endl;
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
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}