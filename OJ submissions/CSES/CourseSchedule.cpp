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

bool vis[N];
int state[N];
stack<int> st;
bool flag = true;
void dfs(vector<int>* graph, int node){
	vis[node]=1;
	state[node]=1;
	for(auto adj: graph[node]){
		if(!vis[adj]){
			dfs(graph, adj);
		}
		else if(state[adj]==1){
			flag = false;
		}
	}
	state[node]=2;
	st.push(node);

}

void solve(){
	int n, m;
	cin>>n>>m;
	vector<int> graph[n+1];
	for(int i = 0; i < m; i++){
		int x, y;
		cin>>x>>y;
		graph[x].pb(y);
	}
	for(int i = 1; i <=n; i++){
		if(!vis[i])
			dfs(graph, i);
	}
	if(!flag)
		cout << "IMPOSSIBLE\n";
	else{
		while(!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
	}
	

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