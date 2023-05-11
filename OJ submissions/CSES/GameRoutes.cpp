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
const int N = 1e5+10;
int n, m;
ll dp[N];
ll count_ways(vector<int>* graph, int lvl){
	if(lvl==n){
		return 1;
	}
	if(dp[lvl]!=-1)
		return dp[lvl];
	ll ret = 0;
	for(auto adj: graph[lvl]){
		ret = (ret%mod +count_ways(graph, adj)%mod)%mod;
	}
	return dp[lvl] = ret;
}

void solve(){
	
	cin>>n>>m;
	vector<int> graph[n+1];
	for(int i = 0; i < m; i++){
		int a, b;
		cin>>a>>b;
		graph[a].pb(b);
	}
	memset(dp, -1, sizeof(dp));
	ll ans = count_ways(graph, 1);
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
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;

}