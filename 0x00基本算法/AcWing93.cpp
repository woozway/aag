#include <iostream>
#include <vector>
using namespace std;
vector<int> chosen;
int stk[100010], top = 0, address = 0, n, m;

void call(int x, int ret_addr) {
  int old_top = top;
  stk[++top] = x;
  stk[++top] = ret_addr;
  stk[++top] = old_top;
}

int ret() {
  int ret_addr = stk[top-1]; // 恢复返回地址
  top = stk[top]; // 恢复旧的top位置
  return ret_addr;
}

int main() {
  cin >> n >> m;
  call(1, 0);
  while (top) {
    int x = stk[top-2]; // call中放入栈的参数x
    switch (address) {
    case 0: //对应原递归函数入口
      if (chosen.size()>m || chosen.size()+(n-x+1)<m) {
        address = ret();
        continue;
      }
      if (x == n+1) {
        for (int i=0; i<chosen.size(); i++)
          cout << chosen[i] << " ";
        cout << endl;
        address = ret();
        continue;
      }
      chosen.push_back(x); // 准备选当前的x放入chosen
      call(x+1, 1); // 相当于calc(x+1)，返回后从case 1继续
      address = 0;
      continue; // 开启选x的新递归
    case 1: // 对应原递归函数在选完x之后
      chosen.pop_back();
      call(x+1, 2); // 相当于calc(x+1)，返回后从case 2继续
      address = 0;
      continue; // 开启不选x的新递归
    case 2: //对应原递归函数在不选择x之后
      address = ret();
    }
  }
  return 0;
}