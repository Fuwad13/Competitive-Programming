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
    void set(int node, int b, int e, int ind, T val){
        if(ind > e or ind < b)
            return;
        if(ind<=b and ind>=e){
            stree[node] = val; 
            return;
        }
        int mid = (b+e)>>1;
        set(2*node, b, mid, ind, val);
        set(2*node+1, mid+1, e, ind, val);
        stree[node] = merge(stree[2*node+1],stree[2*node]);
        }
    void set(int ind, T val){set(1, 0, n-1, ind, val);}
     void update(int node, int b, int e, int ind, T val){
        if(ind > e or ind < b)
            return;
        if(ind<=b and ind>=e){
            stree[node] = merge(stree[node], val);
            return;
        }
        int mid = (b+e)>>1;
        update(2*node, b, mid, ind, val);
        update(2*node+1, mid+1, e, ind, val);
        stree[node] = merge(stree[2*node+1],stree[2*node]);
    }
    void update(int ind, T val){update(1, 0, n-1, ind, val);}
     T query(int node, int b, int e, int l, int r){
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
     T find(int node, int b, int e, int x){
        if(b==e)
            return b;
        int mid = (b+e)>>1;
        if(stree[2*node]>=x)
            return find(2*node, b, mid, x);
        else
            return find(2*node+1, mid+1, e, x - stree[2*node]);
    }
     T find(int x){
        return find(1, 0, n-1, x);
    }
 };
 void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto&x:v)
        cin>>x;
    vector<int> present(n, 1);
    segment_tree<int> st(present, [](int a, int b){return a+b;}, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        x = st.find(x);
        cout << v[x] << " ";
        st.set(x, 0);
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