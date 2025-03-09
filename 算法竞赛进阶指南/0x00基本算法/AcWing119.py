from math import inf, sqrt
N = 100006
p, tmp = [[0]*3 for _ in range(N*2)], [[0]*3 for _ in range(N*2)]

def dist(a, b):
    if a[2] == b[2]: return inf
    return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]))

def s(l, r):
    if l == r: return inf
    if l+1 == r: return dist(p[l], p[r])
    mid = (l+r)>>1
    ans = min(s(l, mid), s(mid+1, r))
    
    i, j = l, mid+1
    for k in range(l, r+1):
        if j>r or (i<=mid and p[i][1]<=p[j][1]): tmp[k] = p[i]; i += 1
        else: tmp[k] = p[j]; j += 1
    for k in range(l, r+1): p[k] = tmp[k]
    
    k = 0
    for i in range(mid, l-1, -1):
        if k >= 6: break
        if p[mid][0]-ans <= p[i][0] <= p[mid][0]+ans: tmp[k] = p[i]; k += 1
    for i in range(mid+1, r+1):
        if k >= 12: break
        if p[mid][0]-ans <= p[i][0] <= p[mid][0]+ans: tmp[k] = p[i]; k += 1
    
    for i in range(1, k):
        for j in range(i-1, -1, -1):
            if tmp[i][1] - tmp[j][1] < ans: ans = min(ans, dist(tmp[i], tmp[j]))
    return ans
    
def Raid():
    n = int(input())
    for i in range(1, n+1):
        p[i][:2] = map(int, input().split())
        p[i][2] = 0
    for i in range(1, n+1):
        p[i+n][:2] = map(int, input().split())
        p[i][2] = 1
    p[1:2*n+1] = sorted(p[1:2*n+1], key=lambda x: x[0])
    print("%.3f" % s(1, 2*n))
    
def main():
    t = int(input())
    for _ in range(t): Raid()

main()