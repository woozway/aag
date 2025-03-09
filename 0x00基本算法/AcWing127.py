from bisect import bisect_left
N, M = 100006, 100006
p = [[0]*2 for _ in range(N)]
t = [[] for _ in range(M)]
n, m = 0, 0

def Task():
    global n, m
    for i in range(1, n+1):
        x, y = map(int, input().split())
        t[y].append(x)
    for i in range(101): t[i].sort()
    for i in range(1, m+1): p[i] = [int(x) for x in input().split()]
    p[1:m+1] = sorted(p[1:m+1], key=lambda x: (x[0], x[1]), reverse=True)
    ans, ansa = 0, 0
    for i in range(1, m+1):
        flag = 0
        for j in range(p[i][1], 101):
            s = len(t[j])
            it = bisect_left(t[j], p[i][0])
            if it != s:
                t[j].pop(it)
                flag = 1
                break
        if flag:
            ans += 1
            ansa += 500*p[i][0] + 2*p[i][1]
    print(ans, ansa)

def main():
    global n, m
    n, m = map(int, input().split())
    Task()
    
main()