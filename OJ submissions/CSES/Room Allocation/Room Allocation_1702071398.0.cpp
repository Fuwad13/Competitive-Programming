#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
struct person {
    int arv, dep, idx;
    bool operator<(const person &other) {
        // if(dep==other.dep)
        //     return arv<other.arv;
        // return dep<other.dep;
        if (arv == other.arv)
            return dep < other.dep;
        return arv < other.arv;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<person> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].arv >> v[i].dep;
        v[i].idx = i;
    }
    sort(all(v));
    int cur = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            ans[v[i].idx] = cur;
            q.push({v[i].dep, cur});
        } else {
            auto [d, id] = q.top();
            if (v[i].arv > d) {
                ans[v[i].idx] = id;
                q.pop();
                q.push({v[i].dep, id});
            } else {
                cur++;
                ans[v[i].idx] = cur;
                q.push({v[i].dep, cur});
            }
        }
    }
    cout << cur << "\n";
    for (auto x : ans)
        cout << x << " ";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}