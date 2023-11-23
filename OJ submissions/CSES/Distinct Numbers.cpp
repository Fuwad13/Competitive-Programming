#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    int cnt = 0;
    for (int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        if (m[x])
            continue;
        cnt++;
        m[x]++;
    }
    cout << cnt << endl;
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
    while (t--) solve();
    return 0;
}