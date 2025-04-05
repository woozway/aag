#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1010;
int n, g[N][N], a[N], f[N], color[N];

bool dfs(int u, int c) {
  color[u] = c;
  for (int j=1; j<=n; j++) {
    if (!g[u][j]) continue;
    if (color[j]) {
      if (color[j] == c) return false;
    }
    else if (!dfs(j, 3-c)) return false;
  }
  return true;
}

bool check(char a, char b) {
  if (a == b) return true;
  if (a > b) swap(a, b);
  return (a=='a' && b=='d') || (a=='b' && b=='c');
}
// 性质：i,j (i<=j)不能放入同一个栈中，当且仅当存在k, k>j，且a[k]<a[i]<a[j]
int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  f[n+1] = n+1; // 预处理，f[i]表示a[i~n]中最小的数
  for (int i=n; i; i--) f[i] = min(a[i], f[i+1]);

  for (int i=1; i<=n; i++) // 建图，为不能放入同一个栈中的两个点连线
    for (int j=i+1; j<=n; j++)
      if (a[i]<a[j] && f[j+1]<a[i])
        g[i][j] = g[j][i] = 1;

  for (int i=1; i<=n; i++)
    if (!color[i] && !dfs(i, 1)) {
      puts("0"); // 无法染色成二分图，即不是”可双栈排序排列”
      return 0;
    }
  string ans;
  stack<int> s1, s2;
  for (int i=1, cur=1; i<=n; i++) {
    if (color[i] == 1) s1.push(a[i]), ans += 'a';
    else s2.push(a[i]), ans += 'c';
    while (s1.size() && s1.top()==cur || s2.size() && s2.top()==cur) {
      if (s1.size() && s1.top()==cur) s1.pop(), cur++, ans += 'b';
      else s2.pop(), cur++, ans += 'd';
    }
  }
  // 输出字典序最小方案：优先将当前点分配到第一个栈中
  // 只有'ad', 'bc'的相对顺序可变，对连续'ad', 'bc'区间排序后即为最小字典序
  for (int i=0; i<ans.size(); ) {
    int j = i+1;
    while (j<ans.size() && check(ans[i], ans[j])) j++;
    sort(ans.begin()+i, ans.begin()+j);
    i = j;
  }
  for (auto c: ans) printf("%c ", c);
  return 0;
}