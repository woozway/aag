#include <iostream>
using namespace std;
const int N = 730;
int n, p[8]; // p[i]表示i级盒子的边长
bool a[N][N]; // a[i][j]表示该位置是否为X
// 从(x,y)处开始往右往下标记X位置：即将上一级的盒子复制5次，拼成新一级盒子
void Fractal(int k, int x, int y) {
  if (k == 1) {
    a[x][y] = true;
    return;
  }
  Fractal(k-1, x, y);
  Fractal(k-1, x, y + 2*p[k-1]);
  Fractal(k-1, x + p[k-1], y + p[k-1]);
  Fractal(k-1, x + 2*p[k-1], y);
  Fractal(k-1, x + 2*p[k-1], y + 2*p[k-1]);
}

void Fractal() {
  Fractal(n, 1, 1);
  for (int i=1; i<=p[n]; i++) {
    for (int j=1; j<=p[n]; j++)
      cout << (a[i][j] ? 'X' : ' ');
    cout << endl;
  }
  cout << '-' << endl;
}

int main() {
  p[1] = 1;
  for (int i=2; i<=7; i++) p[i] = p[i-1] * 3;
  while (cin >> n && n != -1) Fractal();
  return 0;
}