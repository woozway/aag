#include <iostream>
#include <vector>
using namespace std;
int n, ans;
vector<int> a[2];
int c[251010]; // >=501*501

void merge(int k, int l, int mid, int r) {
  int i = l, j = mid + 1;
  for (int p=l; p<=r; p++)
    if (j>r || (i<=mid && a[k][i]<=a[k][j])) c[p] = a[k][i++];
    else ans += mid-i+1, c[p] = a[k][j++];
  for (int p=l; p<=r; p++) a[k][p] = c[p];
}

void mergesort(int k, int l, int r) {
  if (l == r) return;
  int mid = (l+r)>>1;
  mergesort(k, l, mid);
  mergesort(k, mid+1, r);
  merge(k, l, mid, r);
}

int calc(int k) { // 计算逆序对数量
  ans = 0;
  mergesort(k, 0, (n*n-1)-1); // 这里除去空格共n*n-1个数，另外下标从0开始
  return ans;
}

int main() {
  while (cin >> n) {
    a[0].clear(); a[1].clear();
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++) {
        int x; cin >> x; if (x) a[0].push_back(x);
      }
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++) {
        int x; cin >> x; if (x) a[1].push_back(x);
      }
    // 两个排序数组的逆序对奇偶性相同即可
    cout << ((a[0].size() && (calc(1)-calc(0))&1) ? "NIE" : "TAK") << endl;
  }
}