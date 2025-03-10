#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200006, INF = 0x3f3f3f3f;
int n, t, s[N], e[N], d[N];
// b-a后以d为间隔，间隔数+1即位点数
int f(int a, int b, int d) {
  return (b >= a) ? ((b - a)/d + 1) : 0;
}
// 求有多少个数<=r，之后可根据奇偶性二分
int le(int r) {
  int ans = 0;
  for (int i=1; i<=n; i++) ans += f(s[i], min(e[i], r), d[i]);
  return ans;
}

void Defense() {
  cin >> n;
  int mins = INF, maxe = 0;
  for (int i=1; i<=n; i++) {
    cin >> s[i] >> e[i] >> d[i];
    mins = min(mins, s[i]);
    maxe = max(maxe, e[i]);
  }
  if (le(maxe) % 2 == 0) {
    cout << "There's no weakness." << endl;
    return;
  }
  int l = mins, r = maxe;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (le(mid) % 2) r = mid;
    else l = mid + 1;
  }
  cout << l << " " << le(l) - le(l-1) << endl;
}

int main() {
  cin >> t;
  while (t--) Defense();
  return 0;
}