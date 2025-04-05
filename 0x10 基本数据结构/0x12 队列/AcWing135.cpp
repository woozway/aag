#include <iostream>
#define ll long long
using namespace std;
const int N = 300006;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, q[N];
ll s[N], ans = -INF;

int main() {
  cin >> n >> m;
  s[0] = 0; // 前缀和s[j]-s[i-1]表示a[i~j]的和
  for (int i=1; i<=n; i++) {
    cin >> s[i];
    s[i] += s[i-1];
  }
  int l = 0, r = 0; // 初始化队列q时，默认加入第一个元素s[0]
  q[l] = 0; // q队列维护m+1个数的下标集合，因为前缀和的性质要多+1
  for (int i=1; i<=n; i++) { // l<=r表示队列q非空
    while (l<=r && q[l]<=i-m-1) l++;
    // 注意这里要在新下标i入队之前计算ans，因为入队前后q[l]可能改变
    if (l <= r) ans = max(ans, s[i] - s[q[l]]); // 此时q队列单调
    while (l<=r && s[q[r]]>=s[i]) r--; // O(1)时间找最值
    q[++r] = i; // 新元素入队
  }
  cout << ans << endl;
  return 0;
}