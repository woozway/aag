#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 50006;
struct COW {
  int id, l, r, ans;
  bool operator < (const COW x) const {
    return l < x.l;
  }
} cow[N];
priority_queue<pair<int, int> > s; // 默认为大根堆

int main() {
  int n, ans[N];
  cin >> n;
  for (int i=1; i<=n; i++) {
    cow[i].id = i;
    cin >> cow[i].l >> cow[i].r;
  }
  sort(cow+1, cow+n+1);
  // 扫描s，找到一畜栏：满足当前牛开始吃草时间>=畜栏中最后一头牛结束吃草的时间
  for (int i=1; i<=n; i++) {
    int num = s.size();
    if (num && -s.top().first < cow[i].l) {
      cow[i].ans = s.top().second;
      s.pop();
      s.push(make_pair(-cow[i].r, cow[i].ans));
      continue;
    }
    cow[i].ans = ++num;
    s.push(make_pair(-cow[i].r, num));
  }
  cout << s.size() << endl;
  for (int i=1; i<=n; i++) ans[cow[i].id] = cow[i].ans;
  for (int i=1; i<=n; i++) cout << ans[i] << endl;
  return 0;
}