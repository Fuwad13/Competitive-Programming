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
const int N = 1005;
int n;
int grid[N][N];
 
ll memo[N][N];
 
ll dp(int r, int c){
	if(r==n-1 and c==n-1){
		return grid[n-1][n-1];
	}
	if(memo[r][c]!=-1)
		return memo[r][c];
	ll ret = 0;
	if(r+1<n and grid[r+1][c]){
		//ret+=dp(r+1, c);
		ret = (ret%mod + dp(r+1, c)%mod)%mod;
	}
	if(c+1<n and grid[r][c+1]){
		ret = (ret%mod + dp(r, c+1)%mod)%mod;
	}
	return memo[r][c] = ret;
}
 
void solve(){
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char ch;
			cin>>ch;
			if(ch=='.')
			    grid[i][j] = 1;
			else
				grid[i][j] = 0;
		}
	}
	if(grid[0][0]==0){
		cout << 0 << endl;
		return;
	}
	memset(memo, -1, sizeof(memo));
	ll ans = dp(0, 0);
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
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
 
}