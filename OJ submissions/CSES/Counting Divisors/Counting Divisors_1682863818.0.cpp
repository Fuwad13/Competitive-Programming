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
const int N = 1e6;
int spf[N+5];
 void pre(){
 for(int i = 0; i <= N; i++)
  spf[i] = i;
 for(int i = 2; i <= N; i+=2)
  spf[i]=2;
 for(int i = 3; i*i <= N; i+=2){
  if(spf[i]==i){
   for(int j = i*i; j<=N;j+=2*i)
    spf[j]=i;
  }
 }
 }
 void solve(){
 int n;
 cin>>n;
 map<int, int> mp;
 while(n!=1){
  mp[spf[n]]++;
  n/=spf[n];
 }
 int ans = 1;
 for(auto el: mp){
  ans*=(el.second+1);
 }
 cout << ans << endl;
 }
 //#define ONLINE_JUDGE
 int main(){
   ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif
 pre();
 int t = 1;
 cin >> t;
 while(t--){
  solve();
 }
 return 0;
 }