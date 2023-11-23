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
class HashedString {
private:
    // change M and B if you want
    static const long long M = 1e9 + 9;
    static const long long B = 9973;
    // pow[i] contains B^i % M
    static vector<long long> pow;
    // p_hash[i] is the hash of the first i characters of the given string
    vector<long long> p_hash;
public:
    HashedString(const string &s) : p_hash(s.size() + 1) {
        while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }
        p_hash[0] = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }
    long long getHash(int start, int end) {
        long long raw_val =
            (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
};
vector<long long> HashedString::pow = {1};
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    HashedString hs(s);
    for (int i = 1; i <= n; i++) {
        ll h = hs.getHash(0, i - 1);
        bool flag = true;
        int j = 0;
        for (; j + i <= n and flag; j += i) {
            ll temp = hs.getHash(j, j + i - 1);
            if (temp != h)
                flag = false;
        }
        if (j < n) {
            ll temp = n % i;
            ll h1 = hs.getHash(j, n - 1);
            ll h2 = hs.getHash(0, temp - 1);
            if (h1 != h2)
                flag = false;
        }
        if (flag)
            cout << i << " ";
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