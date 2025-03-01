#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e6;
ll fac[N + 5], fac_inv[N + 5];
ll binexp(ll base, ll exp, ll M) {
    if (exp == 0)
        return 1;
    ll ret = binexp(base, exp / 2, M);
    ret = ((ret % M) * (ret % M)) % M;
    if (exp & 1)
        return ((ret % M) * (base % M)) % M;
    return ret;
}
void prec() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    fac_inv[N] = binexp(fac[N], mod - 2, mod);
    for (int i = N - 1; i >= 0; i--) {
        fac_inv[i] = (fac_inv[i + 1] * (i + 1)) % mod;
    }
}
ll inv(ll n) { return binexp(n, mod - 2, mod); }
ll nCr(ll n, ll r) {
    // return (((fac[n]*(inv(fac[r])))%mod)*inv(fac[n-r]))%mod;
    return (((fac[n] * fac_inv[r]) % mod) * fac_inv[n - r]) % mod;
}
void solve() {
    prec();
    ll n, m;
    cin >> n >> m;
    cout << nCr(n + m - 1, n - 1) << "\n";
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