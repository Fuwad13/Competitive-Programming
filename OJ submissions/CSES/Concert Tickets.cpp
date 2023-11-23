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
void solve() {
  int n, m;
  cin >> n >> m;
  multiset<int> ms;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ms.insert(x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (ms.size() == 0) {
      cout << -1 << endl;
      continue;
    }
    auto it = ms.upper_bound(x);
    if (it == ms.begin()) {
      cout << -1 << endl;
    }
    else {
      it--;
      cout << *it << endl;
      ms.erase(it);
    }
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