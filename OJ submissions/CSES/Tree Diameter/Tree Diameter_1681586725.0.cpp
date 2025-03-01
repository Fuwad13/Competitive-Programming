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
const int N = 1e7;
int n;
  void solve(){
 cin>>n;
 vector<int> tree[n+1];
 for(int i = 1; i < n; i++){
  int x,y;
  cin>>x>>y;
  tree[x].pb(y);
  tree[y].pb(x);
  }
 //take 1 as root and run bfs
 queue<int> q;
 q.push(1);
 vector<int> dist(n+1, -1);
 dist[1]= 0;
 int mx = 0, mxVertice = 1;
 while(!q.empty()){
  int cur = q.front();
  q.pop();
  for(auto a: tree[cur]){
   if(a==cur)
    continue;
   if(dist[a]==-1){
    dist[a] = 1 + dist[cur];
    if(dist[a]>mx){
     mx = dist[a];
     mxVertice=a;
    }
    q.push(a);
    }
  }
 }
 int d2[n+1];
 memset(d2, -1, sizeof(d2));
 queue<int> q2;
 q2.push(mxVertice);
 d2[mxVertice]=0;
 mx = 0;
 while(!q2.empty()){
  int cur = q2.front();
  q2.pop();
  for(auto a: tree[cur]){
   if(a==cur)
    continue;
   if(d2[a]==-1){
    d2[a]=1+d2[cur];
    mx = max(mx, d2[a]);
    q2.push(a);
   }
   }
 }
 cout << mx << endl;
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