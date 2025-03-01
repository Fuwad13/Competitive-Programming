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
 vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
 vector<int> manacher(string s) {
    string t;
    for(auto c: s) t += string("#") + c;
    auto d = manacher_odd(t + "#");
    return vector<int>(begin(d) + 1, end(d) - 1);
}
/**
 * d_odd[i] = d[2i]/2 ; s[i] in center, len = 2*x-1
 * d_even[0] = 0;
 * d_even[i] = (d[2i-1]-1)/2 , i>0; s[i-1]s[i] in center, len = 2*x
**/
  void solve(){
    string s;
    cin>>s;
    auto m = manacher(s);
    debug(m);
    int l=0, r = 0, best = 0;
    for(int i = 0; i < m.size(); i++){
        if(m[i]-1>best){
            best = m[i]-1;
            if(i&1){
                int ind = (i+1)/2;
                l = ind - ((m[i]-1)/2), r = ind-1+((m[i]-1)/2);
            }
            else{
                int ind = i/2;
                l = ind - (m[i]/2-1), r = ind+(m[i]/2-1);
            }
        }
    }
    for(int i = l; i <=r; i++)
        cout << s[i];
}
 signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    return 0;
}