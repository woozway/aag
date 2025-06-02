#include <iostream>
using namespace std;
const int mod = 9901;

int qmi(int a, int k) {
  a %= mod;
  int res = 1;
  while (k) {
    if (k & 1) res = res * a % mod;
    a = a * a % mod;
    k >>= 1;
  }
  return res;
}

// sum(p, k) = p^0 + p^1 + ... + p^k
//           = (p^0 + .. + p^(k/2)) + (p^(k/2+1) + .. + p^k)
//           = (p^0 + .. + p^(k/2)) + p^(k/2+1) * (p^0 + .. + p^(k/2))
//           = (1 + p^(k/2+1)) * sum(p, k / 2)
int sum(int p, int k) {
  if (k == 0) return 1;
  if (k % 2 == 0) return (p % mod * sum(p, k - 1) % mod + 1) % mod;
  return (1 + qmi(p, k / 2 + 1)) % mod * sum(p, k / 2) % mod;
}

// 对A分解质因数：A = p1^k1 * p2^k2 * ... * pn^kn
// 约数个数：(k1 + 1) * (k2 + 1) * ... * (kn + 1)
// 约数之和：(p1^0 + p1^1 +...+ p1^n) * (p2^0 +...+ p2^n) *...* (pn^0 +...+ pn^n)
int main() {
  int A, B;
  cin >> A >> B;

  int res = 1;
  for (int i = 2; i <= A; i ++ ) {
    int s = 0;
    while (A % i == 0) s ++ , A /= i;

    if (s) res = res * sum(i, s * B) % mod;
  }

  if (!A) res = 0;
  cout << res << endl;
  return 0;
}