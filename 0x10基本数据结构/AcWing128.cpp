#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1000006, INF = 0x3f3f3f3f;
int q, st1[N], st2[N], s[N], f[N]; // s是序列的前缀和，f维护前缀和的最大值

void Editor() {
  int t1 = 0, t2 = 0;
  while (q--) {
    char c[2];
    scanf("%s", c);
    switch (c[0]) {
      case 'I':
        scanf("%d", &st1[++t1]);
        s[t1] = s[t1-1] + st1[t1];
        f[t1] = max(f[t1-1], s[t1]);
        continue;
      case 'D':
        if (t1) t1--;
        continue;
      case 'L':
        if (t1) st2[++t2] = st1[t1--];
        continue;
      case 'R':
        if (!t2) continue;
        st1[++t1] = st2[t2--];
        s[t1] = s[t1-1] + st1[t1];
        f[t1] = max(f[t1-1], s[t1]);
        continue;
      case 'Q':
        int k;
        scanf("%d", &k);
        printf("%d\n", f[k]);
    }
  }
}

int main() {
  s[0] = 0;
  f[0] = -INF;
  cin >> q;
  Editor();
  return 0;
}