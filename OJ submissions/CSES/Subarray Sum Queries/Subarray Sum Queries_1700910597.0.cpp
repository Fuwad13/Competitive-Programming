#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define read(v)                                                                \
    for (auto &_ : v)                                                          \
    cin >> _
#define write(v)                                                               \
    for (auto &_ : v)                                                          \
        cout << _ << ' ';                                                      \
    cout << '\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
struct node {
    ll raw, segMax, pref, suf, sum;
};
ll arr[N];
node segTree[4 * N];
void build(int node, int b, int e) {
    if (b == e) {
        segTree[node].raw = arr[b];
        segTree[node].sum = arr[b];
        ll temp = max(arr[b], 0LL);
        segTree[node].pref = temp;
        segTree[node].suf = temp;
        segTree[node].segMax = temp;
        return;
    }
    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    segTree[node].sum = segTree[left].sum + segTree[right].sum;
    segTree[node].pref =
        max(segTree[left].pref, segTree[left].sum + segTree[right].pref);
    segTree[node].suf =
        max(segTree[right].suf, segTree[right].sum + segTree[left].suf);
    segTree[node].segMax =
        max(segTree[left].segMax, max(segTree[right].segMax,
                                      segTree[left].suf + segTree[right].pref));
}
void update(int node, int ind, ll val, int b, int e) {
    if (ind > e or ind < b)
        return;
    if (ind <= b and ind >= e) {
        segTree[node].raw = val;
        segTree[node].sum = val;
        ll temp = max(val, 0LL);
        segTree[node].pref = temp;
        segTree[node].suf = temp;
        segTree[node].segMax = temp;
        return;
    }
    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    update(left, ind, val, b, mid);
    update(right, ind, val, mid + 1, e);
    segTree[node].sum = segTree[left].sum + segTree[right].sum;
    segTree[node].pref =
        max(segTree[left].pref, segTree[left].sum + segTree[right].pref);
    segTree[node].suf =
        max(segTree[right].suf, segTree[right].sum + segTree[left].suf);
    segTree[node].segMax =
        max(segTree[left].segMax, max(segTree[right].segMax,
                                      segTree[left].suf + segTree[right].pref));
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // for(int i=0; i < n; i++)
    //  cout<<arr[i] << " ";
    // cout << endl;
    build(1, 0, n - 1);
    // for(int i = 1; i <=4*n; i++){
    //  cout << "node " << i << " >> " <<  segTree[i].raw << " " <<
    //  segTree[i].segMax << " " << segTree[i].pref << " " << segTree[i].suf <<
    //  ' ' << segTree[i].sum << endl;
    // }
    // cout << segTree[1].segMax << endl;
    for (int i = 0; i < m; i++) {
        int ind;
        ll val;
        cin >> ind >> val;
        ind--;
        update(1, ind, val, 0, n - 1);
        cout << segTree[1].segMax << endl;
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}