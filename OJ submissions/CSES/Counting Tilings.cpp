#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 10;
int n, m;
ll dp[1001][(1 << N) + 10];
bool is_compatible(int x, int y) {
    if ((x & y) != 0)
        return false;
    int X = ((~x) & (~y)) & ((1 << n) - 1);
    if (X % 3)
        return false;
    X = X / 3;
    if (X & (X << 1))
        return false;
    return true;
}
void solve() {
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int from = 0; from < (1 << n); from++) {
            if (dp[i][from] == 0)
                continue;
            for (int to = 0; to < (1 << n); to++) {
                if (is_compatible(from, to)) {
                    dp[i + 1][to] += dp[i][from];
                    dp[i + 1][to] %= mod;
                }
            }
        }
    }
    cout << dp[m][0] << endl;
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