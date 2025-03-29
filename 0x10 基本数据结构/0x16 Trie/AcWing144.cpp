#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 100006;
int n, d[N], trie[N*33][2], tot;
int head[N], ver[N*2], edge[N*2], nxt[N*2];
bool v[N];

void dfs(int x) {
  for (int i=head[x]; i; i=nxt[i]) {
    int y = ver[i], z = edge[i];
    if (v[y]) continue;
    v[y] = 1;
    d[y] = d[x] ^ z;
    dfs(y);
  }
}
// 邻接表加入有向边x->y，权值z
void add(int x, int y, int z) {
  ver[++tot] = y, edge[tot] = z;
  nxt[tot] = head[x], head[x] = tot;
}
// 设d[x]表示根节点到x到路径上所有边权的xor值，则：
//   d[x] = d[father(x)] xor weight(x, father(x))
// 问题转化为：从d[1]~d[N]这N个数中选出两个，xor的结果最大，即AcWing143
void The_xor_longest_Path() {
  memset(d, 0, sizeof(d));
  memset(trie, 0, sizeof(trie));
  memset(v, 0, sizeof(v));
  memset(head, 0, sizeof(head));
  v[0] = 1;
  tot = 1;
  for (int i=1; i<n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    add(u, v, w); // 父到子路径
    add(v, u, w); // 子到父路径
  }
  dfs(0); // 先求出从根节点0出发，所有的d[x]
  int ans = 0;
  for (int i=0; i<n; i++) {
    int p = 1;
    for (int j=31; j>=0; j--) {
      int k = (d[i] >> j) & 1;
      if (!trie[p][k]) trie[p][k] = ++tot;
      p = trie[p][k];
    }
    p = 1;
    if (i) {
      int w = 0;
      for (int j=31; j>=0; j--) {
        int k = (d[i] >> j) & 1;
        if (trie[p][k^1]) {
          w = (w << 1) + (k ^ 1);
          p = trie[p][k^1];
        } else {
          w = (w << 1) + k;
          p = trie[p][k];
        }
      }
      ans = max(ans, w ^ d[i]);
    }
  }
  cout << ans << endl;
}

int main() {
  while (cin >> n) The_xor_longest_Path();
  return 0;
}