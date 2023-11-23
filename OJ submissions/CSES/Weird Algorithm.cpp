#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void solve() {
   long long n;
   cin >> n;
   cout << n << " ";
   while (n > 1) {
      if (n % 2 == 1) {
         n = 3 * n + 1;
      }
      else n /= 2;
      cout << n << " ";
   }
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}