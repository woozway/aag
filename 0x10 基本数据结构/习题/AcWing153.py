N = 1010
n, g, a, f, color = 0, [[0]*N for _ in range(N)], [0]*N, [0]*N, [0]*N

def dfs(u, c):
    global n
    color[u] = c
    for j in range(1, n+1):
        if not g[u][j]: continue
        if color[j]:
            if color[j] == c: return False
        elif not dfs(j, 3-c): return False
    return True
    
def check(a, b):
    if a == b: return True
    if a > b: a, b = b, a
    return (a=='a' and b=='d') or (a=='b' and b=='c')
    
def main():
    global n
    n = int(input())
    a[1:n+1] = [int(x) for x in input().split()]
    f[n+1] = n+1
    for i in range(n, 0, -1): f[i] = min(a[i], f[i+1])
    
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            if a[i]<a[j] and f[j+1]<a[i]:
                g[i][j] = g[j][i] = 1
    
    for i in range(1, n+1):
        if not color[i] and not dfs(i, 1):
            print("0")
            return
    
    ans = []
    s1, s2, cur = [], [], 1
    for i in range(1, n+1):
        if color[i] == 1: s1.append(a[i]); ans.append('a')
        else: s2.append(a[i]); ans.append('c')
        while (s1 and s1[-1]==cur) or (s2 and s2[-1]==cur):
            if s1 and s1[-1]==cur: s1.pop(); cur += 1; ans.append('b')
            else: s2.pop(); cur += 1; ans.append('d')
    for i in range(len(ans)):
        j = i+1
        while j<len(ans) and check(ans[i], ans[j]): j += 1
        ans[i:j] = sorted(ans[i:j])
        i = j
    for c in ans: print("%c " %c, end='')
    
main()