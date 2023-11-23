#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 1e7;
void solve() {
   ll n, k;
   cin >> n >> k;
   vector<int> v(n);
   read(v);
   ll psum = 0;
   map<ll, int> cnt{{0, 1}};
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      psum += v[i];
      ans += cnt[psum - k];
      cnt[psum]++;
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
   // cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}