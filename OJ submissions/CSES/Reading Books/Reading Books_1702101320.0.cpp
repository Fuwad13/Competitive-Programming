#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
  void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(auto &x: v)
        cin>>x;
    ll mx = *max_element(all(v));
    ll sum = accumulate(all(v), 0LL);
    if(mx>sum-mx){
        cout << 2*mx << endl;
    }
    else
        cout << sum << endl;
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