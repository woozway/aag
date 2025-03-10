#include <cstdio>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const int N = 60005;
int n, pows[2*N], p[2*N], tot = 0;
bool v[2*N];
// 获取n!中因子p的个数=n/p + n/p^2 + n/p^3 + ...
int fac(int n, int p) {
  int cnt = 0;
  while (n) {
    cnt += n/p;
    n /= p;
  }
  return cnt;
}
// 高精度乘法+压位（将大数分成多部分，每部分最多包含8位）
void gj(vector<ll> &a, int b) {
  int c = 0;
  for (int i=0; i<a.size(); i++) {
    a[i] = a[i]*b + c;
    c = a[i]/100000000;
    a[i] %= 100000000;
  }
  while (c) { // 最高位可能还有进位
    a.push_back(c % 100000000);
    c /= 100000000;
  }
}
// 求卡特兰数：comb(2n, n)/(n+1)=(2n)! / (n! * (n+1)!)
int main() {
  cin >> n;
  // 筛出1-2n中的质数，T=O(nlgn)
  for (int i=2; i<=2*n; i++)
    if (!v[i]) {
      p[tot++] = i;
      for (int j=i*2; j<=2*n; j+=i) v[j] = 1;
    }
  // 计算答案中每一个质因子的个数
  for (int i=0; i<tot; i++)
    pows[p[i]] = fac(n*2, p[i]) - fac(n, p[i]) - fac(n+1, p[i]);
  vector<ll> ans;
  ans.push_back(1);
  for (int i=0; i<tot; i++)
    for (int j=0; j<pows[p[i]]; j++)
      gj(ans, p[i]);
  printf("%lld", ans.back()); // 高精度第一个数不需要补零
  for (int i=ans.size()-2; i>=0; i--) printf("%08lld", ans[i]);
  return 0;
}