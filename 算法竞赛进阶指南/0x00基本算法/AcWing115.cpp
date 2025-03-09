#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1006;
// nxt[i]记录i节点的下个紧挨着的节点，lst[i]记录i集团中最后一个节点
int n, r, fa[N], nxt[N], lst[N], num[N];
// c[i]记录i集团的等效权值，d为c原始拷贝；tot[i]记录i集团总代价
double c[N], d[N], tot[N];
bool v[N]; // 用于记录i节点是否已被染色
// 不断在树中取等效权值最大的点p，与其父节点fa合并，合并前p与fa各自包含的
// 点的染色顺序是已知的，让p中第一个点排在fa中最后一个点之后紧接着被染色。
// 把这个顺序保存在p与fa合并以后的点上
void Color_a_Tree() {
  for (int i=1; i<=n; i++) {
    cin >> c[i];
    nxt[i] = i;
    lst[i] = i;
    num[i] = 1;
    tot[i] = c[i];
  }
  memcpy(d, c, sizeof(d)); // 保存原始权值，待得出染色顺序后计算总代价
  for (int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    fa[b] = a;
  }
  memset(v, 0, sizeof(v));
  // 找出权值最大的非根未染色节点，与其fa[p]合并
  for (int i=1; i<n; i++) { // n个点的树，合并n-1次即可
    int p;
    double k = 0;
    for (int j=1; j<=n; j++)
      if (j != r && !v[j] && c[j] > k) {
        k = c[j];
        p = j;
      }
    int f = fa[p];
    while (v[f]) fa[p] = f = fa[f]; // 找到还没被染色的父辈
    nxt[lst[f]] = p; // p是p集团中第一个节点
    lst[f] = lst[p]; // lst[p]是p集团中的最后一个
    num[f] += num[p];
    tot[f] += tot[p];
    c[f] = tot[f] / num[f];
    v[p] = 1;
  }
  int ans = 0;
  for (int i=1; i<=n; i++) {
    ans += i * d[r];
    r = nxt[r];
  }
  cout << ans;
}

int main() {
  cin >> n >> r;
  Color_a_Tree();
  return 0;
}