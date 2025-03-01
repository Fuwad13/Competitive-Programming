#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
 const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
 template <class T>
struct segment_tree{
    int n;
    vector<T> stree, lazy;
    function<T(const T&, const T&)> merge;
    T identity = T();
    T lazy_identity = T();
    segment_tree(int n, function<T(const T&, const T&)> merge, T identity, T lazy_identity): 
    n(n), merge(merge), identity(identity), lazy_identity(lazy_identity){
        stree.resize(4*n+5);
        lazy.resize(4*n+5);
    }
    void build(const vector<T>& arr, int node, int b, int e){
        lazy[node]=lazy_identity;
        if(b==e){
            stree[node] = arr[b];
            return;
        }
        int mid = (b+e)>>1;
        build(arr, 2*node, b, mid);
        build(arr, 2*node+1, mid+1, e);
        stree[node] = merge(stree[2*node],stree[2*node+1]);
    }
    segment_tree(const vector<T>& arr, function<T(const T&, const T&)> merge, T identity, T lazy_identity): 
    n(arr.size()), merge(merge), identity(identity), lazy_identity(lazy_identity){
        stree.resize(4*n+5);
        lazy.resize(4*n+5);
        build(arr, 1, 0, n-1);
    }
    void propagate(int node, int b, int e){
        if(lazy[node]==lazy_identity) return;
        stree[node]+=(e-b+1)*1LL*lazy[node]; // update stree[node] accordingly
        if(b!=e){ // apply lazy to children 
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=lazy_identity;
    }
    void update(int node, int b, int e, int l, int r, T val){
        propagate(node, b, e);
        if(l > e or r < b)
            return;
        if(l<=b and r>=e){
            lazy[node]+=val; // apply to lazy
            propagate(node, b, e);
            return;
        }
        int mid = (b+e)>>1;
        update(2*node, b, mid, l, r, val);
        update(2*node+1, mid+1, e, l, r, val);
         stree[node]=merge(stree[2*node],stree[2*node+1]);
        return;
    }
    void update(int l, int r, T val){
        update(1, 0, n-1, l, r, val);
    }
     T query(int node, int b, int e, int l, int r){
        propagate(node, b, e);
        if(l > e or r < b)
            return identity;
        if(l<=b and r>=e)
            return stree[node];
        int mid = (b+e)>>1;
        T c1 = query(2*node, b, mid, l, r);
        T c2 = query(2*node+1, mid+1, e, l, r);
        return merge(c1,c2);
    }
    T query(int l, int r){return query(1, 0, n-1, l, r);}
};
 void solve(){
    int n, m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    segment_tree<ll> st(arr, [](ll a, ll b){return a+b;}, 0, 0);
    for(int i = 0; i < m; i++){
        int tp;
        cin>>tp;
        if(tp&1){
            int l, r, v;
            cin>>l>>r>>v;
            l--, r--;
            st.update(l, r, v);
        }
        else{
            int x;
            cin>>x;
            x--;
            cout<< st.query(x, x) << endl;
        }
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