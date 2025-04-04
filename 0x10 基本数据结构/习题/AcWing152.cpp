#include <iostream>
using namespace std;
const int N = 1006;
char a[N][N];
int t, n, m, h[N], s[N], w[N];
// 单调栈ddz：参考AcWing131直方图中最大的矩形
int ddz(int k) {
  for (int i=1; i<=m; i++) // 预处理以每一行为底的不同高度矩形
    if (a[k][i] == 'F') h[i]++;
    else h[i] = 0;
  int ans = 0, p = 0;
  for (int i=1; i<=m+1; i++)
    if (h[i] > s[p])
      s[++p] = h[i], w[p] = 1;
    else {
      int width = 0;
      while (s[p] > h[i]) {
        width += w[p];
        ans = max(ans,  width * s[p--]);
      }
      s[++p] = h[i], w[p] = width + 1;
    }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      cin >> a[i][j];
  int ans = 0; // 遍历每一行，调用单调栈计算最大矩形面积
  for (int i=1; i<=n; i++) ans = max(ans, ddz(i));
  cout << 3 * ans << endl;
  return 0;
}