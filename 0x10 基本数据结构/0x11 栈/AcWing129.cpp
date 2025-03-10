#include <cstdio>
#include <iostream>
using namespace std;
const int N = 26;
int n, num = 0, st[N], top = 0, ans[N], t = 0; // ans中是已出栈的，st是还在栈中的
// 任何状态时只有两种选择：1.下一个数x进栈；2.把当前栈顶的数出栈（如果栈非空）
void z(int x) {
  if (x == n+1) {
    if (++num > 20) exit(0);
    for (int i=1; i<=t; i++) printf("%d", ans[i]);
    for (int i=top; i; i--) printf("%d", st[i]);
    cout << endl;
    return;
  }
  if (top) {
    ans[++t] = st[top--];
    z(x);
    st[++top] = ans[t--];
  }
  st[++top] = x;
  z(x + 1);
  --top;
}

int main() {
  cin >> n;
  z(1);
  return 0;
}