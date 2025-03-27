#include <cstring>
#include <iostream>
using namespace std;
const int N = 1000006;
int trie[N][27], tot = 1;
char s[N];

void add() {
  int len = strlen(s), p = 1;
  for (int i=0; i<len; i++) {
    int k = s[i] - 'a' + 1;
    if (!trie[p][k]) trie[p][k] = ++tot;
    p = trie[p][k];
  }
  ++trie[p][0]; // 为处理插入重复字符串的情况，不能只做结尾标记
}

void get() {
  int ans = 0, len = strlen(s), p = 1;
  for (int i=0; i<len; i++) {
    p = trie[p][s[i]-'a'+1];
    ans += trie[p][0];
  }
  cout << ans << endl;
}

int main() {
  memset(trie, 0, sizeof(trie));
  int n, m;
  cin >> n >> m;
  while (n--) {
    scanf("%s", s);
    add();
  }
  while (m--) {
    scanf("%s", s);
    get();
  }
  return 0;
}