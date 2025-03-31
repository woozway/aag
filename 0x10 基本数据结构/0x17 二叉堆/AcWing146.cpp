#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2006;
int t, m, n, a[N], b[N], c[N]; // c[i]中存二路归并的和
typedef pair<int, int> pii; // 存两路归并的和s以及当前一路最前面元素的下标p
// 因为a已有序，初始化时b[1~n]分别与a[1]结合形成n路（每一路都是从小到大）：
//   b[1]+a[1], b[1]+a[2], ..., b[1]+a[n]
//   b[2]+a[1], b[2]+a[2], ..., b[2]+a[n]
//   ...
//   b[n]+a[1], b[n]+a[2], ..., b[n]+a[n]
// 取该nxn矩阵第一列入队作小根堆，取出最小值后，将取出元素那一路中的下一个元素入队
void merge() {
  priority_queue<pii, vector<pii>, greater<pii> > q; // c++小根堆语法糖
  for (int i=1; i<=n; i++) q.push({a[1]+b[i], 1});
  for (int i=1; i<=n; i++) {
    auto t = q.top(); q.pop();
    int s = t.first, p = t.second;
    c[i] = s;
    q.push({s-a[p]+a[p+1], p+1}); // b[k]=s-a[p]，k即代表nxn矩阵中的哪一行
  }
  for (int i=1; i<=n; i++) a[i] = c[i];

  // priority_queue<pair<int, int> > q; // 默认为大根堆，小根堆取负即可
  // for (int i=1; i<=n; i++) q.push({-(a[1]+b[i]), 1});
  // for (int i=1; i<=n; i++) {
  //   auto t = q.top(); q.pop();
  //   int s = -t.first, p = t.second;
  //   c[i] = s;
  //   q.push({-(s-a[p]+a[p+1]), p+1});
  // }
  // for (int i=1; i<=n; i++) a[i] = c[i];
}
// 多路归并：即m-1次两路归并
void Sequence() {
  cin >> m >> n;
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  sort(a+1, a+n+1);
  --m;
  while (m--) {
    for (int j=1; j<=n; j++) scanf("%d", &b[j]);
    merge(); // 二路归并a和b，a中保存最终结果
  }
  for (int i=1; i<=n; i++) printf("%d ", a[i]);
  cout << endl;
}

int main() {
  cin >> t;
  while (t--) Sequence();
  return 0;
}
