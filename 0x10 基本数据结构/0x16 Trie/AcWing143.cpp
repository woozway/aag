#include <iostream>
using namespace std;
const int N = 100006 * 33;
int trie[N][2];

int main() {
  int n;
  cin >> n;
  int ans = 0, t = 1; // t就是tot
  for (int i=1; i<=n; i++) {
    int a;
    scanf("%d", &a);
    // 把每个整数看作长度为31的二进制01串（数值较小时前面补0）
    int p = 1;
    for (int j=31; j>=0; j--) {
      int k = (a >> j) & 1;
      if (!trie[p][k]) trie[p][k] = ++t;
      p = trie[p][k];
    }
    p = 1;
    if (i > 1) {
      int w = 0;
      for (int j=31; j>=0; j--) {
        int k = (a >> j) & 1;
        if (trie[p][k^1]) { // 如果与Ai的当前为相反的字符指针不空
          w = (w << 1) + (k ^ 1);
          p = trie[p][k^1];
        } else { // 反之，空
          w = (w << 1) + k;
          p = trie[p][k];
        }
      }
      ans = max(ans, w ^ a);
    }
  }
  cout << ans << endl;
  return 0;
}