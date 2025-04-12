#include <queue>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int N = 100006;
int n, m, a[N], s[N], nxt[N], prv[N];
bool v[N];
struct P {
  int p, c;
  bool operator < (const P x) const {
    return abs((double)c) > abs((double)x.c);
  }
};
priority_queue<P> q;

void Delete(int x) {
  v[x] = 0;
  prv[nxt[x]] = prv[x];
  nxt[prv[x]] = nxt[x];
}
// 同见等价题：AcWing147数据备份
int main() {
  cin >> n >> m;
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  int tot = 1;
  for (int i=1; i<=n; i++)
    if ((ll)s[tot] * a[i] >= 0) s[tot] += a[i];
    else s[++tot] = a[i];
  int ans = 0, cnt = 0;
  for (int i=1; i<=tot; i++) {
    P p;
    p.c = s[i];
    p.p = i;
    q.push(p);
    if (s[i] > 0) {
      ans += s[i];
      cnt++;
    }
    prv[i] = i-1;
    nxt[i] = i+1;
  }
  memset(v, 1, sizeof(v));
  while (cnt > m) {
    cnt--;
    P p = q.top();
    while (!v[p.p]) {
      q.pop();
      p = q.top();
    }
    q.pop();
    if (prv[p.p] && nxt[p.p]!=tot+1) ans -= abs((double)s[p.p]);
    else if (s[p.p] > 0) ans -= s[p.p];
    else {
      cnt++;
      continue;
    }
    s[p.p] += s[prv[p.p]] + s[nxt[p.p]];
    Delete(prv[p.p]);
    Delete(nxt[p.p]);
    p.c = s[p.p];
    q.push(p);
  }
  cout << ans << endl;
  return 0;
}

// // @yxc
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 100010;
// int n, m, a[N], l[N], r[N];
// bool st[N]; // 1标记删除

// void remove(int p) {
//   r[l[p]] = r[p], l[r[p]] = l[p];
//   st[p] = 1;
// }

// int main() {
//   cin >> n >> m;
//   int k = 0, x;
//   while (n--) {
//     cin >> x;
//     if (!x) continue; // 跳过0，只剩正/负数连续段
//     if (!k || (long long)a[k]*x<0) a[++k] = x;
//     else a[k] += x; // a[i]表示一段连续的正/负数
//   }
//   priority_queue<pii, vector<pii>, greater<pii> > q;
//   int cnt = 0, ans = 0; // cnt：正数段的个数
//   for (int i=1; i<=k; i++)
//     if (a[i] > 0) cnt++, ans += a[i];
//   for (int i=1; i<=k; i++) {
//     l[i] = i-1, r[i] = i+1;
//     q.push({abs(a[i]), i});
//   }
//   while (cnt > m) {
//     while (st[q.top().second]) q.pop(); // 懒惰删除
//     auto t = q.top(); q.pop();
//     int v = t.first, p = t.second;
//     if (l[p]!=0 && r[p]!=k+1 || a[p]>0) {
//       cnt--, ans -= v;
//       int left = l[p], right = r[p];
//       a[p] += a[left] + a[right];
//       q.push({abs(a[p]), p});
//       remove(left), remove(right);
//     } else {
//       remove(p);
//     }
//   }
//   cout << ans << endl;
//   return 0;
// }