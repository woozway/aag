#include <iostream>
#include <cstring>
using namespace std;
char a[2000010], b[2000010];
int n, ans;

int calc_min(char *s) { // 计算字符串的最小表示
  int i = 1, j = 2, k;
  while (i <= n && j <= n) {
    for (k=0; k<n && s[i+k]==s[j+k]; k++);
    if (k == n) break;
    if (s[i+k] > s[j+k]) i += k + 1;
    else j += k + 1;
    if (i == j) i++;
  }
  ans = min(i, j);
  s[ans + n] = '\0';
  return ans;
}

int main() {
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1);
  memcpy(a+n+1, a+1, n);
  memcpy(b+n+1, b+1, n);
  int x = calc_min(a), y = calc_min(b);
  if (strcmp(a + x, b + y)) puts("No");
  else {
    puts("Yes");
    puts(a + x);
  }
  return 0;
}