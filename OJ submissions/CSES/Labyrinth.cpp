#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
template<class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl "\n"
#define pb push_back
#define write(v) for(auto& _:v) cout<<_<<' ';cout<<'\n'
#define all(v) (v).begin(), (v).end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9 + 7;
const int N = 1e7;
int dx[] {1, -1, 0, 0};
int dy[] {0, 0, 1, -1};
void solve() {
    int n, m;
    cin >> n >> m;
    pii A, B;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                A = {i, j};
            if (grid[i][j] == 'B')
                B = {i, j};
        }
    }
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
    map<pii, pii> par;
    par[A] = {0, 0};
    queue<pii> q;
    q.push(A);
    dist[A.first][A.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 and nx <= n and ny >= 1 and ny <= m) {
                if (dist[nx][ny] == -1 and grid[nx][ny] != '#') {
                    par[ {nx, ny}] = {x, y};
                    dist[nx][ny] = 1 + dist[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }
    if (dist[B.first][B.second] == -1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<char> ans;
    pii prev = B;
    pii cur = par[B];
    while (cur != par[A]) {
        auto [x1, y1] = prev;
        auto [x2, y2] = cur;
        if (x1 == x2) {
            if (y2 > y1)
                ans.pb('L');
            else
                ans.pb('R');
        }
        else {
            if (x2 > x1)
                ans.pb('U');
            else
                ans.pb('D');
        }
        prev = cur;
        cur = par[cur];
    }
    cout << ans.size() << endl;
    reverse(all(ans));
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
}
//#define ONLINE_JUDGE
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " <<
         std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count()
         << " seconds" << endl;
    return 0;
}