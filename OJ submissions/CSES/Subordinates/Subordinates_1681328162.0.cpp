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
const int N = 2e5+10;
vector<int> tree[N];
int n;
int cnt[N];
 int dfs(int node, int par = -1){
 int ret = 0;
 if(cnt[node]!=-1)
  return cnt[node];
 for(auto child: tree[node]){
  if(child==par)
   continue;
  ret+=1+dfs(child, node);
 }
 return cnt[node] = ret;
}
 void solve(){
  cin>>n;
 for(int i = 2; i <= n; i++){
  int x;
  cin>>x;
  tree[x].pb(i);
  tree[i].pb(x);
 }
 memset(cnt, -1, sizeof(cnt));
 dfs(1);
 for(int i = 1; i <=n; i++)
  cout << cnt[i] << ' ';
 cout << endl;
  // 1 is root
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