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
struct HASH {
    size_t operator()(const pair<int, int> &x) const {
        return hash<long long>()(((long long)x.first) ^
                                 (((long long)x.second) << 32));
    }
};
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    // map<int, int> coord;
    unordered_map<pair<int, int>, int, HASH> mp;
    int itr = 0;
    for (auto &x : v) {
        cin >> x.first >> x.second;
        mp[x] = itr++;
        // coord[x.first], coord[x.second];
    }
    itr = 0;
    // for(auto &[x, y] : coord){
    //     y = itr++;
    // }
    sort(all(v), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    // segment_tree<int> st(coord.size()+1, [](int a, int b){return a+b;}, 0);
    // segment_tree<int> st2(coord.size()+1, [](int a, int b){return a+b;}, 0);
    iset<pair<int, int>> ist;
    vector<int> ans1(n), ans2(n);
    for (int i = 0; i < n; i++) {
        // ans2[mp[v[i]]] = st.query(coord[v[i].second], coord.size());
        int x = ist.order_of_key({v[i].second, 0});
        ans2[mp[v[i]]] = ist.size() - x;
        // st.update(coord[v[i].second],  1);
        ist.insert({v[i].second, itr++});
    }
    ist.clear();
    itr = 0;
    for (int i = n - 1; i >= 0; i--) {
        // ans1[mp[v[i]]] = st2.query(coord[v[i].first], coord[v[i].second]);
        int x = ist.order_of_key({v[i].second, INT_MAX});
        int y = ist.order_of_key({v[i].first + 1, 0});
        // cout << x << " " << y << endl;
        ans1[mp[v[i]]] = x - y;
        // st2.update(coord[v[i].second], 1);
        ist.insert({v[i].second, itr++});
    }
    for (auto x : ans1)
        cout << x << " ";
    cout << "\n";
    for (auto x : ans2)
        cout << x << ' ';
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