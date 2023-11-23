#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 105;
int n;
bitset<100001> dp;
void solve() {
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp |= dp << x;
    }
    cout << dp.count() - 1 << endl;
    for (int i = 1; i <= 100000; i++) {
        if (dp[i])
            cout << i << " ";
    }
    cout << endl;
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