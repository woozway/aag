#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 30010;
int n, m, a[N], u[N];

int main() {
  cin >> n >> m;
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<m; i++) cin >> u[i];
  sort(u, u+m);
  // 对顶堆：大根堆存[1~i-1]个数；小根堆存[i~n]个数
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int> > right;
  int i = 0, j = 0;
  while (i<n || j<m) {
    // GET操作
    while (j<m && u[j]==i) {
      cout << right.top() << endl;
      left.push(right.top()), right.pop();
      j++;
    }
    // ADD(x)操作
    int x = a[i];
    if (left.empty() || x>=right.top()) right.push(x); 
    else {
      left.push(x);
      right.push(left.top()), left.pop();
    }
    i++;
  }
  return 0;
}