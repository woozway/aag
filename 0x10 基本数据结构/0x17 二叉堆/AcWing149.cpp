#include <iostream>
#include <queue>
#define ll long long
using namespace std;
priority_queue<pair<ll, ll> > q;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i=1; i<=n; i++) {
    ll a;
    scanf("%lld", &a);
    q.push(make_pair(-a, 0)); // 小根堆存负值
  }
  while ((n-1) % (k-1)) {
    ++n; // k叉Huffman树，让子节点不足k个的情况发生在最底层
    q.push(make_pair(0, 0)); // (-单词出现频率，-最长k进制串s的最短长度)
  }
  ll ans = 0;
  while (q.size() != 1) {
    ll num = 0, w = 0;
    for (int i=1; i<=k; i++) {
      num += q.top().first;
      w = min(w, q.top().second); // 取出当前的k个节点中k进制串s长度最大的
      q.pop();
    }
    ans += -num;
    q.push(make_pair(num, w-1));
  }
  cout << ans << endl << -q.top().second << endl;
  return 0;
}