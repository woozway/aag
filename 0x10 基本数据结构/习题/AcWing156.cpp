#include <iostream>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
const int N = 1006, P = 131;
int m, n, a, b, q;
ull h[N][N], p[N*N]; // h中存储每一行的字符串哈希（二维）
char s[N];

ull H(ull f[], int l, int r) {
  return f[r] - f[l-1]*p[r-l+1];
}

int main() {
  cin >> m >> n >> a >> b;
  p[0] = 1;
  for (int i=1; i<=m*n; i++) p[i] = p[i-1] * P;
  for (int i=1; i<=m; i++) {
    scanf("%s", s+1);
    for (int j=1; j<=n; j++) h[i][j] = h[i][j-1]*P + s[j]-'0';
  }
  unordered_set<ull> us; // 计算mxn矩阵中每个axb小矩阵的哈希，插入set
  for (int j=b; j<=n; j++) {
    ull val = 0;
    int l = j-b+1, r = j;
    for (int i=1; i<=m; i++) {
      val = val*p[b] + H(h[i], l, r);
      if (i > a) val -= H(h[i-a], l, r) * p[a*b]; // tricky
      if (i >= a) us.insert(val);
    }
  }
  cin >> q;
  while (q--) {
    ull val = 0;
    for (int i=1; i<=a; i++) {
      scanf("%s", s+1);
      for (int j=1; j<=b; j++) val = val*P + s[j]-'0';
    }
    if (us.count(val)) puts("1");
    else puts("0");
  }
  return 0;
}