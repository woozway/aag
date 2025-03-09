#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, bool> existed;
const int N = 10006;
// c[i]表示和最高的牛p的高度h相比，要矮多少
// 为了降低算法时间复杂度从O(nm)到O(m+n)，使用差分数列更新a,b之间牛的身高
// d是c的差分数列，之后对d进行求前缀和，以得到c数列
int c[N], d[N];

int main() {
  int n, p, h, m;
  cin >> n >> p >> h >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    // 一条关系可能输入多次，只算一次
    if (existed[make_pair(a, b)]) continue;
    // 差分数列d上操作两个端点：表示[a+1,b-1]之间坐标的牛的高度都-1
    d[a+1]--, d[b]++;
    existed[make_pair(a, b)] = true;
  }
  for (int i=1; i<=n; i++) {
    c[i] = c[i-1] + d[i];
    cout << h + c[i] << endl;
  }
  return 0;
}