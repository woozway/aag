#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10006;
int n, x[N], y[N];

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
  sort(x+1, x+n+1); // x[i] -> a[i]-i
  sort(y+1, y+n+1); // 士兵排成一排，在y轴上和货仓问题一致
  // x轴上每两个士兵排完后间隔为1，可证相对顺序不变。设排完后第一个位置为a
  // 则x轴上移动的总距离：|x[1]-a| + |x[2]-(a+1)| + ... + |x[n]-(a+n-1)|
  // 即：|x[1]-a| + |x[2]-1-a| + ... + |x[n]-(n-1)-a|，对x处理后也是货仓问题
  for (int i=1; i<=n; i++) x[i] -= i - 1;
  sort(x+1, x+n+1);
  int ans = 0;
  for (int i=1; i<=n/2; i++)
    ans += (x[n+1-i] - x[i]) + (y[n+1-i] - y[i]);
  cout << ans;
  return 0;
}