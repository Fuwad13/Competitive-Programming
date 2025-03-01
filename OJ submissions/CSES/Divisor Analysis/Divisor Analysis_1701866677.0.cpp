#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 // ll binexp(ll base, ll exp, ll M) {
//     base %= M;
//     ll res = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1) { res = res * base % M;}
//         base = base * base % M;
//         exp>>=1;
//     }
//     return res;
// }
 ll binexp(ll base, ll exp, ll M){
    if(exp==0)
        return 1;
    ll ret = binexp(base, exp/2, M);
    ret=((ret%M)*(ret%M))%M;
    if(exp&1)
        return ((ret%M)*(base%M))%M;
    return ret;
}
  void solve(){
    ll n;
    cin>>n;
    ll nod = 1, sod = 1, pod=1, num=1;
    vector<ll> prime(n), cnt(n);
    bool oddexp = false;
    int pos = -1;
    for(int i = 0; i < n; i++){
        ll x, k;
        cin>>x>>k;
        if(!oddexp and k&1){
            oddexp = true;
            pos = i;
        }
        prime[i]=x, cnt[i]=k;
        nod=(nod*(k+1))%mod;
        sod = (sod*(((binexp(x, k+1, mod)-1)*(binexp(x-1, mod-2, mod)))%mod))%mod;
        num = (num*binexp(x, k, mod))%mod;
    }
    if(oddexp){
        ll outer = 1;
        for(int i=0; i < n; i++){
            if(i==pos){
                outer = (outer*((cnt[i]+1)/2))%(mod-1);
            }  
            else{
                outer = (outer*(cnt[i]+1))%(mod-1);
            }
        }
        for(int i = 0; i < n; i++){
            pod = (pod*(binexp(prime[i], (cnt[i]*outer)%(mod-1), mod)))%mod;
        }
     }
    else{
        ll outer = 1;
        for(int i = 0; i < n; i++){
            outer = (outer*(cnt[i]+1))%(mod-1);
        }
        for(int i= 0; i < n; i++){
            pod = (pod*(binexp(prime[i], ((cnt[i]/2)*outer)%(mod-1), mod)))%mod;
        }
    }
     cout<< nod << ' ' << sod << ' ' << pod << "\n";
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