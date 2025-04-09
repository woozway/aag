#include <iostream>
#include <cstring>
using namespace std;
const int N = 10010, M = 80;
int n, m, nxt[N];
char s[N][M];
bool st[M];
// 因为覆盖时最后一个可以多余，所以并不是简单求每个字符串的最小循环节
int main() {
  cin >> n >> m;
  memset(st, 1, sizeof st); // st[i]==1说明长度为i的循环节可以覆盖
  for (int i=1; i<=n; i++) { // 暴力判断每个字符串中宽度j的循环节是否可行
    scanf("%s", s[i]);
    for (int j=1; j<=m; j++)
      if (st[j])
        for (int k=j; k<m; k+=j) {
          for (int u=0; u<j && k+u<m; u++)
            if (s[i][u] != s[i][k+u]) {
              st[j] = 0;
              break;
            }
          if (!st[j]) break;
        }
  }
  int width; // 选择最小的width，则一定可以得到最小的height
  for (int i=1; i<=m; i++) // 找到最小的，可以不完美覆盖每行的循环节长度
    if (st[i]) {
      width = i;
      break;
    }
  for (int i=1; i<=n; i++) s[i][width] = 0; // '\0'
  for (int i=2, j=0; i<=n; i++) { // 把每行看作一个字母，对列做kmp算法
    while (j>0 && strcmp(s[i], s[j+1])) j = nxt[j];
    if (!strcmp(s[i], s[j+1])) j++;
    nxt[i] = j;
  }
  int height = n - nxt[n];
  cout << width*height << endl;
  return 0;
}