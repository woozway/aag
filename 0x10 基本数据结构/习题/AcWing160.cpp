#include <iostream>
using namespace std;
const int N = 200010;
int f[N], nxt[N], cnt[N];
char a[N], b[N];
int n, m, q;
// 转化为有向无环图DAG
int main() {
  cin >> n >> m >> q;
  scanf("%s", a+1); // A[1~n]保存A串
  scanf("%s", b+1); // B[1~n]保存B串
  // 对B串自匹配，求next数组
  for (int i=2, j=0; i<=m; i++) {
    while (j>0 && b[j+1]!=b[i]) j = nxt[j];
    if (b[j+1] == b[i]) j++;
    nxt[i] = j;
  }
  // f[i]表示“A中以i结尾的子串”与“B的前缀”能够匹配的最大长度
  for (int i=1, j=0; i<=n; i++) { // A串与B串进行模式匹配
    while (j>0 && (j==m || a[i]!=b[j+1])) j = nxt[j];
    if (a[i] == b[j+1]) j++;
    f[i] = j;
  }
  // 计算完毕后cnt[x]保存的是匹配长度>=x的位置个数
  for (int i=1; i<=n; i++) cnt[f[i]]++;
  for (int i=n; i; i--) cnt[nxt[i]] += cnt[i];
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", cnt[x] - cnt[x+1]);
  }
  return 0;
}