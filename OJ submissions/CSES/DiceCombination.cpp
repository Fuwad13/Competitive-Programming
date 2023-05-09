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
int memo[N+10];
 
int ways(int n){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(memo[n]!=-1)
		return memo[n];
 
	int res = 0;
	res = (res%mod + ways(n-1)%mod) % mod;
	res = (res%mod + ways(n-2)%mod) % mod;
	res = (res%mod + ways(n-3)%mod) % mod;
	res = (res%mod + ways(n-4)%mod) % mod;
	res = (res%mod + ways(n-5)%mod) % mod;
	res = (res%mod + ways(n-6)%mod) % mod;
 
	return memo[n] = res;
 
}
 
void solve(){
	int n;
	cin>>n;
	memset(memo, -1, sizeof(memo));
	cout << ways(n) << endl;
 
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