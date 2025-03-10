#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100006;
int n, a[N];

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  sort(a+1, a+n+1);
  ll ans = 0;
  // 假设货仓在中位数x，在x左右侧配对的a[i]和a[n-i+1]
  // (x-a[i]) + (a[n-i+1]-x) = a[n-i+1] - a[i]
  for (int i=1; i<=n/2; i++) ans += a[n-i+1] - a[i];
  cout << ans;
  return 0;
}