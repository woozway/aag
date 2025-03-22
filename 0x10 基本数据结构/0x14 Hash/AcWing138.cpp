#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000010;
char s[N];
// 设f[i]表示前缀子串s[1~i]的Hash值，有f[i] = f[i-1]*P + (S[i]-"a"+1)
// 任意子串区间[l,r]的Hash值为：f[r] - f[l-1]*131^(r-l+1)
// 这里取P=131, p[i]表示P^i
unsigned long long f[N], p[N];
int main() {
  scanf("%s", s+1);
  int n, m;
  n = strlen(s+1);
  cin >> m;
  p[0] = 1; // 131^0
  for (int i=1; i<=n; i++) {
    f[i] = f[i-1]*131 + (s[i]-'a'+1); // hash of 1~i
    p[i] = p[i-1]*131; // 131^i
  }
  while (m--) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    // 如果 hash of l1~r1 == hash of l2~r2
    if (f[r1] - f[l1-1]*p[r1-l1+1] == f[r2] - f[l2-1]*p[r2-l2+1])
      puts("Yes");
    else
      puts("No");
  }
}