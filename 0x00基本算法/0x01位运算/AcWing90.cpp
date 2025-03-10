#include <iostream>

using namespace std;
typedef long long ll;

// // 方法一：快速幂
// ll mul(ll a, ll b, ll p) {
//   ll ans = 0;
//   for (; b; b>>=1) {
//     if (b&1) ans = (ans+a) % p;
//     a = a*2 % p;
//   }
//   return ans;
// }

// 方法二：a*b % p = a*b - floor(a*b/p)*p
ll mul(ll a, ll b, ll p) {
  a %= p, b %= p;
  ll c = (long double)a*b / p;
  ll ans = a*b % p - c*p % p;
  if (ans < 0) ans += p;
  return ans;
}

int main() {
  ll a, b, p;
  cin >> a >> b >> p;
  cout << mul(a, b, p);
  return 0;
}