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
struct DSU {
    vector<int> rep; // store negation of size of representative
    int cc;
    DSU(int sz) { \
        rep = vector<int>(sz, -1); 
        cc = sz-1;
    }
 
    // get representive component (uses path compression)
    int get(int x) { return rep[x] < 0 ? x : rep[x] = get(rep[x]); }
 
    bool same_set(int a, int b) { return get(a) == get(b); }
 
    int size(int x) { return -rep[get(x)]; }
 
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rep[x] > rep[y]) swap(x, y); // rep[x] less means bigger size
        rep[x] += rep[y];
        rep[y] = x;
        cc--;
        return true;
    }
};
 
 
void solve(){
    int n, m;
    cin>>n>>m;
    DSU dsu(n+1);
    int mx = 0;
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        if(x>y)
            swap(x, y);
        dsu.unite(x, y);
        mx = max(mx, dsu.size(x));
        cout << dsu.cc << " " << mx << endl;
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