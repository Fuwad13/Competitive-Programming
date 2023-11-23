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
const int N = 1e5 + 10;
void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << arr[b] - arr[a - 1] << endl;
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