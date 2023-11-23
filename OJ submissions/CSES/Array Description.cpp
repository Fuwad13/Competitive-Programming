#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    if (a.front() == 0) {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][a.front()] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (auto k : {j - 1, j, j + 1}) {
                    if (k >= 1 and k <= m) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        else {
            for (auto j : {a[i] - 1, a[i], a[i] + 1}) {
                if (j >= 1 and j <= m) {
                    dp[i][a[i]] += dp[i - 1][j];
                    dp[i][a[i]] %= mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= m; j++) {
        ans += dp[n - 1][j];
    }
    cout << ans % mod << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}