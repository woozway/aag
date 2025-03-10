#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1006;
const double INF = 0x3f3f3f3f;
int n, d;
struct P {
  int x, y;
  double l, r;
  bool operator < (const P x) const {
    return l < x.l;
  }
} p[N];

void Radar_Installation() {
  for (int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
  bool b = true;
  for (int i=1; i<=n; i++)
    if (p[i].y > d) {
      b = 0;
      break;
    }
  if (!b) {
    cout << "-1";
    return;
  }
  for (int i=1; i<=n; i++) {
    double k = sqrt((double)d*d - (double)p[i].y*p[i].y);
    p[i].l = p[i].x - k, p[i].r = p[i].x + k;
  }
  sort(p+1, p+n+1);
  int ans = 0;
  double pos = -INF;
  for (int i=1; i<=n; i++)
    if (pos < p[i].l) {
      ans++;
      pos = p[i].r;
    } else {
      pos = min(p[i].r, pos);
    }
  cout << ans;
}

int main() {
  cin >> n >> d;
  Radar_Installation();
  return 0;
}