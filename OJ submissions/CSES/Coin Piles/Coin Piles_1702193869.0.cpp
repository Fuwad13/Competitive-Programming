#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 void solve(){
    int a, b;
    cin>>a>>b;
    if(2*a-b>=0 and (2*a-b)%3==0 and 2*b-a>=0 and (2*b-a)%3==0)
        cout << "YES\n";
    else
        cout << "NO\n";
}
 signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    return 0;
}