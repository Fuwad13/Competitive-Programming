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
void solve() {
    ll n, S;
    cin >> n >> S;
    vector<ll> v(n);
    read(v);
    ll mid = n / 2;
    vector<ll> fh(v.begin(), v.begin() + mid), sh(v.begin() + mid, v.end());
    vector<ll> mp1, mp2;
    int n1 = mid, n2 = n - mid;
    for (int mask = 0; mask < (1 << n1); mask++) {
        ll temp = 0;
        for (int i = 0; i < n1; i++) {
            if ((mask >> i) & 1) {
                temp += fh[i];
            }
        }
        mp1.pb(temp);
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << n2); mask++) {
        ll temp = 0;
        for (int i = 0; i < n2; i++) {
            if ((mask >> i) & 1) {
                temp += sh[i];
            }
        }
        mp2.pb(temp);
    }
    sort(all(mp1));
    sort(all(mp2));
    for (auto x : mp1) {
        if (x > S)
            break;
        auto ub = upper_bound(all(mp2), S - x) - mp2.begin();
        auto lb = lower_bound(all(mp2), S - x) - mp2.begin();
        ans += ub - lb;
    }
    cout << ans << endl;
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