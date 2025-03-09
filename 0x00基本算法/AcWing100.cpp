#include <iostream>
#define ll long long
using namespace std;
const int N = 100006;
int a[N], b[N]; // b是a上的差分数列，问题转化为把b2,..,bn变全0

int main() {
  int n;
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  b[n+1] = 0, b[1] = a[1];
  for (int i=2; i<=n; i++) b[i] = a[i] - a[i-1];
  // 这里因为b[i]可能是0x7fffffff，两个数相加会溢出，所以用ll
  ll p = 0, q = 0;
  for (int i=2; i<=n; i++)
    if (b[i] > 0) p += b[i];
    else if (b[i] < 0) q -= b[i];
  cout << max(p, q) << endl << abs(p - q) + 1;
  return 0;
}