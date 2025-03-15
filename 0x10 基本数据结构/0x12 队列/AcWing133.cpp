#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010, M = 7000010, INF = 0x3f3f3f3f;
int n, m, q, u, v, t, delta;
int q1[N], q2[M], q3[M]; // q1存原始长度（从大到小）；q2,q3分别存切除的左/右半部分
int hh1, hh2, hh3, tt1, tt2 = -1, tt3 = -1; // 队列头hh，队列尾tt

int max3() {
  int x = -INF;
  if (hh1 <= tt1) x = max(x, q1[hh1]);
  if (hh2 <= tt2) x = max(x, q2[hh2]);
  if (hh3 <= tt2) x = max(x, q3[hh3]);
  if (hh1<=tt1 && x==q1[hh1]) hh1++;
  else if (hh2<=tt2 && x==q2[hh2]) hh2++;
  else hh3++;
  return x;
}

int main() {
  cin >> n >> m >> q >> u >> v >> t;
  for (int i=0; i<n; i++) cin >> q1[i];
  sort(q1, q1+n, [](auto a, auto b) { return a > b; });
  tt1 = n-1;
  for (int i=1; i<=m; i++) {
    int x = max3();
    x += delta;
    int left = x * 1ll * u/v; // 乘的时候可能爆long long
    int right = x - left;
    if (i % t == 0) printf("%d ", x);
    delta += q;
    // 可证明：从q1中取出的数是单调递减的，新产生的两类数值也分别随时间单调递减
    q2[++tt2] = left - delta;
    q3[++tt3] = right - delta;
  }
  puts("");
  for (int i=1; i<=n+m; i++) {
    int x = max3();
    if (i % t == 0) printf("%d ", x+delta);
  }
  puts("");
  return 0;
}