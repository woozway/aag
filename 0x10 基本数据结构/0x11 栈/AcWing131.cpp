#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
const int N = 100006;
int n, p, a[N], s[N], w[N];

void Largest() {
  for (int i=1; i<=n; i++) cin >> a[i];
  a[n+1] = p = 0;
  ll ans = 0;
  for (int i=1; i<=n+1; i++)
    if (a[i] > s[p])
      s[++p] = a[i], w[p] = 1;
    else {
      int width = 0;
      while (s[p] > a[i]) {
        width += w[p];
        ans = max(ans, (ll)width * s[p]);
        p--;
      }
      s[++p] = a[i], w[p] = width + 1;
    }
  cout << ans << endl;
}

int main() {
  while (cin >> n && n) Largest();
  return 0;
}