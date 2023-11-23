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
int dp[1010][N];
int n, x;
// vector<int> price, pages;
int price[1010], pages[1010];
int page_count(int cur, int prc) {
  if (cur == n + 1 or prc <= 0)
    return 0;
  int &ans = dp[prc][cur];
  if (ans != -1)
    return ans;
  ans = 0;
  ans = page_count(cur + 1, prc);
  if (price[cur] <= prc) {
    ans = max(ans, pages[cur] + page_count(cur + 1, prc - price[cur]));
  }
  return ans;
}
void solve() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++)
    cin >> price[i];
  for (int i = 1; i <= n; i++)
    cin >> pages[i];
//memset(dp, -1, sizeof(dp));
//cout << page_count(1, x) << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      dp[i][j] = dp[i - 1][j];
      if (price[i] <= j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
      }
    }
  }
  cout << dp[n][x] << endl;
}
// #define ONLINE_JUDGE
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