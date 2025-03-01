#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
struct Matrix {
    array<array<ll, 2>, 2> m;
    Matrix(int a, int b, int c, int d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
    Matrix operator*(const Matrix &a) {
        Matrix prod(0, 0, 0, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    prod.m[i][k] = (prod.m[i][k] + m[i][j] * a.m[j][k]) % mod;
                }
            }
        }
        return prod;
    }
};
Matrix iden = Matrix(1, 0, 0, 1);
Matrix fib = Matrix(0, 1, 1, 1);
Matrix binexp(Matrix base, ll exp, ll M) {
    if (exp == 0)
        return iden;
    Matrix ret = binexp(base, exp / 2, M);
    ret = ret * ret;
    if (exp & 1)
        ret = ret * base;
    return ret;
}
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
    ll n;
    cin >> n;
    Matrix x = binexp(fib, n, mod);
    cout << x.m[0][1] << endl;
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