#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
  const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5+69;
const int B = 450;
 int n, timer = -1;
vector<int> adj[N];
vector<int> col(N), in(N), out(N), euler(N);
 void dfs(int v, int p){
    in[v] = ++timer;
    euler[timer] = col[v];
    for(auto c: adj[v]){
        if(c^p){
            dfs(c,v);
        }
    }
    out[v] = timer;
}
 void solve(){
    cin>>n;
    map<int, int> mp;
    for(int i = 1; i <=n; i++){
        cin>>col[i];
        mp[col[i]];
    }
    int temp = 0;
    for(auto &[x, y]: mp){
        y=temp++;
    }
    for(int i = 1; i <=n; i++){
        col[i] = mp[col[i]];
    }
    for(int i= 0; i < n-1; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    vector<array<int, 4>> queries;
    for(int i = 1; i <=n; i++){
        queries.push_back({in[i]/B, out[i], in[i], i});
    }
    sort(all(queries));
    vector<int> ans(n+1);
    int distinct = 0;
    vector<int> freq(mp.size()+1);
    int left = 0, right = -1;
    for(auto _: queries){
        auto [lb,r, l, id] = _;
        while(right < r){
            right++;
            freq[euler[right]]++;
            if(freq[euler[right]]==1)
                distinct++;
        }
        while(right > r){
            freq[euler[right]]--;
            if(freq[euler[right]]==0)
                distinct--;
            right--;
        }
        while(left < l){
            freq[euler[left]]--;
            if(freq[euler[left]]==0)
                distinct--;
            left++;
        }
        while(left > l){
            left--;
            freq[euler[left]]++;
            if(freq[euler[left]]==1)
                distinct++;
        }
        ans[id] = distinct;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    }
 signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    return 0;
}