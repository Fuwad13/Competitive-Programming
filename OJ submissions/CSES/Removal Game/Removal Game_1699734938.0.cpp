#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 5005;
ll dp[N][N], a[N];
int n;
ll A = 0, sum = 0;
ll ans(int l, int r){
    if(l>r)
        return 0;
    ll &cur = dp[l][r];
    if(cur!=-1)
        return cur;
    cur = a[l] - ans(l+1, r);
    cur = max(cur, a[r] - ans(l, r-1));
    return cur;
}
 void solve(){
    cin>>n;
    for(int i = 0; i < n;i++)
        cin>>a[i], sum+=a[i];
    memset(dp, -1, sizeof(dp));
    cout << ((ans(0, n-1)+sum)>>1) << endl;
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