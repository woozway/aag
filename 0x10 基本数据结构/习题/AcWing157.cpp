#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 求出以当前点为根的树的最小表示：0表示往下递归，1表示往上退出递归
string dfs(string &seq, int &i) {
  vector<string> seqs; // 存各子节点的最小表示
  i++;
  while (seq[i] == '0') seqs.push_back(dfs(seq, i));
  i++;
  sort(seqs.begin(), seqs.end());
  string ans = "0";
  for (auto s: seqs) ans += s;
  ans += '1';
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    a = '0' + a + '1', b = '0' + b + '1'; // 防止额外处理边界
    int ia = 0, ib = 0; // 下标
    if (dfs(a, ia) == dfs(b, ib)) puts("same");
    else puts("different");
  }
}