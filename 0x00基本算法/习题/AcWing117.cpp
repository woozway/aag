#include <iostream>
#include <cstring>
using namespace std;
// f[i]存扑克牌中字符i对应的1-13中的数字，ans[i]存i正面目前有几张
int f[100], ans[13];
char s[14][5];

int main() {
  for (int i=1; i<=13; i++)
    for (int j=1; j<=4; j++)
      cin >> s[i][j];
  f['A'] = 1;
  for (int i='2'; i<='9'; i++) f[i] = i - '0';
  f['0'] = 10;
  f['J'] = 11;
  f['Q'] = 12;
  f['K'] = 13;
  memset(ans, 0, sizeof(ans));
  for (int i=1; i<=4; i++) {
    char t = s[13][i];
    while (f[t] != 13) {
      ans[f[t]]++;
      // 这里默认4位置就是最后一张，所以下步要调整所有还没翻过来的牌往后挪一位
      char tmp = s[f[t]][4];
      for (int j=4; j>ans[f[t]]; j--) s[f[t]][j] = s[f[t]][j-1];
      t = tmp;
    }
  }
  int cnt = 0;
  for (int i=1; i<=12; i++)
    if (ans[i] == 4) cnt++;
  cout << cnt;
  return 0;
}