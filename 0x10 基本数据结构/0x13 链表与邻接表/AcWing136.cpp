#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100006;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct A {
  ll a; // a是值，因为相减可能爆long long，w是原序列中的下标
  int w, prv, nxt;
  bool operator < (const A x) const {
    return a < x.a;
  }
} a[N];
int n, b[N]; // b[i]存储排序后Ai对应在链表中的位置
struct ANS {
  ll x; // 和a[i].a同理，可能爆long long
  int k; // x是|Aj-Ai|差的绝对值，k是Aj下标
} ans[N];

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> a[i].a;
    a[i].w = i;
  }
  sort(a+1, a+n+1);
  for (int i=1; i<=n; i++) {
    b[a[i].w] = i;
    a[i].prv = i - 1;
    a[i].nxt = i + 1;
  }
  // 倒着从n->1，因为对于第An个数，可以从前面所有的数中找Aj，完成后删除节点
  a[0].a = -INF, a[n+1].a = INF; // 设立哨兵head, tail，降低编码难度
  for (int i=n; i>1; i--) {
    ans[i].x = a[a[b[i]].nxt].a - a[b[i]].a;
    ans[i].k = a[a[b[i]].nxt].w;
    if (a[b[i]].a - a[a[b[i]].prv].a <= ans[i].x) {
      ans[i].x = a[b[i]].a - a[a[b[i]].prv].a;
      ans[i].k = a[a[b[i]].prv].w;
    }
    a[a[b[i]].prv].nxt = a[b[i]].nxt;
    a[a[b[i]].nxt].prv = a[b[i]].prv;
  }
  for (int i=2; i<=n; i++) cout << ans[i].x << " " << ans[i].k << endl;
  return 0;
}