#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
queue<pii> q; // 等待队列：（所需内存长度，运行时间）
set<pii> runs; // 运行任务：（内存起始下标，所需内存长度）
// 小根堆：（任务结束时间，内存起始下标）
priority_queue<pii, vector<pii>, greater<pii> > hp;
int n, tm, cnt;

bool pd(int t, int m, int p) { // 尝试为任务分配内存
  for (auto it=runs.begin(); it!=runs.end(); it++) {
    auto jt = it;
    jt++; // it和jt之间就是空闲的内存，可设置2哨兵以防止边界处理逻辑
    int start = it->first + it->second;
    if (jt != runs.end()) {
      if (m <= jt->first - start) {
        runs.insert({start, m});
        hp.push({t+p, start});
        return true;
      }
    }
  }
  return false;
}

void sf(int t) { // 释放结束时间<=t时刻的任务所占用的内存
  while (hp.size() && hp.top().first<=t) {
    int endt = hp.top().first; // 获取任务结束的具体时间endt
    while (hp.size() && hp.top().first==endt) {
      auto top = hp.top(); hp.pop();
      auto it = runs.lower_bound({top.second, 0});
      runs.erase(it);
    }
    tm = endt; // 每一次都要记得更新结束时间
    while (q.size()) { // 如果endt后队列q中可以满足，则分配内存
      auto front = q.front();
      if (pd(endt, front.first, front.second)) q.pop();
      else break;
    }
  }
}
// 1. 释放所有时间<=t的内存，每次释放后，需判断q队头任务是否可满足
// 2. 判断当前任务(t,m,p)是否可满足，若不可以，则插入等待队列q
int main() {
  cin >> n;
  int t, m, p; // t申请时刻，m所需内存长度，p运行时间
  runs.insert({-1, 1}), runs.insert({n, 1}); // 首尾哨兵
  while (cin >> t >> m >> p, t || m || p) {
    sf(t);
    if (!pd(t, m, p)) {
      q.push({m, p});
      cnt++;
    }
  }
  sf(1e9); // 释放所有任务
  cout << tm << endl << cnt << endl;
  return 0;
}