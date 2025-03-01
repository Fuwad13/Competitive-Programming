#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 void solve(){
    ll n;
    cin>>n;
    ll low = 1, high = n*n, ans = high;
    auto works = [&](ll x) -> bool {
        ll sum = 0;
        for(ll i = 1; i <=n; i++)
            sum+=min((x-1)/i, n);
        return sum < ((n*n)/2 + 1);
    };
     while(low<=high){
        ll mid = (low+high)>>1;
        if(works(mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout << ans <<"\n";
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