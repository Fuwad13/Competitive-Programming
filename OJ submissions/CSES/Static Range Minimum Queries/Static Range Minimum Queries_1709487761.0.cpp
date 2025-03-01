#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 // #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 using namespace std;
using namespace __gnu_pbds;
template<class T>
    using iset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 #define endl "\n"
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
 using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9+7;
const int N = 1e7;
 template <class T>
struct sparse_table {
    int n, LG;
    vector<vector<T>> table;
    vector<int> lgs;
    function<T(const T&, const T&)> merge;
     sparse_table(vector<T>& v, function<T(const T&, const T&)> merge): n(v.size()), merge(merge){
        LG = __lg(n) + 1;
        table.assign(LG, vector<T>(n, 0));
        lgs.assign(n+1, 0);
        for(int i = 0; i < n; i++)
            table[0][i] = v[i];
        lgs[1] = 0;
        for(int i = 2; i <=n; i++)
            lgs[i] = lgs[i/2] + 1;
        for(int i = 1; i < LG; i++){
            for(int j = 0; j + (1<<i) - 1 < n; j++){
                table[i][j] = merge(table[i-1][j], table[i-1][j+(1<<(i-1))]);
            }
        }  
    }
     T query(int l, int r){
        int lg = lgs[r-l+1];
        return merge(table[lg][l], table[lg][r-(1<<lg)+1]);
    }
};
 void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    read(v);
    sparse_table<int> st(v, [](int a, int b){return min(a, b);});
    while(q--){
        int l,r ;
        cin>>l>>r;
        cout << st.query(l-1, r-1) << endl;
    }
  }
 #define ONLINE_JUDGE
 int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " << 
    std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
    << " seconds" << endl;
    return 0;
}