#include <bits/stdc++.h>
 using namespace std;
 #define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
 const int mod = 1e9+7;
const int N = 5005;
int dp[N][N];
string a, b;
int n, m;
 int edist(int i, int j){
    if(i==-1)
        return j+1;
    if(j==-1)
        return i+1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==b[j])
        return dp[i][j] = edist(i-1, j-1);
    dp[i][j] = 1+edist(i, j-1); // delete jth char from b
    dp[i][j] = min(dp[i][j], 1+edist(i-1, j)); // insert a[i] at j+1 th pos in b
    dp[i][j] = min(dp[i][j], 1+edist(i-1, j-1)); // replace b[j] with a[i]
    return dp[i][j];
}
  void solve(){
        cin>>a>>b;
    n = a.size();
    m = b.size();
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         if(a[i-1]==b[j-1]){
    //             dp[i][j] = dp[i-1][j-1];
    //         }
    //         else{
    //             dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
    //         }
    //     }
    // }
    // cout << dp[n][m] << endl;
    memset(dp, -1, sizeof(dp));
    cout << edist(n-1, m-1) << endl;
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
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}