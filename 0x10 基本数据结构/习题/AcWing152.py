N = 1006
a = [[0]*N for _ in range(N)]
t, n, m, h, s, w = 0, 0, 0, [0]*N, [0]*N, [0]*N

def ddz(k):
    for i in range(1, m+1):
        if a[k][i] == 'F': h[i] += 1
        else: h[i] = 0
    ans, p = 0, 0
    for i in range(1, m+2):
        if h[i] > s[p]:
            p += 1; s[p] = h[i]; w[p] = 1
        else:
            width = 0
            while s[p] > h[i]:
                width += w[p]
                ans = max(ans, width * s[p])
                p -= 1
            p += 1; s[p] = h[i]; w[p] = width+1
    return ans
    
def main():
    global t, n, m
    n, m = [int(x) for x in input().split()]
    for i in range(1, n+1):
        a[i][1:m+1] = input().split()
    ans = 0
    for i in range(1, n+1): ans = max(ans, ddz(i))
    print(3*ans)

main()