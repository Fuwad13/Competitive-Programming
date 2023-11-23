#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 5005;
ll dp[N][N], a[N];
int n;
ll sum = 0;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = a[i];
            }
            else {
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
            }
        }
    }
    cout << (dp[0][n - 1] + sum) / 2 << endl;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}