#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 1e7;
int n, q;
ll stree[2 * N];
void build() {
    for (int i = n - 1; i > 0; i--) {
        stree[i] = min(stree[i << 1] , stree[i << 1 | 1]);
    }
}
void update(int ind, int val) {
    for (stree[ind += n] = val; ind > 1; ind >>= 1)
        stree[ind >> 1] = min(stree[ind] , stree[ind ^ 1]);
}
ll query(int l, int r) { // range sum [l, r)
    ll res = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = min(stree[l++], res);
        if (r & 1)
            res = min(res, stree[--r]);
    }
    return res;
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> stree[n + i];
    }
    build();
    while (q--) {
        int tp, x, y;
        cin >> tp >> x >> y;
        if (tp & 1) {
            update(x - 1, y);
        }
        else {
            cout << query(x - 1, y) << endl;
        }
    }
}
//#define ONLINE_JUDGE
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