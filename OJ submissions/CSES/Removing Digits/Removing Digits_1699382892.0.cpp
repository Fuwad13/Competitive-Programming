#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int dp[N + 20];
void prec() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= 9; j++) {
            if (to_string(i + j).find(to_string(j)) != string::npos)
                dp[i + j] = min(dp[i + j], 1 + dp[i]);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
// #define ONLINE_JUDGE
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    prec();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: "
         << std::chrono::duration_cast<std::chrono::duration<double>>(end -
                                                                      begin)
                .count()
         << " seconds" << endl;
    return 0;
}