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
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = 0;
    map<int, int> freq;
    int cnt = 0;
    for (int l = 0, r = 0; r < n; r++) {
        freq[v[r]]++;
        if (freq[v[r]] == 1)
            cnt++;
        while (cnt > k) {
            freq[v[l]]--;
            if (freq[v[l]] == 0)
                cnt--;
            l++;
        }
        ans += r - l + 1;
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