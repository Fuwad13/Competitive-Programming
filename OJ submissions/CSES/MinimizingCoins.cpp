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
int dp[N];
 
void solve(){
	int n, x;
	cin>>n>>x;
	vector<int> coins(n);
	
	read(coins);
	sort(all(coins));
	for(int i = 1; i <=x; i++)
		dp[i]=1e9;
	dp[0]=0;
	for(int i = 1; i <=x; i++){
		for(auto a: coins){
			if(i-a>=0){
				if(dp[i-a]!=1e9)
					dp[i] = min(1+dp[i-a], dp[i]);
			}
			else
				break;
		}
	}
	cout << (dp[x]==1e9?-1:dp[x]) << endl;
 
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