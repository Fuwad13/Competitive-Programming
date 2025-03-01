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
    int zor = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        x%=4;
        zor^=x;
    }
    cout << (zor==0?"second":"first") << "\n";
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