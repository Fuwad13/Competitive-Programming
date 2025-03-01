#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
    using iset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 #ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 69
#endif
 struct info{
    vector<ll> v, p;
};
 template <class T>
struct segment_tree{
    int n;
    vector<T> stree;
    function<T(const T&, const T&)> merge;
    T identity = T();
    segment_tree(int n, function<T(const T&, const T&)> merge, T identity): n(n), merge(merge), identity(identity){
        stree.resize(4*n+5);
    }
    void build(const vector<T>& arr, int node, int b, int e){
        if(b==e){
            stree[node] = arr[b];
            return;
        }
        int mid = (b+e)>>1;
        build(arr, 2*node, b, mid);
        build(arr, 2*node+1, mid+1, e);
        stree[node] = merge(stree[2*node],stree[2*node+1]);
    }
    segment_tree(const vector<T>& arr, function<T(const T&, const T&)> merge, T identity): n(arr.size()), merge(merge), identity(identity){
        stree.resize(4*n+5);
        build(arr, 1, 0, n-1);
    }
     ll query(int node, int b, int e, int l, int r, ll k){
        if(l > e or r < b)
            return 0;
        if(l<=b and r>=e){
            auto it = upper_bound(all(stree[node].v), k) - stree[node].v.begin();
            // debug(b, e, it);
            // debug(stree[node].v, stree[node].p, stree[node].p.size());
            ll ret = (it? it*k - stree[node].p[it-1] : 0);
            ret+=(stree[node].p.back() - (it?stree[node].p[it-1]:0))-((ll)stree[node].p.size() - it)*k;
            return ret;
        }
        int mid = (b+e)>>1;
        ll c1 = query(2*node, b, mid, l, r, k);
        ll c2 = query(2*node+1, mid+1, e, l, r, k);
        return (c1+c2);
    }
    ll query(int l, int r, ll k){return query(1, 0, n-1, l, r, k);}
};
 void solve(){
    ll n, k;
    cin>>n>>k;
    vector<info> v(n);
    iset<pair<ll, ll>> ist;
    ll timer = 0;
    ll median = (k+1)/2 -1;
    for(int i= 0; i < n; i++){
        ll x;
        cin>>x;
        v[i].v.push_back(x);
        v[i].p.push_back(x);
        if(i<k){
            ist.insert({v[i].v.front(), timer++});
        }
    }
    segment_tree<info> st(v, [](const info& a, const info& b){
        info ret;
        ret.v.resize(a.v.size()+b.v.size());
        merge(all(a.v), all(b.v), ret.v.begin());
        ret.p.resize(a.v.size()+b.v.size());
        partial_sum(all(ret.v), ret.p.begin());
        return ret;
    }, info());
    // debug(st.stree[1].v, st.stree[1].p);
    cout << st.query(0, k-1, ist.find_by_order(median)->first) << " ";
    for(int i = k; i < n; i++){
        ist.erase(ist.lower_bound({v[i-k].v[0], 0}));
        ist.insert({v[i].v[0], timer++});
        cout << st.query(i-k+1, i, ist.find_by_order(median)->first) << " ";
    }
 }
 signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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