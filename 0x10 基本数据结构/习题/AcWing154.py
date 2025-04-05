N = 1000006
a, q = [0]*N, [0]*N

def main():
    n, k = [int(x) for x in input().split()]
    a[1:n+1] = [int(x) for x in input().split()]
    
    l, r = 0, -1
    for i in range(1, n+1):
        while l<=r and q[l]<=i-k: l += 1
        while l<=r and a[q[r]]>=a[i]: r -= 1
        r += 1; q[r] = i
        if i >= k: print("%d " %a[q[l]], end='')
    print()
    
    l, r = 0, -1
    for i in range(1, n+1):
        while l<=r and q[l]<=i-k: l += 1
        while l<=r and a[q[r]]<=a[i]: r -= 1
        r += 1; q[r] = i
        if i >= k: print("%d " %a[q[l]], end='')
    
main()