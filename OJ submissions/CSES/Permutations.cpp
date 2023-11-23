#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve() {
// solution for each test case here
  int n;
  cin >> n;
  if (n == 2 || n == 3)
    cout << "NO SOLUTION\n";
  else if (n == 4)
    cout << "2 4 1 3\n";
  else {
    if (n & 1) {
      for (int i = n - 1; i >= 2; i -= 2)
        cout << i << " ";
      cout << n <<  " ";
      for (int i = 1; i <= n - 2; i += 2)
        cout << i << " ";
      cout << endl;
    }
    else {
      for (int i = n; i >= 2; i -= 2)
        cout << i << " ";
      for (int i = n - 1; i >= 1; i -= 2)
        cout << i << " ";
      cout << endl;
    }
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