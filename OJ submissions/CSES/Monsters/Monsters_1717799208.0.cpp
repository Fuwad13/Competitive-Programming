#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
int dx[]{0, -1, 0, 1};
int dy[]{1, 0, -1, 0}; // R U L D
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dista(n, vector<int>(m, -1));
    auto distm = dista;
    auto par = dista;
    pair<int, int> me;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                me = {i, j};
            } else if (grid[i][j] == 'M') {
                q.push({i, j});
                distm[i][j] = 0;
            }
        }
    }
    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m) {
                if (grid[nr][nc] != '#' and distm[nr][nc] == -1) {
                    distm[nr][nc] = 1 + distm[r][c];
                    q.push({nr, nc});
                }
            }
        }
    }
    q.push(me);
    dista[me.first][me.second] = 0;
    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m) {
                if (grid[nr][nc] != '#' and dista[nr][nc] == -1) {
                    dista[nr][nc] = 1 + dista[r][c];
                    par[nr][nc] = i;
                    q.push({nr, nc});
                }
            }
        }
    }
    pair<int, int> boundary{-1, -1};
    for (int i = 0; i < n; i++) {
        if (i == 0 or i == n - 1) {
            for (int j = 0; j < m; j++) {
                if (dista[i][j] != -1 and
                    (distm[i][j] == -1 or dista[i][j] < distm[i][j])) {
                    boundary = {i, j};
                }
            }
        } else {
            if (dista[i][0] != -1 and
                (distm[i][0] == -1 or dista[i][0] < distm[i][0])) {
                boundary = {i, 0};
            }
            if (dista[i][m - 1] != -1 and
                (distm[i][m - 1] == -1 or dista[i][m - 1] < distm[i][m - 1])) {
                boundary = {i, m - 1};
            }
        }
    }
    if (boundary == pair{-1, -1}) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    stack<char> st;
    map<int, char> mp{{0, 'R'}, {1, 'U'}, {2, 'L'}, {3, 'D'}};
    while (par[boundary.first][boundary.second] != -1) {
        auto x = par[boundary.first][boundary.second];
        st.push(mp[x]);
        boundary = {boundary.first - dx[x], boundary.second - dy[x]};
    }
    cout << st.size() << "\n";
    while (st.size()) {
        cout << st.top();
        st.pop();
    }
    cout << '\n';
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