#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
template<class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n"
#define pb push_back
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9 + 7;
const int N = 1e7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> stree(4 * n), arr(n);
    auto build = [&](auto build, int node, int b, int e) -> void {
        if (b == e) {
            stree[node] = arr[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(build, node * 2, b, mid);
        build(build, node * 2 + 1, mid + 1, e);
        // stree[node] = stree[node*2]+stree[node*2+1];
    };
    auto update = [&](auto update, int node, int b, int e, int l, int r, int val) -> void {
        if (l > e or r < b)
            return;
        if (b >= l and e <= r) {
            stree[node] += val;
            return;
        }
        int mid = (b + e) >> 1;
        update(update, 2 * node, b, mid, l, r, val);
        update(update, 2 * node + 1, mid + 1, e, l, r, val);
        // stree[node] = stree[2*node]+stree[2*node+1];
    };
    auto query = [&](auto query, int node, int b, int e, int ind) -> ll {
        if (ind > e or ind < b)
            return 0LL;
        if (ind <= b and ind >= e)
            return stree[node];
        int mid = (b + e) >> 1;
        return stree[node] + query(query, 2 * node, b, mid, ind) + query(query, 2 * node + 1, mid + 1, e, ind);
    };
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(build, 1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int tp;
        cin >> tp;
        if (tp & 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            update(update, 1, 0, n - 1, l, r, v);
        }
        else {
            int x;
            cin >> x;
            x--;
            cout << query(query, 1, 0, n - 1, x) << endl;
        }
    }
}
#define ONLINE_JUDGE
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " <<
         std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count()
         << " seconds" << endl;
    return 0;
}