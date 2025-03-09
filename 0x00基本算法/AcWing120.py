from math import inf
N = 200006
n, t, s, e, d = 0, 0, [0]*N, [0]*N, [0]*N
def f(a, b, c):
    return (b-a)//c + 1 if b>=a else 0
    
def le(r):
    global n
    ans = 0
    for i in range(1, n+1): ans += f(s[i], min(e[i], r), d[i])
    return ans
    
def Defense():
    global n
    n = int(input())
    mins, maxe = inf, 0
    for i in range(1, n+1):
        s[i], e[i], d[i] = map(int, input().split())
        mins = min(mins, s[i])
        maxe = max(maxe, e[i])
    
    if le(maxe) % 2 == 0:
        print("There's no weakness.")
        return
    
    l, r = mins, maxe
    while l < r:
        mid = (l + r) >> 1
        if le(mid) % 2: r = mid
        else: l = mid + 1
    print(l, le(l)-le(l-1))

def main():
    global t
    t = int(input())
    for _ in range(t): Defense()
    
main()