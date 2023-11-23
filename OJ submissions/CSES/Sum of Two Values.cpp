#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define read(v) for(auto& _:v) cin>>_
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const int mod = 1e9 + 7;
const int N = 1e7;
void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].pb(i + 1);
    }
    sort(all(arr));
    int l = 0, r = n - 1;
    while (l < r) {
        if (arr[l] + arr[r] == s) {
            if (arr[l] == arr[r]) {
                cout << mp[arr[l]][0] << ' ' << mp[arr[r]][1] << endl;
                return;
            }
            else {
                cout << mp[arr[l]][0] << " " << mp[arr[r]][0] << endl;
                return;
            }
        }
        else if (arr[l] + arr[r] > s) {
            r--;
        }
        else
            l++;
    }
    cout << "IMPOSSIBLE\n";
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
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}