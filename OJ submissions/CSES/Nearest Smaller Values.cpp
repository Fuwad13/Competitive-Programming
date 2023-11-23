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
    int n;
    cin >> n;
    vector<int> arr(n);
    read(arr);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() and arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            cout << 0 << " ";
        }
        else {
            cout << st.top() + 1 << " ";
        }
        st.push(i);
    }
    cout << endl;
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