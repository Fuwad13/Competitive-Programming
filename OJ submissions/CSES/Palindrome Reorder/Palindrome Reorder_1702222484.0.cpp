#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
const ll oo = 1e17;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5;
void solve() {
    string s;
    cin >> s;
    vector<int> freq(26);
    for (auto c : s)
        freq[c - 'A']++;
    int cntodd = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] & 1)
            cntodd++;
    }
    if ((int)s.size() % 2 == 0) {
        if (cntodd) {
            cout << "NO SOLUTION";
            return;
        } else {
            vector<char> answer(s.size());
            int ind = 0;
            for (int i = 0; i < 26; i++) {
                while (freq[i]) {
                    freq[i] -= 2;
                    answer[ind] = answer[s.size() - 1 - ind] = 'A' + i;
                    ind++;
                }
            }
            for (auto c : answer)
                cout << c;
            return;
        }
    } else {
        if (cntodd == 1) {
            char mid;
            vector<char> answer(s.size());
            int ind = 0;
            for (int i = 0; i < 26; i++) {
                if (freq[i] & 1)
                    mid = i + 'A', freq[i]--;
                while (freq[i]) {
                    freq[i] -= 2;
                    answer[ind] = answer[s.size() - 1 - ind] = 'A' + i;
                    ind++;
                }
            }
            answer[answer.size() / 2] = mid;
            for (auto c : answer)
                cout << c;
            return;
        } else {
            cout << "NO SOLUTION";
            return;
        }
    }
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