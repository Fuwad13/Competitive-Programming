#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 void solve(){
    ll n, x;
    cin>>n>>x;
    vector<ll> v(n);
    for(auto &x: v)
        cin>>x;
    vector<pair<ll, ll>> dp(1<<n);
    // dp[X].first = # min rides for subset X
    // dp[X].second = min weight of the last ride for subset X
    dp[0] = {1, 0}; 
    for(int mask = 1; mask < 1<<n; mask++){
        dp[mask] = {n+1, 0};
        for(int p = 0; p < n; p++){
            if(mask&(1<<p)){
                auto option = dp[mask^(1<<p)];
                if(option.second+v[p] <= x){
                    option.second+=v[p];
                }
                else{
                    option.first++;
                    option.second=v[p];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }
    cout << dp[(1<<n)-1].first << "\n";
}
 signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    return 0;
}