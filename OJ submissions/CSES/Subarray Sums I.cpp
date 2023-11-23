#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 1e7;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] =  a[i] + (i ? p[i - 1] : 0);
    }
    int l, r;
    l = r = 0;
    int cnt = 0;
    auto calc = [&](int x, int y) {
        ll ret = p[y] - (x ? p[x - 1] : 0);
        return ret;
    };
    while (r < n) {
        if (l > r)
            r = l;
        ll temp = calc(l, r);
        if (temp == x) {
            cnt++;
            r++;
        }
        else {
            if (temp < x)
                r++;
            else
                l++;
        }
    }
    cout << cnt << endl;
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