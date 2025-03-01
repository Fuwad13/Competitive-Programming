#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll sum = 0;
    for (auto &x : v)
        cin >> x, sum += x;
    ll low = *max_element(all(v)), high = sum, ans = sum;
    auto check = [&](ll x) -> bool {
        ll cnt = 1, cur = 0;
        ll tmx = 0;
        for (int i = 0; i < n; i++) {
            if (cur + v[i] > x) {
                cnt++;
                tmx = max(tmx, cur);
                cur = v[i];
            } else {
                cur += v[i];
            }
        }
        // cout << x << "--> " << cnt << " " << tmx << endl;
        return tmx <= x and cnt <= k;
    };
    while (low <= high) {
        ll mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }
    cout << ans << endl;
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