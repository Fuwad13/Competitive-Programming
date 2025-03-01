#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 class HashedString {
  private:
    // use randomized base for safeguarding anti hash tests
    static const ll M = 1e9 + 9;
    static const ll B = 9973;
     // pow[i] contains B^i % M
    static vector<ll> pow;
     // p_hash[i] is the hash of the first i characters of the given string
    vector<ll> p_hash;
   public:
    HashedString(const string &s) : p_hash(s.size() + 1) {
        while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }
         p_hash[0] = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }
     ll getHash(int start, int end) {
        ll raw_val =
            (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
};
vector<ll> HashedString::pow = {1};
  void solve(){
    string s, t;
    cin>>s>>t;
    int n, m;
    n = s.size(), m = t.size();
    HashedString hs(s), ht(t);
    int cnt = 0;
    for(int i = 0; i+m-1 < n; i++){
        if(hs.getHash(i, i+m-1)==ht.getHash(0, m-1))
            cnt++;
    }
    cout << cnt << endl;
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