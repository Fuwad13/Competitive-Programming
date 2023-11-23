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
const int N = 2e5 + 69;
int n, q;
ll arr[N];
ll bit[N];
void build() {
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1] + arr[i];
        if (i & 1) {
            bit[i] = arr[i];
        }
        else {
            int x = i & (-i);
            bit[i] = pre[i] - pre[i - x];
        }
    }
}
void update(int ind, ll val) {
    while (ind <= n) {
        bit[ind] += val;
        ind += ind & -ind;
    }
}
ll query(int r) {
    ll res = 0;
    while (r >= 1) {
        res += bit[r];
        r -= r & -r;
    }
    return res;
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build();
    while (q--) {
        ll tp, x, y;
        cin >> tp >> x >> y;
        if (tp & 1) {
            update(x, y - arr[x]);
            arr[x] = y;
        }
        else {
            cout << query(y) - query(x - 1) << endl;
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