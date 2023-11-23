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
  ll n;
  cin >> n;
  ll modinv2 = binexp(2, mod - 2, mod);
  ll total = 0;
  ll at = 1;
  while (at <= n) {
    ll amt = n / at; // number of times it contrib. to total sum;
    ll last_same = n / amt; // last div. with same times of appearance
    // for this range, find the sum of the div. values
    // using arithmatic progression series sum formula
    ll range = (last_same - at + 1) % mod;
    ll sum = ((((range % mod) * ((at % mod + last_same % mod) % mod)) % mod) * modinv2) % mod;
    ll temp = ((sum % mod) * (amt % mod)) % mod;
    total = (total % mod + temp % mod) % mod;
    at = last_same + 1;
  }
  cout << total << endl;
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