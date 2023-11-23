#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve() {
// solution for each test case here
  string s;
  cin >> s;
  int ans = INT_MIN;
  for (int i = 0; i < s.size();) {
    char cur = s[i];
    int temp = 1;
    for (int j = i + 1; j < s.size(); j++) {
      if (s[j] == cur)
        temp++;
      else {
        break;
      }
    }
    i += temp;
    ans = max(ans, temp);
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