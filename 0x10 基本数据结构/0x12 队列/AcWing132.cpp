#include <queue>
#include <iostream>
using namespace std;
const int N = 1000000, T = 1006;
int t, f[N], id = 0; // f[x]记录x是属于哪个组
char s[10];
queue<int> q[T];

void Team_Queue() {
  q[0] = queue<int>();
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      f[x] = i;
    }
    q[i] = queue<int>();
  }
  cout << "Scenario #" << ++id << endl;
  while (scanf("%s", s) && s[0] != 'S') {
    if (s[0] == 'E') {
      int x;
      cin >> x;
      if (q[f[x]].empty()) q[0].push(f[x]);
      q[f[x]].push(x);
    } else {
      int x = q[0].front();
      cout << q[x].front() << endl;
      q[x].pop();
      if (q[x].empty()) q[0].pop();
    }
  }
  cout << endl;
}

int main() {
  while (cin >> t && t) Team_Queue();
  return 0;
}