#include <iostream>
using namespace std;
int n, m;

void dfs(int u, int s, int state) {
  if (s == m) {
    for (int i = 0; i < n; i ++ )
      if (state >> i & 1)
        cout << i + 1 << ' ';
    cout << endl;
    return;
  }
  if (u == n) return;

  for (int i = u; i < n; i ++ )
    dfs(i + 1, s + 1, state + (1 << i));
}

int main() {
  cin >> n >> m;
  dfs(0, 0, 0);
  return 0;
}