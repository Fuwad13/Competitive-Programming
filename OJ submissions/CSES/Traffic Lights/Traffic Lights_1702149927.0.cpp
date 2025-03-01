#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using iset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
void solve() {
    int x, n;
    cin >> x >> n;
    iset<int> ist;
    ist.insert(0);
    ist.insert(x);
    multiset<int> ms;
    ms.insert(x);
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        int pos = ist.order_of_key(y);
        int a, b;
        a = *ist.find_by_order(pos - 1);
        b = *ist.find_by_order(pos);
        assert(ms.find(b - a) != ms.end());
        ms.erase(ms.find(b - a));
        ms.insert(y - a), ms.insert(b - y), ist.insert(y);
        cout << *ms.rbegin() << " ";
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