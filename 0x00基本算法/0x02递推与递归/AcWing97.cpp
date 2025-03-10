#include <iostream>
#include <vector>
// #define ll long long
using namespace std;
typedef long long ll;
const ll P = 9901;
vector<pair<ll, ll> > w;
// 快速幂计算a**b
ll ksm(ll a, ll b) {
  ll ans = 1;
  a %= P;
  while (b) {
    if (b & 1) (ans *= a) %= P;
    (a *= a) %= P;
    b >>= 1;
  }
  return ans;
}
// 计算1+p+p**2+..+p**c
ll get_sum(ll p, ll c) {
  if (!p) return 0; // 0也可能是约数
  if (!c) return 1;
  if (c & 1) return (1 + ksm(p, (c+1)/2)) * get_sum(p, (c-1)/2) % P;
  return ((1 + ksm(p, c/2)) * get_sum(p, c/2-1) + ksm(p, c)) % P;
}
// 从[2,floor(sqrt(a))]，找到每一个a的质因子，并记录个数
// 1不是质因子，但是是约数，后面会统一处理
void fj(ll a) {
  for (int i=2; i*i<=a; i++) {
    if (!(a % i)) {
      ll num = 0;
      while (!(a % i)) {
        num++;
        a /= i;
      }
      w.push_back(make_pair(i, num));
    }
  }
  if (a != 1) w.push_back(make_pair(a, 1));
}

int main() {
  ll a, b;
  cin >> a >> b;
  fj(a); // 分解a的质因子，存入w
  ll ans = 1;
  for (ll i=0; i<w.size(); i++) {
    ll p = w[i].first, c = w[i].second;
    (ans *= get_sum(p, b*c)) %= P;
  }
  if (ans < 0) ans += P;
  cout << ans;
  return 0;
}