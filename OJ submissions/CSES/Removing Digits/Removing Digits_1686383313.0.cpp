#include <bits/stdc++.h>
 using namespace std;
 #define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
 const int mod = 1e9+7;
const int N = 1e6+10;
 ll dp[N];
 ll count_steps(int n){
 if(n/10==0){
  return 1;
 }
 if(dp[n]!=-1)
  return dp[n];
 string s = to_string(n);
 ll ret = LLONG_MAX;
  for(int i = 0; i < s.size(); i++){
  int cur = s[i]- '0';
  if(cur==0)
   continue;
  ret = min(ret, 1+count_steps(n-cur));
  }
 return dp[n] = ret;
 }
 void solve(){
 int n;
 cin>>n;
 memset(dp, -1, sizeof(dp));
 cout << count_steps(n) << endl;
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