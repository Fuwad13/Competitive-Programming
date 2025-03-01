#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 5005;
ll dp[N][N], a[N];
int n;
ll A = 0;
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
 void ans2(int l, int r, int p){
    if(l>r)
        return;
    ll c1 = a[l] - ans(l+1, r);
    ll c2 = a[r] - ans(l, r-1);
    if(c1>=c2){
        if(p)
            A+=a[l];
        ans2(l+1, r, 1-p);
     }
    else{
        if(p)
            A+=a[r];
        ans2(l, r-1, 1-p);
    }
}
 void solve(){
    cin>>n;
    for(int i = 0; i < n;i++)
        cin>>a[i];
    memset(dp, -1, sizeof(dp));
    ans2(0, n-1, 1);
    cout << A << endl;
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