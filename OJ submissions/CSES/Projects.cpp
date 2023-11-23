#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5 + 5;
int n, a[N], b[N], p[N], coords;
ll dp[2 * N];
map<int, int> compress;
vector<vector<pair<int, int>>> projects;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }
    for (auto &[x, y] : compress)
        y = coords++;
    projects.resize(coords);
    for (int i = 0; i < n; i++) {
        projects[compress[b[i]]].push_back({compress[a[i]], p[i]});
    }
    for (int i = 1; i < coords; i++) {
        dp[i] = dp[i - 1];
        for (auto [x, y] : projects[i]) {
            dp[i] = max(dp[i], y + dp[x]);
        }
    }
    cout << dp[coords - 1] << endl;
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