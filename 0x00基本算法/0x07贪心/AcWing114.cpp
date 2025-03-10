#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1006;
// k,ans,ans0中保存大数，lk,la,la0分别为其指针
int n, k[N*4], lk = 1, ans[N*4], la = 1, ans0[N*4], la0 = 1;
struct P {
  int a, b;
  bool operator < (const P x) const {
    return a*b < x.a*x.b;
  }
} p[N];
// k中保存i个大臣前面所有a所相乘的大数
void gj1(int x) {
  for (int i=1; i<=lk; i++) k[i] *= x;
  lk += 4;
  for (int i=1; i<=lk; i++) {
    k[i+1] += k[i]/10;
    k[i] %= 10;
  }
  while (!k[lk]) lk--;
}
// ans0中保存k中大数/x的值
void gj2(int x) {
  int w = 0;
  bool flag = true; // 因为la0最多只更新一次
  for (int i=lk; i; i--) {
    w = w*10 + k[i];
    ans0[i] = w/x;
    w %= x;
    if (ans0[i] && flag) {
      la0 = i;
      flag = false;
    }
  }
}
// 判断ans中所存的大数是否小于临时变量大数ans0，若是则更新
bool pd() {
  if (la != la0) return la < la0;
  for (int i=la; i; i--)
    if (ans[i] != ans0[i]) return ans[i] < ans0[i];
  return 0;
}

int main() {
  cin >> n;
  for (int i=0; i<=n; i++) cin >> p[i].a >> p[i].b;
  sort(p+1, p+n+1); // 逆序对=0即可结束本题，后续为大数处理环节
  memset(k, 0, sizeof(k));
  memset(ans, 0, sizeof(ans));
  memset(ans0, 0, sizeof(ans0));
  k[1] = 1;
  gj1(p[0].a);
  for (int i=1; i<=n; i++) {
    gj2(p[i].b);
    if (pd()) {
      memcpy(ans, ans0, sizeof(ans));
      la = la0;
    }
    gj1(p[i].a);
  }
  for (int i=la; i; i--) cout << ans[i];
  return 0;
}