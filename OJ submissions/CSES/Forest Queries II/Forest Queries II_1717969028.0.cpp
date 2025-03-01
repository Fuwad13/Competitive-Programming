#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
template <class T> struct fenwick2d { // 1 based indexing
    int n, m;
    vector<vector<T>> bit;
    fenwick2d(int n, int m) : n(n), m(m) {
        bit = vector(n + 1, vector<T>(m + 1));
    }
    fenwick2d(const vector<vector<T>> &v) : n(v.size()), m(v[0].size()) {
        bit = vector(n + 1, vector<T>(m + 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                update(i + 1, j + 1, v[i][j]);
    }
    void update(int x, int y, T val) {
        while (x <= n) {
            for (int i = y; i <= n; i += i & -i)
                bit[x][i] += val;
            x += x & -x;
        }
    }
    T query(int x, int y) {
        T sum = 0;
        while (x > 0) {
            for (int i = y; i > 0; i -= i & -i)
                sum += bit[x][i];
            x -= x & -x;
        }
        return sum;
    }
    T query(int x1, int y1, int x2, int y2) {
        T sum1 = query(x2, y2);
        T sum2 = query(x2, y1 - 1);
        T sum3 = query(x1 - 1, y2);
        T sum4 = query(x1 - 1, y1 - 1);
        return sum1 - sum2 - sum3 + sum4;
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = ch == '*';
        }
    }
    fenwick2d<int> f2d(grid);
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp & 1) {
            int x, y;
            cin >> x >> y;
            auto prev = f2d.query(x, y, x, y);
            f2d.update(x, y, 1 - 2 * prev);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << f2d.query(x1, y1, x2, y2) << "\n";
        }
    }
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