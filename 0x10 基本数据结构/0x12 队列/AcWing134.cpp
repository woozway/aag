#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200006, INF = 0x3f3f3f3f;
pair<int, int> a[N]; // 存原数组（数值，下标）
int n;
vector<int> p[N];

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a+1, a+n+1); // 这里c++顺便把第二键（下标）也排序了
  // 将数值相同的一段摘出放在p[t]中：记录每一段最大&最小下标
  int t = 0;
  for (int i=1; i<=n; i++) {
    p[++t].push_back(a[i].second);
    while (a[i].first == a[i+1].first)
      p[t].push_back(a[++i].second);
  }
  // 根据上一段的趋势（向上/向下）来计算当前数值相同一段的衔接方向
  bool flag = 0; // 0: 上一段趋势向下，1：...向上
  int num = INF, ans = 1; // num表示上一段的最后一个数
  for (int i=1; i<=t; i++) {
    int s = p[i].size(); // maxp=p[i][s-1], minp=p[i][0]
    if (flag) {
      if (num < p[i][0]) num = p[i][s-1];
      else {
        ++ans; // 完成一次单谷的切分，答案++
        flag = 0;
        num = p[i][0];
      }
    }
    else {
      if (num > p[i][s-1]) num = p[i][0];
      else {
        flag = 1;
        num = p[i][s-1];
      }
    }
  }
  cout << ans << endl;
  return 0;
}