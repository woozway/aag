#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1000006;
int n, a[N], s[N];
ll k = 0;
// 环形均分纸牌问题，s[i]取中位数时最优
int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
    k += a[i];
  }
  k /= n;
  for (int i=1; i<=n; i++) a[i] -= k;
  s[0] = 0;
  for (int i=1; i<=n; i++) s[i] = s[i-1] + a[i];
  sort(s+1, s+n+1);
  ll ans = 0;
  for (int i=1; i<=n/2; i++) ans += s[n+1-i] - s[i];
  cout << ans;
  return 0;
}