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
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
const ll oo = 1e17;
const int mod = 1e9 + 7;
const int N = 1e7;
using point = complex<ll>;
#define x() real()
#define y() imag()
void solve() {
    point pts[3];
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
    for (int i = 1; i < 3; i++) {
        pts[i] = pts[i] - pts[0];
    }
    // ll cross_product = pts[2].x()*pts[1].y() - pts[1].x()*pts[2].y();
    // (conj(a) * b).y ---> cross product of a, b
    ll cross_product = (conj(pts[2]) * pts[1]).y();
    if (cross_product < 0) {
        cout << "LEFT" << endl;
    }
    else if (cross_product > 0) {
        cout << "RIGHT" << endl;
    }
    else {
        cout << "TOUCH" << endl;
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
    cin >> t;
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