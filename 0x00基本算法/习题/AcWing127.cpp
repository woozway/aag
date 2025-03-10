#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100006, M = 106;
struct P {
  int x, y;
  bool operator < (const P w) const {
    return x > w.x || (x==w.x && y>w.y);
  }
} p[N];
vector<int> t[M]; // 按照不同级别为机器设置vector
int n, m;
// 贪心-决策包容性，见AcWing110防晒
void Task() {
  for (int i=1; i<=n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    t[y].push_back(x);
  }
  // 级别为i的机器有多台，按最长工作时间从小到大排序
  for (int i=0; i<=100; i++) sort(t[i].begin(), t[i].end());
  for (int i=1; i<=m; i++) scanf("%d %d", &p[i].x, &p[i].y);
  sort(p+1, p+m+1); // 按(任务所需时间，任务级别)两个key从大到小排序
  int ans = 0;
  ll ansa = 0;
  for (int i=1; i<=m; i++) {
    bool flag = 0; // 表示当前任务能否找到某一机器成功执行
    // 贪心去找足够cover当前i任务的最小能力机器
    for (int j=p[i].y; j<=100; j++) {
      int s = t[j].size();
      auto it = lower_bound(t[j].begin(), t[j].end(), p[i].x);
      if (it != t[j].end()) {
        t[j].erase(it);
        flag = 1;
        break;
      }
    }
    if (flag) {
      ans++;
      ansa += 500*p[i].x + 2*p[i].y;
    }
  }
  cout << ans << " " << ansa << endl;
}

int main() {
  cin >> n >> m;
  Task();
  return 0;
}