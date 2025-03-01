#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define int long long
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
// by sqrt decomposition
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    debug(v);
    int BLOCK_SZ = ceil(sqrt(n));
    vector<int> blocks(BLOCK_SZ);
    for (int i = 0; i < n; i++) {
        blocks[i / BLOCK_SZ] += v[i];
    }
    debug(BLOCK_SZ, blocks);
    while (q--) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp & 1) {
            l--;
            blocks[l / BLOCK_SZ] -= v[l];
            v[l] = r;
            blocks[l / BLOCK_SZ] += v[l];
        } else {
            l--, r--;
            int ub = r / BLOCK_SZ;
            debug(ub);
            int ans = 0;
            for (int i = 0; i < ub; i++)
                ans += blocks[i];
            debug(ans);
            for (int i = ub * BLOCK_SZ; i <= r; i++)
                ans += v[i];
            debug(ans);
            ub = l / BLOCK_SZ;
            debug(ub);
            for (int i = 0; i < ub; i++)
                ans -= blocks[i];
            debug(ans);
            for (int i = ub * BLOCK_SZ; i < l; i++)
                ans -= v[i];
            debug(ans);
            cout << ans << "\n";
        }
    }
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