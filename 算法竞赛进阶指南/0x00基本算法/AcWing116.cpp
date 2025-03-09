#include <iostream>
#include <cstring>
using namespace std;
char s[4][4];
bool a[4][4], c[4][4];
int p[37];

int lowbit(int x) {
  return x & -x;
}

int num(int x) { // 计算出x中有几个1，这里是计算矩阵变成全1需要花几步
  int cnt = 0;
  while (x) {
    cnt++;
    x -= lowbit(x);
  }
  return cnt;
}

void dj(int x, int y) { // 对x,y所在的行与列进行取反操作
  for (int i=0; i<4; i++) {
    c[x][i] ^= 1;
    c[i][y] ^= 1;
  }
  c[x][y] ^= 1; // x,y位置上取反了两次，要减一次
}

int pd(int x) { // x的二进制表示哪些位置上的开关需要取反
  memcpy(c, a, sizeof(c));
  while (x) {
    int k = lowbit(x)%37;
    dj(p[k]/4, p[k]%4); // 这里p[2^k % 37]把2^k映射到k，这里即[0,15]
    x -= lowbit(x);
  }
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      if (!c[i][j]) return 0;
  return 1;
}

int main() {
  for (int i=0; i<4; i++) cin >> s[i];
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      a[i][j] = (s[i][j] == '-'); // '-'处为1，'+'处为0
  int ans = 17, x; // x表示最后的计算步骤
  // k在[0,35]时，(2^k % 37)互不相等，且恰好取遍1-36
  for (int i=0; i<16; i++) p[(1<<i) % 37] = i; // 将2^i映射到i
  for (int i=0; i<(1<<16); i++) {
    int n = num(i);
    if (n<ans && pd(i)) { // 如果当前的方案步骤书更少且最后矩阵可以全1
      ans = n;
      x = i;
    }
  }
  cout << ans << endl;
  while (x) {
    int k = lowbit(x) % 37;
    cout << p[k]/4+1 << " " << p[k]%4+1 << endl;
    x -= lowbit(x);
  }
  return 0;
}