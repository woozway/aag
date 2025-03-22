#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int N = 100006;
int n, tot, P = 99991; // 随机数据期望O(N^2/P)，取P为接近的大质数
int snow[N][6], head[N], nxt[N];
int H(int *a) {
  int sum = 0, mul = 1;
  for (int i=0; i<6; i++) {
    sum = (sum + a[i]) % P;
    mul = (ll)mul * a[i] % P;
  }
  return (sum + mul) % P;
}

bool equal(int *a, int *b) {
  for (int i=0; i<6; i++)
    for (int j=0; j<6; j++) {
      bool eq = 1;
      for (int k=0; k<6; k++)
        if (a[(i+k)%6] != b[(j+k)%6]) {
          eq = 0; // 顺时针对比
          break;
        }
      if (eq) return 1;
      eq = 1;
      for (int k=0; k<6; k++)
        if (a[(i+k)%6] != b[(j-k+6)%6]) {
          eq = 0; // 逆时针对比
          break;
        }
      if (eq) return 1;
    }
  return 0;
}

bool insert(int *a) {
  int val = H(a);
  // 遍历表头head[val]指向的链表，在同一slot中寻找形状相同的雪花
  for (int i=head[val]; i; i=nxt[i])
    if (equal(snow[i], a)) return 1;
  // 未找到形状相同的雪花，执行插入
  ++tot;
  memcpy(snow[tot], a, 6*sizeof(int));
  nxt[tot] = head[val], head[val] = tot;
  return 0;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    int a[10];
    for (int j=0; j<6; j++) scanf("%d", &a[j]);
    if (insert(a)) {
      puts("Twin snowflakes found.");
      return 0;
    }
  }
  puts("No two snowflakes are alike.");
  return 0;
}