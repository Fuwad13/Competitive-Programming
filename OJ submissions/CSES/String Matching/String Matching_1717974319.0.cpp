#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e6 + 10;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
int p_function[N];
int KMP(string &s, int sz) {
    int cnt = 0, cur = 0;
    p_function[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        while (cur != 0 and s[cur] != s[i])
            cur = p_function[cur - 1];
        if (s[cur] == s[i])
            cur++;
        p_function[i] = cur;
        cnt += cur == sz;
    }
    return cnt;
}
void solve() {
    string t, p;
    cin >> t >> p;
    string s = p + "$" + t;
    cout << KMP(s, p.size()) << "\n";
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