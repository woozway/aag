#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  int _0 = 0, _1 = -1; // 每位上全0和全1
  while (n -- ) {
    int x;
    string op;
    cin >> op >> x;

    if (op[0] == 'A') _0 &= x, _1 &= x;
    if (op[0] == 'X') _0 ^= x, _1 ^= x;
    if (op[0] == 'O') _0 |= x, _1 |= x;
  }

  int res = 0; // 每位独立，可以贪心，让伤害最大
  for (int i = 29; ~i; i -- ) // 本题中m最大是10^9，lg2(10^9) = 3log2(10^3) < 30
    if (_0>>i & 1) res += 1 << i; // 说明初始数的该位上填0，经过n道门后是1
    else if (_1>>i & 1 && (1 << i) <= m) res += 1 << i, m -= 1 << i;

  cout << res << endl;
  return 0;
}