#include <iostream>
#include <cstring>
using namespace std;
char a[1000010];
int nxt[1000010], n, T;

void calc_next() {
  nxt[1] = 0;
  for (int i=2, j=0; i<=n; i++) {
    while (j>0 && a[i]!=a[j+1]) j = nxt[j];
    if (a[i] == a[j+1]) j++;
    nxt[i] = j;
  }
}

int main() {
  while (cin >> n && n) {
    scanf("%s", a+1);
    calc_next();
    printf("Test case #%d\n", ++T);
    for (int i=2; i<=n; i++)
      if (i%(i-nxt[i]) == 0 && i/(i-nxt[i]) > 1) // 能整除才是循环节
        printf("%d %d\n", i, i/(i-nxt[i]));
    puts("");
  }
}