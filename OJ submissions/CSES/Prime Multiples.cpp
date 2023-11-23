#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const int mod = 1e9 + 7;
const int N = 1e7;
ll f(ll n, ll nn) {
    return n / nn;
}
void solve() {
    ll n;
    int k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> arr(k);
    read(arr);
    for (int i = 1; i < (1 << k); i++) {
        ll cur = n;
        int cnt = 0;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                cnt++;
                cur /= arr[j];
            }
        }
        if (cnt & 1) {
            ans += cur;
        }
        else {
            ans -= cur;
        }
    }
    cout << ans << endl;
}
//#define ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}