N = 1006
ch2n, n2ch = [0]*200, [0]*200
s, ans = [0]*N, [0]*N

def NUMVER_BASE_CONVERSION():
    a, b, c = input().split()
    a, b, s[:len(c)] = int(a), int(b), list(c)
    print(f"{a} {c}\n{b} ", end='')
    _len, t, i = len(c), len(c), 0
    while t:
        k = 0
        for j in range(_len-t, _len):
            k = k*a + ch2n[ord(s[j])]
            s[j] = n2ch[k//b]
            k %= b
        ans[i] = n2ch[k]
        while t>0 and s[_len-t]=='0': t -= 1
        i += 1
    for j in range(i-1, -1, -1): print(ans[j], end='')
    print("\n")

def main():
    t = 0
    for i in range(ord('0'), ord('9')+1):
        ch2n[i] = t; n2ch[t] = chr(i); t += 1
    for i in range(ord('A'), ord('Z')+1):
        ch2n[i] = t; n2ch[t] = chr(i); t += 1
    for i in range(ord('a'), ord('z')+1):
        ch2n[i] = t; n2ch[t] = chr(i); t += 1
    t = int(input())
    for _ in range(t): NUMVER_BASE_CONVERSION()

main()