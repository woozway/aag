#include <iostream>
using namespace std;
typedef unsigned long long ULL;

int main() {
  ULL a, b, p;
  cin >> a >> b >> p;

  ULL res = 0;
  while (b) {
    if (b & 1) res = (res + a) % p;
    a = (a + a) % p;
    b >>= 1;
  }
  cout << res << endl;
  return 0;
}