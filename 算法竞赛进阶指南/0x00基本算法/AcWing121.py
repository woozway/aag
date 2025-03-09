MAX, N = 10006, 506
xx, yy = [0]*MAX, [0]*MAX
c, n, tx, ty = 0, 0, 0, 0
x, y, s = [0]*N, [0]*N, [[0]*N for _ in range(N)]
p = [[0]*2 for _ in range(N)]

def pd(k):
    global xx, yy, c, n, tx, ty, x, y, s, p
    for i in range(xx[k], tx+1):
        for j in range(yy[k], ty+1):
            x0, y0 = 0, 0
            if x[i]-k >= 0: x0 = xx[x[i]-k]
            if y[j]-k >= 0: y0 = yy[y[j]-k]
            if s[i][j] - s[x0][j] - s[i][y0] + s[x0][y0] >= c: return 1
    return 0

def main():
    global xx, yy, c, n, tx, ty, x, y, s, p
    c, n = map(int, input().split())
    for i in range(1, n+1):
        p[i] = list(map(int, input().split()))
        xx[p[i][0]] += 1
        yy[p[i][1]] += 1

    for i in range(1, 10001):
        if xx[i]: tx += 1; x[tx] = i
        xx[i] = tx
        if yy[i]: ty += 1; y[ty] = i
        yy[i] = ty

    for i in range(1, n+1): s[xx[p[i][0]]][yy[p[i][1]]] += 1
    for i in range(1, tx+1):
        for j in range(1, ty+1):
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1]

    l, r = 1, 10000
    while l < r:
        mid = (l + r) >> 1
        if pd(mid): r = mid
        else: l = mid + 1
    print(l)

main()