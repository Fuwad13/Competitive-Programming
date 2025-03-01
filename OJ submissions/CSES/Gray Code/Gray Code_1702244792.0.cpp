#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
vector<string> ans(int n) {
    vector<string> ret;
    if (n == 1) {
        ret = {"0", "1"};
        return ret;
    }
    vector<string> prev = ans(n - 1);
    for (int i = 0; i < (int)prev.size(); i++) {
        string s = "0";
        s += prev[i];
        ret.push_back(s);
    }
    for (int i = (int)prev.size() - 1; i >= 0; i--) {
        string s = "1";
        s += prev[i];
        ret.push_back(s);
    }
    return ret;
}
void solve() {
    int n;
    cin >> n;
    vector<string> res = ans(n);
    for (auto x : res)
        cout << x << "\n";
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