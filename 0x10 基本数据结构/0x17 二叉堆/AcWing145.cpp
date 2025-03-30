#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 10006;
int n;
pair<int, int> a[N]; // 每件商品的过期天数d和利润p
priority_queue<int> q; // c++中优先队列默认为大根堆

void Supermarket() {
  for (int i=1; i<=n; i++)
    scanf("%d %d", &a[i].second, &a[i].first);
  sort(a+1, a+n+1); // 按过期时间d排序
  // 贪心维护一个集合（小根堆）：
  //   1. 当集合大小 < a[i]的过期时间d，入队；
  //   2. 当=，检查是否可替换队中最小利润商品
  for (int i=1; i<=n; i++) {
    if (a[i].first==q.size() && -q.top()<a[i].second) {
      q.pop();
      q.push(-a[i].second);
      continue;
    }
    if (a[i].first > q.size()) q.push(-a[i].second);
  }
  int ans = 0;
  while (q.size()) {
    ans += q.top();
    q.pop();
  }
  cout << -ans << endl;
}

int main() {
  while (cin >> n) Supermarket();
  return 0;
}