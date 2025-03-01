#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define read(v)                                                                \
    for (auto &_ : v)                                                          \
    cin >> _
#define write(v)                                                               \
    for (auto &_ : v)                                                          \
        cout << _ << ' ';                                                      \
    cout << '\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const int mod = 1e9 + 7;
const int N = 1e7;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pre[i] = arr[i] ^ (i ? pre[i - 1] : 0);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << (pre[y] ^ (x ? pre[x - 1] : 0)) << endl;
    }
}
// #define ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}