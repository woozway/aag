#include <iostream>
using namespace std;
const int N = 200010;
int nxt[N], cnt[N];
char a[N], b[N];
int n, m, q;
// 转化为有向无环图DAG
int main() {
  cin >> n >> m >> q;
  scanf("%s", a+1); // A[1~n]保存A串
  scanf("%s", b+1); // B[1~n]保存B串
  // 对B串自匹配，求next数组
  for (int i=2, j=0; i<=m; i++) {
    while (j>0 && b[i]!=b[j+1]) j = nxt[j];
    if (b[i] == b[j+1]) j++;
    nxt[i] = j;
  }
  // cnt[j]：A中以i为结尾的子串中和B匹配的最大长度为j
  for (int i=1, j=0; i<=n; i++) { // A串与B串进行模式匹配
    while (j>0 && a[i]!=b[j+1]) j = nxt[j];
    if (a[i] == b[j+1]) j++;
    cnt[j]++;
  }
  for (int i=m; i; i--) cnt[nxt[i]] += cnt[i];
  // cnt[x]++了多少次，cnt[next[x]]++也就要相应执行多少次
  // 计算完毕后cnt[x]保存的是匹配长度>=x的位置个数
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", cnt[x] - cnt[x+1]);
  }
  return 0;
}