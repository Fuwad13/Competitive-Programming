#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v(k);
    for(auto &x: v)
        cin>>x;
    sort(all(v));
    vector<bool> dp(n+1, false);
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        for(auto x: v){
            if(i-x<0)
                break;
            dp[i] = (dp[i] | (!dp[i-x]));
        }
        cout << (dp[i] ? "W": "L");
    }
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