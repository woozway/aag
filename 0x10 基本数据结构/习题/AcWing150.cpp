#include <iostream>
#include <stack>
using namespace std;

int main() {
  string s;
  cin >> s;
  stack<int> stk; // 存左括号的下标
  int ans = 0;
  for (int i=0; i<s.size(); i++) {
    char c = s[i];
    if (stk.empty()) stk.push(i);
    else {
      char t = s[stk.top()];
      if (c==')'&&t=='(' || c==']'&&t=='[' || c=='}'&&t=='{') stk.pop();
      else stk.push(i);
    }
    // 若stk非空，栈顶为第一个非匹配下标，i-stk.top()为中间已匹配弹出段的长度
    if (!stk.empty()) ans = max(ans, i - stk.top());
    else ans = max(ans, i + 1); // i开始的字符串中的括号完全匹配
  }
  cout << ans << endl;
  return 0;
}

// #include <iostream>
// #include <cstring>
// using namespace std;
// int n, p, ans, history_match[100010], pos[100010];
// // f中存放期待匹配的括号，p表示其个数，pos[p]表示第p个左括号的下标
// char s[100010], f[100010];
// int main() {
//   scanf("%s", s);
//   n = strlen(s), p = 0;
//   for (int i=0; i<n; i++) {
//     if (s[i] == '(') f[++p] = ')', pos[p] = i;
//     else if (s[i] == '[') f[++p] = ']', pos[p] = i;
//     else if (s[i] == '{') f[++p] = '}', pos[p] = i;
//     else {
//       if (p && s[i]==f[p]) { // 发生一次括号匹配
//         int cur_match = i - pos[p] + 1;
//         p--;
//         ans = max(ans, history_match[p] + cur_match);
//         history_match[p] += cur_match;
//       }
//       else { // 以i开始的括号序列不是美观序列
//         for (int j=0; j<=p; j++) history_match[j] = 0;
//         p = 0;
//       }
//     }
//   }
//   cout << ans << endl;
// }