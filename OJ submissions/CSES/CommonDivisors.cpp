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
const int N = 1e6;
 
int divcnt[N+5]; 
void solve(){
    int n;
    cin>>n;
    int mx = -1;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        mx = max(mx, x);
        for(int j = 1; j*j <= x; j++){
            if(x%j==0){
                divcnt[j]++;
                if(x/j != j){
                    divcnt[x/j]++;
                }
            }
        }
 
    }
    for(int i = mx; i >=1; i--){
        if(divcnt[i]>1){
            cout << i << endl;
            break;
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