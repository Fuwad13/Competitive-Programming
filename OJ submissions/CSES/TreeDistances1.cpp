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
	set<int> st;
	for(int i = 1; i < n; i++){
		st.insert(i);
		int x,y;
		cin>>x>>y;
		tree[x].pb(y);
		tree[y].pb(x);
 
	}
	int e1, e2;
	// find two endpoints
	queue<int> q;
	int dist[n+1];
	memset(dist, -1, sizeof(dist));
	dist[1]=0;
	q.push(1);
	int mx = 0, mxVertice = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto a: tree[cur]){
			if(dist[a]==-1){
				dist[a]=1+dist[cur];
				if(mx < dist[a]){
					mx = dist[a];
					mxVertice = a;
				}
				q.push(a);
			}
		}
	}
	vector<int> ans(n+1);
	memset(dist, -1, sizeof(dist));
	q.push(mxVertice);
	dist[mxVertice]=0;
	mx = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto a: tree[cur]){
			if(dist[a]==-1){
				dist[a] = 1+dist[cur];
				if(mx < dist[a]){
					mx = dist[a];
					mxVertice = a;
				}
				q.push(a);
				ans[a] = max(ans[a], dist[a]);
			}
		}
	}
	memset(dist, -1 , sizeof(dist));
	q.push(mxVertice);
	dist[mxVertice]=0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto a: tree[cur]){
			if(dist[a]==-1){
				q.push(a);
				dist[a]=1+dist[cur];
				ans[a] = max(ans[a], dist[a]);
			}
		}
	}
	for(int i = 1; i <=n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
 
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