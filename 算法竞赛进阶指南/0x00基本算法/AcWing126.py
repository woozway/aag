from math import inf
N = 106
a = [[0]*N for _ in range(N)]

def rd(n):
    nums = []
    while True:
        try:
            line = input().strip()
            nums.extend(map(int, line.split()))
        except:
            break
    for i in range(1, n+1):
        a[i][1:] = nums[(i-1)*n:(i*n)]
    return a
    
def main():
    n = int(input())
    a = rd(n)
    ans = -inf
    for i in range(1, n+1):
        x = [0]*N
        for j in range(i, n+1):
            num = 0
            for k in range(1, n+1):
                x[k] += a[j][k]
                num += x[k]
                ans = max(ans, num)
                if num < 0: num = 0
    print(ans)
    
main()