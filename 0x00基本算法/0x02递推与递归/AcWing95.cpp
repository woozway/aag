#include <cstring>
#include <iostream>
using namespace std;
const int N = 6;
// a[i]用于存储每一行00111的十进制整数，aa[i]是运行时的拷贝
// s[i]存字符串"00111"，为方便计算下标都从1开始
int a[N], aa[N], ans;
char s[N];
// dj用于翻转01操作，(x,y)是5x5中的坐标，x是aa,a的横坐标，从1开始
// 因为移位操作<<的性质，所以y下标从0开始
void dj(int x, int y) {
  aa[x] ^= (1 << y);
  if (x != 1) aa[x-1] ^= (1 << y);
  if (x != 5) aa[x+1] ^= (1 << y);
  if (y != 0) aa[x] ^= (1 << (y-1));
  if (y != 4) aa[x] ^= (1 << (y+1));
}
// 参数p用于枚举第一行的全部点击情况，所以((p>>y) & 1)不取反也可以
void pd(int p) {
  int k = 0;
  memcpy(aa, a, sizeof(a));
  for (int y=0; y<5; y++)
    if (!((p>>y) & 1)) {
      dj(1, y);
      if (++k >= ans) return;  // 剪枝
    }
  // 这里x<5，因为最后只要第4行固定了，第5行就不能改了
  for (int x=1; x<5; x++)
    for (int y=0; y<5; y++)
      if (!((aa[x]>>y) & 1)) {
        dj(x+1, y);
        if (++k >= ans) return;
      }
  if (aa[5] == 31) ans = k;
}

void abc() {
  memset(a, 0, sizeof(a));
  for (int i=1; i<=5; i++) {
    cin >> (s+1);
    for (int j=1; j<=5; j++) a[i] = a[i]*2 + (s[j]-'0');
  }
  ans = 7;
  // 按照书上的思路，先考察第一行如何点击，枚举2^5次后固定第一行
  for (int p=0; p<(1<<5); p++) pd(p);
  cout << ((ans == 7) ? -1 : ans) << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) abc();
  return 0;
}