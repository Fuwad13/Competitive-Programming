#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
ll dp[20][11][2][2];
string num;
 ll calc(int pos, int banned, bool tight, bool lz){
    if(pos<0){
        return 1;
    }
    ll &ans = dp[pos][banned][tight][lz];
    if(ans!=-1)
        return ans;
    ans = 0;
    if(tight){
        for(int i = 0; i <= num[pos]-'0'; i++){
            if(i!=banned or (i==0 and !lz)){
                ans+=calc(pos-1, i, (i==num[pos]-'0'), lz | (i!=0));
            }
        }
    }
    else{
        for(int i = 0; i <10; i++){
            if(i!=banned or (i==0 and !lz)){
                ans+= calc(pos-1, i, tight, lz | (i!=0));
            }
        }
    }
    return ans;
}
 ll fun(ll x){
    num = to_string(x);
    reverse(all(num));
    int n = num.size();
    memset(dp, -1, sizeof(dp));
    return calc(n-1, 10, 1, 0);
 }
 void solve(){
    ll a, b;
    cin>>a>>b;
    cout << fun(b) - fun(a-1) << "\n";
    debug(fun(b), fun(a-1));
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