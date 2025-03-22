#include <cstring>
#include <iostream>
#define ull unsigned long long
using namespace std;
const int N = 1000006, P = 13331;
char s[N];
// 设f1[i]表示前缀子串s[1~i]的Hash值，f2[i]表示前缀子串s[len~i]的Hash值
ull f1[N], f2[N], p[N]; // p[i]表示13331^i

ull H1(int i, int j) {
  return (f1[j] - f1[i-1]*p[j-i+1]);
}

ull H2(int i, int j) {
  return (f2[i] - f2[j+1]*p[j-i+1]);
}

int main() {
  int id = 0;
  p[0] = 1;
  for (int i=1; i<N; i++) p[i] = p[i-1] * P;
  while (scanf("%s", s+1) && !(s[1]=='E' && s[2]=='N' && s[3]=='D')) {
    int ans = 0, len = strlen(s+1);
    f1[0] = 0, f2[len+1] = 0;
    for (int i=1; i<=len; i++) f1[i] = f1[i-1]*P + s[i]; // 正序预处理
    for (int i=len; i; i--) f2[i] = f2[i+1]*P + s[i]; // 倒序预处理
    for (int i=1; i<=len; i++) {
      // l和r分别表示回文串可能的最短/长半径。r取往左和往右能取到最远长度中的较小值
      int l = 0, r = min(i-1, len-i);
      while (l < r) { // 二分找以i为中心的奇数回文串最长半径p
        int mid = (l + r + 1) >> 1;
        if (H1(i-mid, i) == H2(i, i+mid)) l = mid;
        else r = mid - 1;
      }
      ans = max(l*2 + 1, ans);
      l = 0, r = min(i-1, len-i+1);
      while (l < r) { // 二分找以i-1和i之间夹缝为中心偶数回文串最长半径q
        int mid = (l + r + 1) >> 1;
        if (H1(i-mid, i-1) == H2(i, i+mid-1)) l = mid;
        else r = mid - 1;
      }
      ans = max(l*2, ans);
    }
    printf("Case %d: %d\n", ++id, ans);
  }
  return 0;
}