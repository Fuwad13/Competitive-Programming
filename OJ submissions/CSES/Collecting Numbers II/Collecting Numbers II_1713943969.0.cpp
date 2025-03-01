#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), ind(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        ind[v[i]] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans += (ind[i] < ind[i - 1]);
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if (v[l] - 1 >= 1)
            st.insert({v[l] - 1, v[l]});
        if (v[l] + 1 <= n)
            st.insert({v[l], v[l] + 1});
        if (v[r] - 1 >= 1)
            st.insert({v[r] - 1, v[r]});
        if (v[r] + 1 <= n)
            st.insert({v[r], v[r] + 1});
        // undo
        for (auto [x, y] : st) {
            ans -= ind[y] < ind[x];
        }
        swap(v[l], v[r]);
        ind[v[l]] = l;
        ind[v[r]] = r;
        for (auto [x, y] : st) {
            ans += ind[y] < ind[x];
        }
        st.clear();
        cout << ans << "\n";
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