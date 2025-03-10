from math import inf
N = 50006
p = [[0]*2 for _ in range(N)]

def main():
    n = int(input())
    for i in range(1, n+1): p[i] = list(map(int, input().split()))
    p[1:n+1] = sorted(p[1:n+1], key=lambda x: x[0]+x[1])
    ans, k = -inf, 0
    for i in range(1, n+1):
        ans = max(ans, k - p[i][1])
        k += p[i][0]
    print(ans)
    
main()