#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
template <class T> struct segment_tree {
    int n;
    vector<T> stree;
    function<T(const T &, const T &)> merge;
    T identity = T();
    segment_tree(int n, function<T(const T &, const T &)> merge, T identity)
        : n(n), merge(merge), identity(identity) {
        stree.resize(n << 1);
    }
    void build() {
        for (int i = n - 1; i > 0; i--)
            stree[i] = merge(stree[i << 1], stree[i << 1 | 1]);
    }
    segment_tree(const vector<T> &arr, function<T(const T &, const T &)> merge,
                 T identity)
        : n(arr.size()), merge(merge), identity(identity) {
        stree.resize(n << 1);
        for (int i = 0; i < n; i++)
            stree[i + n] = arr[i];
        build();
    }
    void set(int ind, T val) {
        ind += n;
        for (stree[ind] = val; ind > 1; ind >>= 1) {
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    void update(int ind, T val) {
        ind += n;
        for (stree[ind] = merge(val, stree[ind]); ind > 1; ind >>= 1) {
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    T query(int l, int r) { // closed interval [l,r]
        T ansl = identity;
        T ansr = identity;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ansl = merge(ansl, stree[l++]);
            }
            if (r & 1) {
                ansr = merge(stree[--r], ansr);
            }
        }
        return merge(ansl, ansr);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<pair<int, int>>> queries(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[r].emplace_back(l, i);
    }
    map<int, int> last;
    segment_tree<int> st(n + 1, [](int a, int b) { return a + b; }, 0);
    vector<int> ans(q);
    for (int i = 1; i <= n; i++) {
        st.update(i, 1);
        if (last.count(v[i]))
            st.update(last[v[i]], -1);
        for (auto [x, y] : queries[i]) {
            ans[y] = st.query(x, i);
        }
        last[v[i]] = i;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
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