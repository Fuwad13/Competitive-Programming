#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int dp[N];
void prec() {
    for (int i = 1; i < 10; i++)
        dp[i] = 1;
    for (int i = 10; i < N; i++) {
        dp[i] = N;
        string s = to_string(i);
        for (auto x : s) {
            dp[i] = min(dp[i], 1 + dp[i - (x - '0')]);
        }
    }
}
void solve() {
    int n;
    scanf("%d", &n);
    cout << dp[n] << endl;
}
int32_t main() {
    prec();
    int t{1};
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}