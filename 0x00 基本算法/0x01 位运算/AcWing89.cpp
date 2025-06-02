#include <iostream>
using namespace std;
typedef long long LL;

int main() {
  int a, b, p;
  cin >> a >> b >> p;

  int res = 1 % p;
  while (b) {
    if (b & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    b >>= 1;
  }

  cout << res << endl;
  return 0;
}