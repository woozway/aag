#include <iostream>
using namespace std;
const int N = 100006;
struct L {
  int d, prv, nxt, th; // th存放相邻的差d在小根堆h中的下标
} p[N]; // 双向链表p
struct H {
  int D, tp; // D和tp分别为相邻的差和该差在双向链表中的下标
} h[N]; // 小根堆h
int tot = 0;

void up(int i) {
  while (i > 1) {
    if (h[i].D < h[i>>1].D) {
      swap(h[i], h[i>>1]);
      swap(p[h[i].tp].th, p[h[i>>1].tp].th);
      i >>= 1;
    } else return;
  }
}

void down(int i) {
  int ii = i << 1;
  while (ii <= tot) {
    if (ii<tot && h[ii].D>h[ii+1].D) ++ii;
    if (h[ii].D < h[i].D) {
      swap(h[ii], h[i]);
      swap(p[h[ii].tp].th, p[h[i].tp].th);
      i = ii, ii = i << 1;
    } else return;
  }
}
// 删除双向链表p中位置为i的节点
void DeL(int i) {
  p[p[i].prv].nxt = p[i].nxt;
  p[p[i].nxt].prv = p[i].prv;
}
// 删除小根堆h中位置为i的节点
void DeH(int i) {
  swap(h[i], h[tot]);
  swap(p[h[i].tp].th, p[h[tot--].tp].th);
  up(i), down(i);
}
// 双向链表 + 小根堆
int main() {
  int n, k, pre;
  cin >> n >> k >> pre;
  for (int i=1; i<n; i++) { // n-1个差d
    int w;
    scanf("%d", &w);
    p[i] = {d: w-pre, prv: i-1, nxt: i+1, th: ++tot};
    pre = w;
    h[tot] = {D: p[i].d, tp: i}; // 建小根堆
    up(tot);
  }
  int ans = 0;
  while (k--) {
    ans += h[1].D;
    int tp0 = h[1].tp; // 小根堆h中最小值所对应的p中的下标
    if (!p[tp0].prv || p[tp0].nxt==n) { // 特判第一个和最后一个节点
      if (!p[tp0].prv) {
        DeH(p[p[tp0].nxt].th);
        DeL(p[tp0].nxt);
      } else {
        DeH(p[p[tp0].prv].th);
        DeL(p[tp0].prv);
      }
      DeL(tp0);
      DeH(1);
    } else { // 取出最小差Di，删除链表p中对应位置的节点，并在该位置加入新d
      h[1].D = p[p[tp0].prv].d + p[p[tp0].nxt].d - p[tp0].d;
      p[tp0].d = h[1].D;
      down(1);
      DeH(p[p[tp0].prv].th); // 删除小根堆h中的D_i-1
      DeH(p[p[tp0].nxt].th); // ... D_i+1
      DeL(p[tp0].prv); // 删除双向链表p中的D_i-1
      DeL(p[tp0].nxt); // ... D_i+1
    }
  }
  cout << ans << endl;
  return 0;
}

// // @yxc
// #include <iostream>
// #include <set> // 对应python3中的sortedcontainers.SortedSet
// using namespace std;
// typedef long long ll;
// typedef pair<ll, int> pli;
// const int N = 100006;
// int n, k, l[N], r[N];
// ll d[N];

// void delete_node(int p) {
//   r[l[p]] = r[p], l[r[p]] = l[p];
// }

// int main() {
//   cin >> n >> k;
//   for (int i=0; i<n; i++) cin >> d[i];
//   for (int i=n-1; i; i--) d[i] -= d[i-1]; // 获取n-1个相邻的差d[i]
  
//   set<pli> s; // c++中的set有序，可以当作带增删操作的二叉堆使用
//   d[0] = d[n] = 1e15; // 头尾哨兵
//   for (int i=1; i<n; i++) {
//     l[i] = i-1, r[i] = i+1; // l[i]记录双向链表中i节点的左侧是i-1, r同理
//     s.insert({d[i], i}); // 插入邻差d和在双向链表中的下标i
//   }
//   ll ans = 0;
//   while (k--) {
//     auto it = s.begin(); // 取出堆顶元素
//     ll v = it->first;
//     int p = it->second, left = l[p], right = r[p];
//     // 堆中Di, D_i-1及D_i+1，然后
//     s.erase(it), s.erase({d[left], left}), s.erase({d[right], right});
//     delete_node(left), delete_node(right);
//     ans += v;
//     // 因为还要把d[left]+d[right]-d[p]插入到链表中，所以上一步没有delete_node(p)
//     d[p] = d[left] + d[right] - d[p];
//     s.insert({d[p], p});
//   }
//   cout << ans << endl;
//   return 0;
// }