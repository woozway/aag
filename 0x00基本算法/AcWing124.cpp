#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1006;
// ch2n[i]存放字符i对应的10进制下的数字，ff中存放原始字符[0-9A-Za-z]
int ch2n[200], n2ch[100];
char s[N], ans[N];
// 这里用短除法直接a转b进制（也可以先转为十进制数：秦九韶+短除法）
void NUMBER_BASE_CONVERSION() {
  int a, b;
  cin >> a >> b;
  scanf("%s", s);
  cout << a << " " << s << endl << b << " ";
  int len = strlen(s), t = strlen(s), i;
  for (i=0; t; i++) {
    int k = 0; // a进制中前一高位用于后一位计算的借位
    for (int j=len-t; j<len; j++) {
      k = k*a + ch2n[s[j]];
      s[j] = n2ch[k/b];
      k %= b;
    }
    ans[i] = n2ch[k]; // 获取b进制数的一位（从个位开始往高位）
    while (t>0 && s[len-t]=='0') t--; // 除去前导0
  }
  while (--i >= 0) cout << ans[i];
  cout << endl << endl;
}

int main() {
  int t = 0;
  for (int i='0'; i<='9'; i++) {
    ch2n[i] = t;
    n2ch[t++] = i;
  }
  for (int i='A'; i<='Z'; i++) {
    ch2n[i] = t;
    n2ch[t++] = i;
  }
  for (int i='a'; i<='z'; i++) {
    ch2n[i] = t;
    n2ch[t++] = i;
  }
  cin >> t;
  while (t--) NUMBER_BASE_CONVERSION();
  return 0;
}