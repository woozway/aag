#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 500006;
int n, m, w;
// a是原始读入的n个数；c中有序保存当前[l,r]区间的数字
ll t, a[N], b[N], c[N];

void merge(int l, int mid, int r) {
  int i = l, j = mid+1;
  for (int k=l; k<=r; k++)
    if (j>r || (i<=mid && b[i]<=b[j])) c[k] = b[i++];
    else c[k] = b[j++];
}

ll f(int l, int r) { // 计算[l,r]区间的校验值
  if (r > n) r = n;
  int p = min(m, (r-l+1)>>1);
  for (int i=w+1; i<=r; i++) b[i] = a[i];
  sort(b+w+1, b+r+1); // 只对新增的长度部分排序
  merge(l, w, r); // 然后合并新旧两段
  ll num = 0;
  for (int i=0; i<p; i++) num += (c[r-i] - c[l+i])*(c[r-i] - c[l+i]);
  return num;
}

void Genius_ACM() {
  cin >> n >> m >> t;
  for (int i=1; i<=n; i++) cin >> a[i];
  int ans = 0, l = 1, r = 1;
  w = 1; // 全局变量，保存旧的一段的右端点
  b[1] = a[1];
  while (l <= n) {
    int p = 1;
    while (p) { // 倍增+二进制划分
      ll num = f(l, r + p);
      if (num <= t) {
        w = r = min(r + p, n);
        // 现在c中[l,w]是有序的，b中对应段也要复制该段，以便之后的merge
        for (int i=l; i<=r; i++) b[i] = c[i];
        // 试想当n==1的时候，没有这句break，会陷入死循环
        if (r == n) break;
        p <<= 1;
      } else {
        p >>= 1;
      }
    }
    ans++;
    l = r + 1;
  }
  cout << ans << endl;
}

int main() {
  int k;
  cin >> k;
  while (k--) Genius_ACM();
  return 0;
}