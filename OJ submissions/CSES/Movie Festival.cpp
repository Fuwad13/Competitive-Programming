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
bool by(pair<int, int> a, pair<int, int> b) {
  if (a.second < b.second)
    return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  pair<int, int> events[n];
  for (int i = 0; i < n; i++)
    cin >> events[i].first >> events[i].second;
  sort(events, events + n, by);
  int cur = -1;
  int ans = 0;
// for(auto& a : events)
//  cout << a.first << " " << a.second << endl;
// cout << endl;
  for (int i = 0; i < n; i++) {
    if (events[i].first >= cur) {
      ans++;
      cur = events[i].second;
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
  return 0;
}