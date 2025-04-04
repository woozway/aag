#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
stack<int> nums;
stack<char> ops;

void calc() {
  int b = nums.top(); nums.pop();
  int a = nums.top(); nums.pop();
  char c = ops.top(); ops.pop();
  int d = 1;
  switch (c) {
  case '+': d = a + b; break;
  case '-': d = a - b; break;
  case '*': d = a * b; break;
  case '/': d = a / b; break;
  case '^': while (b--) d *= a;
  }
  nums.push(d);
}

int main() {
  string s;
  cin >> s;
  s = '(' + s + ')'; // 首尾加括号，强制算到最后栈中只有一个数
  int l = 0, r = 0; // 计算左右括号数，若个数不匹配需补到相等
  for (int i=0; i<s.size(); i++) {
    if (s[i] == '(') l++;
    if (s[i] == ')') r++;
  }
  if (l >= r) s.append(l - r, ')');
  else s = string(r - l, '(') + s;
  for (int i=0; i<s.size(); i++) {
    if (isdigit(s[i])) {
      int j = i, t = 0;
      while (isdigit(s[j])) t = t*10 + s[j++]-'0';
      i = j - 1;
      nums.push(t);
    } else {
      char c = s[i];
      if (c == '(') ops.push(c);
      else if (c == ')') {
        while (ops.top() != '(') calc();
        ops.pop();
      } else if (c == '+' || c == '-') {
        // 如果当前这个'-'代表负号而非减号
        if (c=='-' && i && !isdigit(s[i-1]) && s[i-1]!=')') {
          if (s[i+1] == '(')
            nums.push(-1), ops.push('*');
          else {
            int j = i+1, t = 0;
            while (isdigit(s[j])) t = t*10 + s[j++]-'0';
            i = j - 1;
            nums.push(-t);
          }
        } else { // +-优先级最低，若栈中有其他运算符，直接计算
          while (ops.top() != '(') calc();
          ops.push(c);
        }
      } else if (c == '*' || c == '/') {
        while (ops.top()=='*' || ops.top()=='/' || ops.top()=='^') calc();
        ops.push(c);
      } else if (c == '^') {
        while (ops.top() == '^') calc();
        ops.push(c);
      }
    }
  }
  cout << nums.top() << endl;
  return 0;
}