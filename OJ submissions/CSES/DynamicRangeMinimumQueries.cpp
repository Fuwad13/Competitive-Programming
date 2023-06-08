#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;

const int mod = 1e9+7;

const int N = 2e5+5;

int arr[N], tree[N*4];

void build(int node, int b, int e){
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[node] = min(tree[left],tree[right]);
}

ll query(int node, int b, int e, int l, int r){
    if(l > e or r < b)
        return INT_MAX;
    if(l<=b and r>=e)
        return tree[node];
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)>>1;
    ll c1 = query(left, b, mid, l, r);
    ll c2 = query(right, mid+1, e, l, r);
    return min(c1,c2);
}

void update(int node, int b, int e, int ind, ll val){
    if(ind > e or ind < b)
        return;
    if(ind<=b and ind>=e){
        tree[node] = val;
        return;
    }
    int mid = (b+e)>>1;
    int left = 2*node;
    int right = left+1;
    update(left, b, mid, ind, val);
    update(right, mid+1, e, ind, val);
    tree[node] = min(tree[right],tree[left]);

}

void solve(){
    int n, q;
    cin>>n>>q;
    for(int i= 0; i < n; i++)
        cin>>arr[i];
    build(1, 0, n-1);
    while(q--){
        int u;
        cin>>u;
        if(u==1){
            int k, v;
            cin>>k>>v;
            update(1, 0, n-1, k-1, v);
        }
        else{
            int a, b;
            cin>>a>>b;
            cout << query(1, 0, n-1, a-1, b-1) <<endl;
        }
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