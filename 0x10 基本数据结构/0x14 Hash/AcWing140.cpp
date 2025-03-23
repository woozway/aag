#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 300010;
unsigned long long f[N], p[N]; // hash
int sa[N], height[N], n;
char s[N];

unsigned long long H(int l, int r) {
  return f[r] - f[l-1]*p[r-l+1];
}

// 最长公共前缀，二分+Hash
int lcp(int x, int y) {
  int l = 0, r = min(n-x+1, n-y+1);
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (H(x, x+mid-1) == H(y, y+mid-1)) l = mid; else r = mid - 1;
  }
  return l; 
}

// 比较s[x~n]和s[y~n]的大小
bool cmp(int x, int y) {
  int l = lcp(x, y); 
  return s[x+l] < s[y+l];
}

void calc_height() {
  for (int i=2; i<=n; i++)
    height[i] = lcp(sa[i-1], sa[i]);
}

int main() {
  // 下标1~n，输出时再变回0~n-1 
  scanf("%s", s+1);
  n = strlen(s+1);
  p[0] = 1;
  for (int i=1; i<=n; i++) {
    sa[i] = i; // 后缀数组Suffix Array
    f[i] = f[i-1]*131 + (s[i]-'a'+1);
    p[i] = p[i-1] * 131; 
  } 
  sort(sa+1, sa+n+1, cmp);
  calc_height();
  for (int i=1; i<=n; i++) printf("%d ", sa[i]-1); puts("");
  for (int i=1; i<=n; i++) printf("%d ", height[i]); puts("");
  return 0;
}