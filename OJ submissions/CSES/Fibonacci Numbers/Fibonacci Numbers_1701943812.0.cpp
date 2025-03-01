#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
template <int SZ = 2, ll M = (ll)1e9 + 7> struct matrix {
    array<array<ll, SZ>, SZ> mat;
    matrix() {
        for (int i = 0; i < SZ; i++)
            for (int j = 0; j < SZ; j++)
                mat[i][j] = 0;
    }
    matrix(const vector<vector<ll>> &v) {
        assert((int)v.size() == SZ);
        assert((int)v[0].size() == SZ);
        for (int i = 0; i < SZ; i++)
            for (int j = 0; j < SZ; j++)
                mat[i][j] = v[i][j];
    }
    static matrix identity() {
        auto ret = vector(SZ, vector<ll>(SZ));
        for (int i = 0; i < SZ; i++)
            ret[i][i] = 1;
        return matrix(ret);
    }
    matrix operator*(const matrix &a) {
        matrix prod;
        for (int i = 0; i < SZ; i++) {
            for (int j = 0; j < SZ; j++) {
                for (int k = 0; k < SZ; k++) {
                    prod.mat[i][k] =
                        (prod.mat[i][k] + mat[i][j] * a.mat[j][k]) % M;
                }
            }
        }
        return prod;
    }
};
static matrix<> iden = matrix<>::identity();
matrix<> fib = matrix<>({{0, 1}, {1, 1}});
matrix<> binexp(matrix<> base, ll exp) {
    matrix<> ret = iden;
    while (exp) {
        if (exp & 1)
            ret = ret * base;
        base = base * base;
        exp >>= 1;
    }
    return ret;
}
void solve() {
    ll n;
    cin >> n;
    matrix x = binexp(fib, n);
    cout << x.mat[0][1] << endl;
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