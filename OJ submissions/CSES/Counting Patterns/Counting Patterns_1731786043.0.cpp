#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
struct SuffixArray {
    vector<int> sa, lcp;
    SuffixArray(string &s, int lim = 256) { // or basic_string<int>
        int n = s.size() + 1, k = 0, a, b;
        vector<int> x(all(s)), y(n), ws(max(n, lim));
        x.push_back(0), sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            for (int i = 0; i < n; i++)
                if (sa[i] >= j)
                    y[p++] = sa[i] - j;
            fill(all(ws), 0);
            for (int i = 0; i < n; i++)
                ws[x[i]]++;
            for (int i = 1; i < lim; i++)
                ws[i] += ws[i - 1];
            for (int i = n; i--;)
                sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                a = sa[i - 1], b = sa[i],
                x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
            for (k &&k--, j = sa[x[i] - 1]; s[i + k] == s[j + k]; k++)
                ;
    }
};
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    SuffixArray SA(s);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string p;
        cin >> p;
        int l, r;
        l = 1, r = n;
        for (int j = 0; j < p.size(); j++) {
            bool flag = false;
            int low = l, high = r;
            while (low <= high) {
                int mid = (low + high) >> 1;
                int ind = SA.sa[mid] + j;
                if (ind >= n) {
                    low = mid + 1;
                    continue;
                }
                if (s[ind] == p[j]) {
                    flag = true;
                    l = mid;
                    high = mid - 1;
                } else if (s[ind] > p[j]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (!flag) {
                l = r = -1;
                break;
            }
            low = l, high = r;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (SA.sa[mid] + j >= n) {
                    low = mid + 1;
                    continue;
                }
                if (s[SA.sa[mid] + j] == p[j]) {
                    flag = true;
                    r = mid;
                    low = mid + 1;
                } else if (s[SA.sa[mid] + j] > p[j]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (l == -1 or r == -1)
            cout << 0 << "\n";
        else
            cout << r - l + 1 << "\n";
    }
}
signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: "
         << std::chrono::duration_cast<std::chrono::duration<double>>(end -
                                                                      begin)
                .count()
         << " seconds" << endl;
    return 0;
}