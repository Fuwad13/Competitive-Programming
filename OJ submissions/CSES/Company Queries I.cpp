#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
typedef pair<int, int> pii;
#define endl "\n"
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, q;
int ancs[N][20];
void solve() {
    cin >> n >> q;
    int l = ceil(log2(n));
    for (int i = 2; i <= n; i++) {
        cin >> ancs[i][0];
    }
    for (int i = 1; i <= l; i++) {
        for (int node = 1; node <= n; node++) {
            ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = l; i >= 0; i--) {
            if ((1 << i) <= k) {
                x = ancs[x][i];
                k -= (1 << i);
            }
        }
        cout << (x ? x : -1) << endl;
    }
}
#define ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}