#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void solve() {
    int n ;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n - 1 ; i++) {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i] == 0) {
            cout << i << '\n';
            break;
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}