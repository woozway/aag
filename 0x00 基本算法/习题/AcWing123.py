N = 10006
n, x, y = 0, [0]*N, [0]*N

def main():
    global n, x, y
    n = int(input())
    for i in range(1, n+1): x[i], y[i] = map(int, input().split())
    x[1:n+1] = sorted(x[1:n+1])
    y[1:n+1] = sorted(y[1:n+1])
    for i in range(1, n+1): x[i] -= i
    x[1:n+1] = sorted(x[1:n+1])
    ans = 0
    for i in range(1, n//2+1):
        ans += x[n+1-i]-x[i] + y[n+1-i]-y[i]
    print(ans)
    
main()