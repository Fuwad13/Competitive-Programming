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
const ll mod = 1e9 + 7;
const int N = 1e7;
ll binexp(ll base, ll exp, ll M) {
    if (exp == 0)
        return 1;
    ll ret = binexp(base, exp / 2, M);
    ret = ((ret % M) * (ret % M)) % M;
    if (exp & 1)
        return ((ret % M) * (base % M)) % M;
    return ret;
}
void solve() {
    int n;
    cin >> n;
    int x = ((n * (n + 1)) >> 1);
    vector<ll> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = x; j - i >= 0; j--) {
            dp[j] += dp[j - i];
            dp[j] %= mod;
        }
    }
    if (x % 2)
        cout << 0 << endl;
    else
        cout << (dp[x / 2] * (binexp(2, mod - 2, mod))) % mod << endl;
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
    //cin >> t;
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