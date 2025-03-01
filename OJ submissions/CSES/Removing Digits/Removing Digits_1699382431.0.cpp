#include <bits/stdc++.h>
using namespace std;
 const int N = 1e6+10;
int dp[N];
void prec(){
    for(int i = 1;i<10; i++)
        dp[i]=1;
    for(int i = 10; i <N; i++){
        dp[i]=N;
        string s = to_string(i);
        for(auto x: s){
            dp[i] = min(dp[i], 1+dp[i - (x-'0')]);
        }
    }
}
 void solve(){
    int n;
    cin>>n;
    cout << dp[n] << endl;
}
 //#define ONLINE_JUDGE
 int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    prec();
    for(int i = 1; i <=t; i++){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " << 
    std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
    << " seconds" << endl;
    return 0;
}