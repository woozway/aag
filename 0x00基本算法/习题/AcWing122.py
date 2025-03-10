N = 1000006
n, k, a, s = 0, 0, [0]*N, [0]*N

def main():
    global n, k, a, s
    n = int(input())
    for i in range(1, n+1):
        a[i] = int(input())
        k += a[i]
    
    k //= n
    for i in range(1, n+1): a[i] -= k
    s[0] = 0
    for i in range(1, n+1): s[i] = s[i-1] + a[i]
    s[1:n+1] = sorted(s[1:n+1])
    ans = 0
    for i in range(1, n//2+1): ans += s[n+1-i] - s[i]
    print(ans)

main()