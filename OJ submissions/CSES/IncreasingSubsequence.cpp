#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl

const int mod = 1e9+7;
const int N = 2e5+10;

void solve(){
    int n;
    cin>>n;
    vector<int> ans;
    int x;
    cin>>x;
    ans.pb(x);
    for(int i = 1; i <n; i++){
        
        cin>>x;
        int pos = lower_bound(all(ans), x) - ans.begin();
        if(pos==ans.size()) // when i can add an element to the sequence
            ans.pb(x);
        else
            ans[pos]=x;  // when i can't increase the lenght but can lower value at that positon of seq.

    }
    cout << ans.size() << endl;
    

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