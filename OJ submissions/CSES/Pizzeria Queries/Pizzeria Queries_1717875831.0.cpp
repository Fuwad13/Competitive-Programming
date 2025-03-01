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
    vector<ll> p(n), up(n), down(n);
    for(int i = 0; i < n; ++i){
        cin>>p[i];
        up[i] = p[i] + i;
        down[i] = p[i] - i;
    }
    segment_tree<ll> stup(up, [](ll a, ll b){return min(a,b);}, oo);
    segment_tree<ll> stdown(down, [](ll a, ll b){return min(a,b);}, oo);
    for(int i = 0; i< q; i++){
        int tp;
        cin>>tp;
        if(tp&1){
            ll k, x;
            cin>>k>>x;
            k--;
            stup.set(k, x+k);
            stdown.set(k, x-k);
        }
        else{
            ll k;
            cin>>k;
            k--;
            ll ans = min(stdown.query(0, k) + k, stup.query(k, n-1) - k);
            cout << ans << "\n";
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