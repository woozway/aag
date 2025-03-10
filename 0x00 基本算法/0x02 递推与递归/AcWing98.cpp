#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

// calc(N,M)返回编号为M的房屋（从0开始）在N级城市中的位置
// len表示N级城市的正方形边长（一个格子边长记为1，尚未乘10）
pair<ll, ll> calc(ll N, ll M) {
  if (N == 0) return make_pair(0, 0);
  // 这里因为N<=31，所以2*N-2会超出int表示范围，加ll
  ll len = 1 << (N-1), cnt = 1ll << (2*N-2);
  pair<ll, ll> pos = calc(N-1, M%cnt);
  ll x = pos.first, y = pos.second;
  ll z = M / cnt;
  if (z == 0) return make_pair(y, x);
  if (z == 1) return make_pair(x, y+len);
  if (z == 2) return make_pair(x+len, y+len);
  if (z == 3) return make_pair(2*len-y-1, len-x-1);
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    ll N, A, B;
    cin >> N >> A >> B;
    pair<ll, ll> ap = calc(N, A-1);
    pair<ll, ll> bp = calc(N, B-1);
    ll dx = ap.first - bp.first, dy = ap.second - bp.second;
    // 因为需要四舍五入，所以用round最好；c的写法如下
    // printf("%.0f\n", (double)sqrt(dx * dx + dy * dy) * 10);
    cout << (ll)round(sqrt(dx*dx + dy*dy) * 10) << endl;
  }
  return 0;
}