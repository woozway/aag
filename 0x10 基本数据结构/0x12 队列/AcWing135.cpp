#include <iostream>
#define ll long long
using namespace std;
const int N = 300006;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, q[N];
ll s[N], ans = -INF;

int main() {
  cin >> n >> m;
  s[0] = 0;
  for (int i=1; i<=n; i++) {
    cin >> s[i];
    s[i] += s[i-1];
  }
  int l = 1, r = 1;
  q[1] = 0; // q队列维护前m个数的下标集合，刚开始只有下标0
  for (int i=1; i<=n; i++) {
    while (l<=r && q[l]<i-m) l++; // 把m范围外没用的元素删除
    ans = max(ans, s[i] - s[q[l]]); // 此时q队列有序（递增）
    while (l<=r && s[q[r]]>=s[i]) r--; // O(1)时间找最值
    q[++r] = i; // 新元素入队
  }
  cout << ans << endl;
  return 0;
}