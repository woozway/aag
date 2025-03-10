#include <iostream>
using namespace std;
const int N = 100006;
int main() {
  int a[N], n, ans = 0;
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int i=1; i<n; i++) ans += max(a[i+1] - a[i], 0);
  cout << ans;
  return 0;
}