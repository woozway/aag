def main():
    s = input()
    stk = []
    ans = 0
    for i in range(len(s)):
        c = s[i]
        if not stk: stk.append(i)
        else:
            t = s[stk[-1]]
            if c==')' and t=='(' or c==']' and t=='[' or c=='}' and t=='{': stk.pop()
            else: stk.append(i)
        if stk: ans = max(ans, i - stk[-1])
        else: ans = max(ans, i + 1)
    print(ans)

main()