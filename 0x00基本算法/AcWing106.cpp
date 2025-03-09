#include <iostream>
#include <queue>
using namespace std;
// q1大根堆（保存大小上前一半的数）q2小根堆保存后一半
priority_queue<int> q1, q2;

void Running_Median() {
  while (q1.size()) q1.pop();
  while (q2.size()) q2.pop();
  int num, n, a, cnt = 1;
  cin >> num >> n;
  cout << num << " " << (n+1)/2 << endl;
  cin >> a;
  cout << a;
  q2.push(-a); // 当q1和q2中的个数不等时，q2中总是多一个
  for (int i=2; i<=n; i++) {
    cin >> a;
    if (a < -q2.top()) q1.push(a);
    else q2.push(-a);
    int s = q1.size();
    if (s > i/2) {
      q2.push(-q1.top());
      q1.pop();
    }
    if (s < i/2) {
      q1.push(-q2.top());
      q2.pop();
    }
    if (i % 2) {
      if (cnt % 10) cout << " ";
      cout << -q2.top();
      if (++cnt % 10 == 0) cout << endl;
    }
  }
  if (cnt % 10) cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) Running_Median();
  return 0;
}