#include <iostream>
#include <cstring>
using namespace std;
const int N = 15;

int main() {
  int d[N], f[N]; // d[i]表示求解该i盘3塔问题的最小步数，f[i]是4塔

  d[0] = 0; // 3塔：n-1个盘子A->B，第n个盘子A->C，最后n-1个盘子B->C
  for (int i = 1; i <= 12; i ++ ) d[i] = d[i - 1] * 2 + 1;

  memset(f, 0x3f, sizeof f);
  f[0] = 0; // 4塔：j个盘子A->B，利用ACD三塔完成i-j个盘子A->D，最后B->D
  for (int i = 1; i <= 12; i ++ )
    for (int j = 0; j < i; j ++ )
      f[i] = min(f[i], f[j] * 2 + d[i - j]);

  for (int i = 1; i <= 12; i ++ ) cout << f[i] << endl;
  return 0;
}