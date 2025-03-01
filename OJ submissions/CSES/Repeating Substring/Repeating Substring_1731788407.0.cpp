#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 #ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
 struct SuffixArray {
    vector<int> sa, lcp;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
        int n = s.size() + 1, k = 0, a, b;
        vector<int> x(all(s)), y(n), ws(max(n, lim));
        x.push_back(0), sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            for(int i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            for(int i =0; i < n; i++) ws[x[i]]++;
            for(int i = 1; i< lim; i++) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for(int i =1; i< n; i++) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
            for (k && k--, j = sa[x[i] - 1];
                    s[i + k] == s[j + k]; k++);
    }
};
 template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= int(V.size()); pw *= 2, ++k) {
            jmp.emplace_back(int(V.size()) - pw * 2 + 1);
            for(int j=0; j < int(jmp[k].size()); j++)
                jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};
 void solve(){
    string s;
    cin>>s;
    int n = s.size();
    SuffixArray SA(s);
    vector<pair<int, int>> v(n+1);
    for(int i = 0; i <=n; i++)
        v[i]={SA.lcp[i], i};
    RMQ<pair<int, int>> rmq(v);
    auto [sz, ind] = rmq.query(0, n+1);
    if(!sz){
        cout << -1 << "\n";
        return;
    }
    ind = SA.sa[ind];
    cout << s.substr(ind, sz) << "\n";
}
 signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " << 
    std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
    << " seconds" << endl;
    return 0;
}