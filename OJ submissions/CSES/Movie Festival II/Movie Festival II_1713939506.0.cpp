#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 void solve(){
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(all(v), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    int ans = 0;
    multiset<int> ms;
    for(int i= 0; i < k; i++)
        ms.insert(0);
    for(int i = 0; i < n; i++){
        int now = v[i].first;
        auto it = ms.upper_bound(now);
        if(it==ms.begin())
            continue;
        it--;
        ans++;
        ms.insert(v[i].second);
        ms.erase(it);
    }
    cout << ans << "\n";
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