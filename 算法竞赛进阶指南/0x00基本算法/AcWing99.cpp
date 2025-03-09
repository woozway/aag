#include <iostream>
#include <cstring>
using namespace std;
const int N = 5006;
// 这里求前缀和时把一个点(x,y)看成一个格子，可认为目标位于格子中心
int n, r, s[N][N];

int main() {
  memset(s, 0, sizeof(s));
  cin >> n >> r;
  while (n--) {
    int x, y, w;
    cin >> x >> y >> w;
    s[x][y] += w;
  }
  // s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]
  // 内存限制严格，省略a数组，读入时直接向s中累加
  for (int i=0; i<=5000; i++)
    for (int j=0; j<=5000; j++)
      if (!i && !j) continue;
      else if (!i) s[i][j] += s[i][j-1];
      else if (!j) s[i][j] += s[i-1][j];
      else s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
  // 特判，如果炸弹范围很大，所有目标都会被摧毁
  if (r > 5000) {
    cout << s[5000][5000];
    return 0;
  }
  // s[i][j] = s[i-r][j] + s[i][j-r] - s[i-r][j-r] + sum(a[x][y])
  // 这里求的是sum(a[x][y)]，x从i-r+1到i，y从j-r+1到j，长度都是r
  // 这里i和j都从r-1开始，因为(r-1)-0+1=r；当i==r-1 && j==r-1时，
  // 求的是最左上角边长为r的正方形爆炸区域摧毁的总价值
  int ans = 0;
  for (int i=r-1; i<=5000; i++)
    for (int j=r-1; j<=5000; j++)
      if (i == r-1 && j == r-1) ans = max(ans, s[i][j]);
      else if (i == r-1) ans = max(ans, s[i][j] - s[i][j-r]);
      else if (j == r-1) ans = max(ans, s[i][j] - s[i-r][j]);
      else ans = max(ans, s[i][j] - s[i-r][j] - s[i][j-r] + s[i-r][j-r]);
  cout << ans;
  return 0;
}