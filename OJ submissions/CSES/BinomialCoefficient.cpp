#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl

const int mod = 1e9+7;
const int N = 1e6;
int fac[N+1];
void precompute(){
    fac[0] = 1;
    for(int i = 1; i <=N; i++){
        fac[i] = (fac[i-1]*1LL*i)%mod;
    }
}
ll binexp(ll base, ll exp, ll M){
    if(exp==0)
        return 1;
    ll ret = binexp(base, exp/2, M);
    ret=((ret%M)*(ret%M))%M;
    if(exp&1)
        return ((ret%M)*(base%M))%M;
    return ret;
}

int inv(int n){
    return binexp(n, mod-2, mod);
}
int nCr(int n, int r){
    return (fac[n]*1LL*(((inv(fac[r]))*1LL*(inv(fac[n-r])))%mod))%mod;
}


void solve(){
    int a, b;
    cin>>a>>b;
    cout << nCr(a, b) << endl;


}

//#define ONLINE_JUDGE

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    precompute();
    while(t--){
        solve();
    }
    return 0;

}