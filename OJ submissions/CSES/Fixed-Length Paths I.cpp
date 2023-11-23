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
const int N = 2e5 + 10;
int n, k;
vector<int> tree[N];
int cnt[N];
int subtree_size[N];
bool bad[N];
int mx;
ll ans = 0;
void calc_ssz(int v, int p) {
    subtree_size[v] = 1;
    for (auto c : tree[v]) {
        if (!bad[c] and c != p) {
            calc_ssz(c, v);
            subtree_size[v] += subtree_size[c];
        }
    }
}
int get_centroid(int v, int p, int sz) {
    for (auto c : tree[v]) {
        if (!bad[c] and c != p and subtree_size[c] * 2 > sz)
            return get_centroid(c, v, sz);
    }
    return v;
}
void calc(int v, int p, bool flag, int depth) {
    if (depth > k)
        return;
    mx = max(mx, depth);
    if (flag)
        cnt[depth]++; // incrementing for calculation of next subtrees
    else
        ans += cnt[k - depth]; // calculation for the current subtree
    for (auto c : tree[v]) {
        if (c != p and !bad[c])
            calc(c, v, flag, depth + 1);
    }
}
void decompose(int v, int p) {
    calc_ssz(v, p);
    int cen = get_centroid(v, p, subtree_size[v]);
    bad[cen] = 1;
    mx = 0;
    for (auto c : tree[cen]) {
        if (!bad[c]) {
            calc(c, cen, false, 1); // calculating for this subtree
            calc(c, cen, true, 1); // updating cnt[] for upcoming subtrees calc.
        }
    }
    for (int i = 1; i <= mx; i++)
        cnt[i] = 0;
    for (auto c : tree[cen]) {
        if (!bad[c]) {
            decompose(c, cen);
        }
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    cnt[0] = 1;
    decompose(1, 0);
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