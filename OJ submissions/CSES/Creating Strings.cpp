#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve() {
// solution for each test case here
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  set<string> st;
  st.insert(s);
  while (next_permutation(s.begin(), s.end())) {
    st.insert(s);
  }
  cout << st.size() << endl;
  auto it = st.begin();
  for (; it != st.end(); it++) {
    cout << *it << endl;
  }
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