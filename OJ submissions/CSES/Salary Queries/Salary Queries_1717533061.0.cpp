#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 #ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
 template <class T>
struct segment_tree{
    int n;
    vector<T> stree;
    function<T(const T&, const T&)> merge;
    T identity = T();
    segment_tree(int n, function<T(const T&, const T&)> merge, T identity): n(n), merge(merge), identity(identity){
        stree.resize(n<<1);
    }
    void build(){
        for (int i = n - 1; i > 0; i--)
            stree[i] = merge(stree[i << 1], stree[i << 1 | 1]);
    }
    segment_tree(const vector<T>& arr, function<T(const T&, const T&)> merge, T identity): n(arr.size()), merge(merge), identity(identity){
        stree.resize(n<<1);
        for(int i=0; i<n; i++)
            stree[i+n] = arr[i];
        build();
    }
    void set(int ind, T val){
        ind+=n;
        for (stree[ind] = val; ind > 1; ind >>= 1){
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    void update(int ind, T val){
        ind+=n;
        for (stree[ind] = merge(val, stree[ind]); ind > 1; ind >>= 1){
            stree[ind >> 1] = merge(stree[ind], stree[ind ^ 1]);
        }
    }
    T query(int l, int r){ // closed interval [l,r]
        T ansl = identity;
        T ansr = identity;
        for (l+=n, r+=n+1; l<r; l>>=1, r>>=1)
        {
            if (l&1){
                ansl = merge(ansl, stree[l++]);
            }
            if (r&1){
                ansr = merge(stree[--r], ansr);
            }
        }
        return merge(ansl, ansr);
    }
};
 void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    map<int, int> coord;
    vector<int> coordv;
    for(int i = 0; i <n; i++){
        cin>>v[i];
        // coord[v[i]];
        coordv.push_back(v[i]);
    }
    vector<array<int, 3>> queries(q);
    for(int i = 0; i < q; i++){
        char ch;
        cin>>ch;
        queries[i][0]= ch=='?';
        cin>>queries[i][1]>>queries[i][2];
        if(ch=='!'){
            // coord[queries[i][2]];
            coordv.push_back(queries[i][2]);
        }
        else{
            // coord[queries[i][1]];
            // coord[queries[i][2]];
            coordv.push_back(queries[i][1]);
            coordv.push_back(queries[i][2]); 
        }
    }
    sort(all(coordv));
    int ind = 0;
    for(auto &x: coordv)
        coord[x] = ind++;
     segment_tree<int> st(ind, [](int a, int b){return a+b;}, 0);
    for(int i= 0; i < n; i++)
        st.update(coord[v[i]], 1);
    for(auto [x, y, z]: queries){
        if(!x){
            int prev = v[y-1];
            st.update(coord[prev], -1);
            v[y-1] = z;
            st.update(coord[z], 1);
        }
        else{
            cout << st.query(coord[y], coord[z]) << "\n";
        }
    }
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