#include <iostream>
using namespace std;
double a[100001], b[100001], s[100001];
int main() {
  int N, L;
  cin >> N >> L;
  for (int i=1; i<=N; i++) cin >> a[i];
  double eps = 1e-5; // 因为最后r*1000，保留k=3位小数,eps=10e-(k+2)
  double l = 1, r = 1e6;
  while (r - l > eps) { // 实数域上二分
    double mid = (l + r)/2;
    for (int i=1; i<=N; i++) b[i] = a[i] - mid;
    for (int i=1; i<=N; i++) s[i] = s[i-1] + b[i];
    double ans = -1e10;
    double min_val = 1e10;
    // 因为更新后的sum[i-L]可能<0，sum[i]-min_val可能变更大
    for (int i=L; i<=N; i++) {
      min_val = min(min_val, s[i-L]);
      ans = max(ans, s[i] - min_val);
    }
    if (ans >= 0) l = mid; else r = mid;
  }
  cout << int(r * 1000);
  return 0;
}