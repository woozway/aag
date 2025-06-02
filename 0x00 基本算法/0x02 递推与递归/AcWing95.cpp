#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
char g[10][10];
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

void flip(int x, int y) {
  for (int i = 0; i < 5; i ++ ) {
    int a = x + dx[i], b = y + dy[i];
    if (a >= 0 && a < 5 && b >= 0 && b < 5)
      g[a][b] = '0' + !(g[a][b] - '0');
  }
}

// 枚举第一行所有可能，假定前行不变，翻转下一行来改变上一行
// 递推n-1行到最后一行，若全1说明可行，否则不合法
int work() {
  int ans = INF;
  for (int k = 0; k < 1<<5; k ++ ) {
    int res = 0;
    char backup[10][10];
    memcpy(backup, g, sizeof g);

    for (int j = 0; j < 5; j ++ )
      if (k>>j & 1) { // !(k>>j & 1)也可以，对称的
        res ++ ;
        flip(0, j);
      }

    for (int i = 0; i < 4; i ++ )
      for (int j = 0; j < 5; j ++ )
        if (g[i][j] == '0') {
          res ++ ;
          flip(i + 1, j);
        }

    bool is_successful = true;
    for (int j = 0; j < 5; j ++ )
      if (g[4][j] == '0') {
        is_successful = false;
        break;
      }
    if (is_successful) ans = min(ans, res);

    memcpy(g, backup, sizeof g);
  }

  if (ans > 6) return -1;
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t -- ) {
    for (int i = 0; i < 5; i ++ ) cin >> g[i];
    cout << work() << endl;
  }
  return 0;
}