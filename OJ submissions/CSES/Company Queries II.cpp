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
int n, q, l;
int ancs[N][20];
int level[N];
int lca(int x, int y) {
    // let x be the deeper node
    if (level[x] < level[y]) {
        swap(x, y);
    }
    // lifting x to the same level of y
    for (int i = l; i >= 0; i--) {
        if (level[y] + (1 << i) <= level[x]) {
            x = ancs[x][i];
        }
    }
    if (x == y)
        return x;
    // finding the node whose direct ancs./ parent is the lca of x and y
    for (int i = l; i >= 0; i--) {
        if (ancs[x][i] != ancs[y][i]) {
            x = ancs[x][i];
            y = ancs[y][i];
        }
    }
    return ancs[x][0];
}
void solve() {
    cin >> n >> q;
    l = ceil(log2(n));
    for (int i = 2; i <= n; i++) {
        cin >> ancs[i][0];
    }
    for (int i = 1; i <= l; i++) {
        for (int node = 1; node <= n; node++) {
            ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
        }
    }
    for (int i = 2; i <= n; i++) {
        level[i] = level[ancs[i][0]] + 1;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
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