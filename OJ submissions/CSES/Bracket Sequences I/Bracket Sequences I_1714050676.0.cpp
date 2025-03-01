#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
ll binexp(ll base, ll exp, ll M) {
    if (exp == 0)
        return 1;
    ll ret = binexp(base, exp / 2, M);
    ret = ((ret % M) * (ret % M)) % M;
    if (exp & 1)
        return ((ret % M) * (base % M)) % M;
    return ret;
}
void solve() {
    ll n;
    cin >> n;
    if (n & 1) {
        cout << 0 << "\n";
        return;
    }
    n /= 2;
    // nth Catalan Number -> number of valid bracket sequence with n opening and
    // n closing brackets
    vector<ll> fac(2 * n + 1);
    fac[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    ll ans = binexp((1 + n) % mod, mod - 2, mod);
    ans = (ans * (((fac[2 * n] * binexp(fac[n], mod - 2, mod) % mod) *
                   binexp(fac[n], mod - 2, mod)) %
                  mod)) %
          mod;
    cout << ans << "\n";
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