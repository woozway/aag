// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
  vector<int> specialSort(int N) {
    vector<int> a;
    for (int i=0; i<N; i++) a.push_back(i+1);
    // 数学归纳法：假设k-1已经按要求排好，二分确定第k个元素放在哪一元素前面
    for (int i=0; i<N; i++) {
      int k = a[i]; 
      int l = 0, r = k-1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (compare(k, a[mid])) r = mid;
        else l = mid + 1;
      }
      // 找到k的放置位置l，需要先把[l,i-1]坐标上的元素往后挪一格
      for (int j=i-1; j>=l; j--) a[j+1] = a[j];
      a[l] = k;
    }
    return a;
  }
};