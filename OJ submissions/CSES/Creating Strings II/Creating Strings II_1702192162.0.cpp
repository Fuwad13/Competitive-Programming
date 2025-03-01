#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 1e6;
ll binexp(ll base, ll exp, ll M) {
    if (exp == 0)
        return 1;
    ll ret = binexp(base, exp / 2, M);
    ret = ((ret % M) * (ret % M)) % M;
    if (exp & 1)
        return ((ret % M) * (base % M)) % M;
    return ret;
}
ll fac[N + 5];
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }
    fac[0] = 1;
    for (ll i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    ll ans = fac[n];
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1)
            ans = (ans * binexp(fac[freq[i]], mod - 2, mod)) % mod;
    }
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