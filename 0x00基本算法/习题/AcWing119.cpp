#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const int N = 100006;
const double INF = 0x3f3f3f3f;
struct P {
  double x, y;
  bool z; // 区分两波数字
  bool operator < (const P w) const {
    return x < w.x;
  }
} p[N*2], tmp[N*2];
int n, t;

double dist(P a, P b) {
  if (a.z == b.z) return INF;
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
// 分治法计算左半右半，取最小ans；然后依此计算左右各一个点的情况
double s(int l, int r) {
  if (l == r) return INF;
  if (l + 1 == r) return dist(p[l], p[r]);
  int mid = (l + r) >> 1;
  double ans = min(s(l, mid), s(mid+1, r));

  // 归并排序，并在过程中将[l,r]中的点按照y从小到大排列
  int i = l, j = mid+1;
  for (int k=l; k<=r; k++)
    if (j>r || (i<=mid && p[i].y<=p[j].y)) tmp[k] = p[i++];
    else tmp[k] = p[j++];
  for (int k=l; k<=r; k++) p[k] = tmp[k];

  // 在[p[mid].x-ans, p[mid].x+ans]的左半找最多6个点，右半找最多6个点
  int k = 0;
  for (int i=mid; i>=l && k<6; i--)
    if (p[i].x >= p[mid].x-ans) tmp[k++] = p[i];
  for (int i=mid+1; i<=r && k<12; i++)
    if (p[i].x >= p[mid].x-ans) tmp[k++] = p[i];
  for (int i=1; i<k; i++)
    for (int j=i-1; j>=0; j--)
      ans = min(ans, dist(tmp[i], tmp[j]));
  return ans;
}

void Raid() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i].z = 0;
  }
  for (int i=1; i<=n; i++) {
    cin >> p[i+n].x >> p[i+n].y;
    p[i+n].z = 1;
  }
  sort(p+1, p+2*n+1); // 按照x坐标从小到达排列
  cout << fixed << setprecision(3) << s(1, 2*n) << endl;
}

int main() {
  cin >> t;
  while (t--) Raid();
  return 0;
}