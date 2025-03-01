#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    map<pair<int, int>, int> mp;
    int itr = 0;
    for (auto &x : v) {
        cin >> x.first >> x.second;
        mp[x] = itr++;
    }
    sort(all(v), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    vector<bool> ans1(n), ans2(n);
    // vector<int> f(n), s(n);
    // for(int i= 0; i < n; i++){
    //     f[i]=v[i].first, s[i]=v[i].second;
    // }
    int mxR = 0;
    for (int i = 0; i < n; i++) {
        if (mxR >= v[i].second)
            ans2[mp[v[i]]] = 1;
        mxR = max(mxR, v[i].second);
    }
    int mnR = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (mnR <= v[i].second)
            ans1[mp[v[i]]] = 1;
        mnR = min(mnR, v[i].second);
    }
    for (auto x : ans1)
        cout << (x ? 1 : 0) << " ";
    cout << "\n";
    for (auto x : ans2)
        cout << (x ? 1 : 0) << ' ';
    cout << '\n';
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