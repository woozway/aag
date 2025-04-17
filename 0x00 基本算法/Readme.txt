常用代码模版1：基础算法
@yxc, https://www.acwing.com/blog/content/277/
---
// 快速排序，快速选择
void quick_sort(int l, int r) {
  if (l >= r) return; // >=，因为快排中区间内可能没有数
  int x = a[l+r>>1], i = l-1, j = r+1; // 测试用例增强了
  while (i < j) {
    do i++; while (a[i] < x);
    do j--; while (a[j] > x);
    if (i < j) swap(a[i], a[j]);
  }
  quick_sort(l, j); // a[l~j]都<=x
  quick_sort(j+1, r); // a[j+1~r]都>=x
}

// 归并排序，逆序对
void merge_sort(int l, int r) {
  if (l >= r) return;
  int mid = l+r >> 1;
  merge_sort(l, mid);
  merge_sort(mid+1, r);
  int i = l, j = mid+1;
  for (int k=l; k<=r; k++)
    if (j>r || i<=mid && a[i]<=a[j]) b[k] = a[i++]; // 这里写<=才稳定
    else b[k] = a[j++];
  for (int k=l; k<=r; k++) a[k] = b[k];
}

// 整数二分
bool check(int x) { /* ... */} // 检查x是否满足某种性质
void bsearch_1() {
  int l = 0, r = n-1;
  while (l < r) {
    int mid = l+r >> 1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
}

void bsearch_2() {
  int l = 0, r = n-1;
  while (l < r) {
    int mid = l+r+1 >> 1;
    if (a[mid] <= k) l = mid;
    else r = mid-1;
  }
}

// 浮点数二分
void bsearch_3() {
  l = -100, r = 100; // double eps = 1e-6
  while (r-l > 1e-8) { // 8=6+2
    double mid = (l+r) / 2;
    if (mid*mid*mid < n) l = mid;
    else r = mid;
  }
}

// 高精度加法：C=A+B, A>=0, B>=0
vector<int> add(vector<int> &A, vector<int> &B) {
  if (A.size() < B.size()) return add(B, A);
  vector<int> C;
  int t = 0; // 进位
  for (int i=0; i<A.size(); i++) {
    t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(1);
  return C;
}

// 高精度减法：C=A-B, A>=0, B>=0, A>=B
vector<int> sub(vector<int> &A, vector<int> &B) {
  vector<int> C;
  for (int i=0, t=0; i<A.size() || t; i++) {
    t = A[i] - t;
    if (i < B.size()) t -= B[i];
    C.push_back((t+10) % 10);
    if (t < 0) t = 1;
    else t = 0;
  }
  while (C.size()>1 && C.back()==0) C.pop_back(); // 删除前导0
  return C;
}

// 高精度乘法：C=A*b, 大整数A>=0，整数b>=0
vector<int> mul(vector<int> &A, int b) {
  vector<int> C;
  for (int i=0, t=0; i<A.size() || t; i++) {
    if (i < A.size()) t += A[i] * b;
    C.push_back(t % 10);
    t /= 10;
  }
  while (C.size()>1 && C.back()==0) C.pop_back();
  return C;
}

// // 大整数A>=0, B>=0
// vector<int> mul(vector<int> &A, vector<int> &B) {
//   vector<int> C(A.size()+B.size(), 0);
//   for (int i=0; i<A.size(); i++)
//     for (int j=0; j<B.size(); j++)
//       C[i+j] += A[i] * B[j];
//   for (int i=0; i<C.size()-1; i++) {
//     C[i+1] += C[i] / 10;
//     C[i] %= 10;
//   }
//   while (C.size()>1 && C.back()==0) C.pop_back();
//   return C;
// }

// 高精度除法：A/B=C...r, 大整数A>=0，整数b>0
vector<int> div(vector<int> &A, int b, int &r) {
  vector<int> C;
  r = 0;
  for (int i=A.size()-1; i>=0; i--) { // 除法从高位开始
    r = r*10 + A[i];
    C.push_back(r / b);
    r %= b;
  }
  reverse(C.begin(), C.end());
  while (C.size()>1 && C.back()==0) C.pop_back();
  return C;
}

// 1D前缀和
s[i] = a[1] + a[2] + ... + a[i]
a[l] + ... + a[r] = s[r] - s[l-1]

// 2D前缀和
s[i,j] = 第i行j列格子左上部分所有元素的和
以(x1,y1)为左上角，(x2,y2)为右下角的子矩阵的和为：
s[x2,y2] - s[x1-1,y2] - s[x2,y1-1] + s[x1-1,y1-1]

// 1D差分
给区间[l, r]中的每个数加上c：d[l] += c, d[r+1] -= c

// 2D差分
给以(x1,y1)为左上角，(x2,y2)为右下角的子矩阵中的所有元素加上c：
s[x1,y1] += c, s[x2+1,y1] -= c, s[x1, y2+1] -= c, s[x2+1,y2+1] += c

// 位运算
求n的第k位数字: n >> k & 1
返回n的最后一位1：lowbit(n) = n & -n

// 双指针
for (int i=0, j=0; i<n; i++) {
  while (j<i && check(i, j)) j++; // 或j--等操作
  // 具体问题的逻辑
}
常见问题分类：
  (1) 对于一个序列，用两个指针维护一段区间
  (2) 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作

// 离散化
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end()); // 去掉重复元素
// 二分求出x对应的离散化的值
int find(int x) { // 找到第一个大于等于x的位置
  int l = 0, r = alls.size()-1;
  while (l < r) {
    int mid = l + r >> 1;
    if (alls[mid] >= x) r = mid;
    else l = mid+1;
  }
  return l+1; // 映射到1, 2, ...n
}

// 区间合并
void merge() {
  sort(segs.begin(), segs.end()); // 按左端点排序
  int st = -2e9, ed = -2e9; // 左端点初始化-inf
  for (auto seg: segs)
    if (ed < seg.first) {
      if (st != -2e9) ans.push_back({st, ed}); // 这里ans收录的是合并后的st和ed
      st = seg.first, ed = seg.second;
    } else {
      ed = max(ed, seg.second);
    }
  if (st != -2e9) ans.push_back({st, ed}); // 压入最后一个合并后的区间
}
