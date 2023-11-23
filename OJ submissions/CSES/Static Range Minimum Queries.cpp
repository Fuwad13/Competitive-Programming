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
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9 + 7;
const int N = 1e7;
const int LG = 25; // floor(log2(N)) + 1]
int st[LG][N], lgs[N + 1];
void sparse_table(vector<int>& v, int n) {
    for (int i = 0; i < n; i++)
        st[0][i] = v[i];
    lgs[1] = 0;
    for (int i = 2; i <= n; i++)
        lgs[i] = lgs[i / 2] + 1;
    for (int i = 1; i < LG; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}
int rmq(int l, int r) {
    int lg = lgs[r - l + 1];
    return min(st[lg][l], st[lg][r - (1 << lg) + 1]);
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    read(v);
    sparse_table(v, n);
    while (q--) {
        int l, r ;
        cin >> l >> r;
        cout << rmq(l - 1, r - 1) << endl;
    }
}
//#define ONLINE_JUDGE
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