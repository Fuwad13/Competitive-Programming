#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
const int B = 450;
 void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    map<int, int> coord;
    for(auto &x: v){
        cin>>x;
        coord[x];
    }
    int ind = 0;
    for(auto &[x, y]: coord)
        y = ind++;
    for(auto &x: v)
        x = coord[x];
    vector<array<int, 4>> queries(q); // {l/B, r, l, id}
    for(int i = 0; i < q; i++){
        int l, r;
        cin>>l>>r;
        l--, r--;
        queries[i] = array{l/B, r, l, i};
    }
    sort(all(queries));
    vector<int> ans(q);
    int distinct = 0, left = 0, right = -1;
    vector<int> freq(ind);
    auto add = [&](int idx) -> void {
        freq[v[idx]]++;
        if(freq[v[idx]]==1)
            distinct++;
    };
    auto remove = [&](int idx) -> void {
        freq[v[idx]]--;
        if(freq[v[idx]]==0)
            distinct--;
    };
    for(int i= 0; i < q; i++){
        auto [_, r, l, id] = queries[i];
        while(right < r)
            add(++right);
        while(right > r)
            remove(right--);
        while(left > l)
            add(--left);
        while(left < l)
            remove(left++);
        ans[id] = distinct;
    }
    for(auto x: ans)
        cout << x << "\n";
  }
 signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    return 0;
}