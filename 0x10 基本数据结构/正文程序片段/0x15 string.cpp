// KMP
// next[i]表示“A中以i结尾的非前缀子串”与“A的前缀”能够匹配的最大长度
// 假设next[1~i-1]已求出，不断求next[i]；j表示最长匹配长度，初始化为0
next[1] = 0;
for (int i = 2, j = 0; i <= n; i++) { // 这里next是在建立A自身子串的对应关系，所以初始化i=2
  // 不断尝试扩展匹配长度j，如果扩展失败，令j=next[j]，直至j为0（从头匹配）
  while (j > 0 && a[i] != a[j+1]) j = next[j];
  // 如果扩展成功，匹配长度j+1；next[i]的值就是j
  if (a[i] == a[j+1]) j++;
  next[i] = j;
}

// f[i]表示“B中以i结尾的子串”与“A的前缀”能够匹配的最大长度
// 因为定义相似，求解f[i]与求解next[i]的过程基本一致
for (int i = 1, j = 0; i <= m; i++) { // 这里j是在建立B和A的对应关系，所以初始化i=1
  // 这里添加了j==n的判断，因为子串A可能在B中出现多次
  // 第一次之后的匹配会用到j==n条件再次匹配子串A在B中新的位置
  while (j > 0 && (j == n || b[i] != a[j+1])) j = next[j];
  if (b[i] == a[j+1]) j++;
  f[i] = j;
  // if (f[i] == n)，此时就是A在B中的某一次出现
}


// 最小表示法：找循环同构的n个字符串中字典序最小的一个
// B[i]表示从i开始的循环同构字符串，即：S[i~n] + S[1~i-1]
// 可通过拼接SS，则B[i]=SS[i~i+n-1]
int n = strlen(s + 1);
for (int i = 1; i <= n; i++) s[n+i] = s[i];
int i = 1, j = 2, k; // 初始化
while (i <= n && j <= n) {
  // 1. 如果扫描了n个字符后B[i]与B[j]仍然相等，说明S有更小的循环元
  for (k = 0; k < n && s[i+k] == s[j+k]; k++);
  if (k == n) break; // s形如"aaa"时，它的循环元已扫描完成
  // 2. 如果在i+k与j+k处发现不相等
  if (s[i+k] > s[j+k]) {
    i = i + k + 1;
    if (i == j) i++;
  } else {
    j = j + k + 1;
    if (i == j) j++;
  }
}
ans = min(i, j); // B[ans]是最小表示
