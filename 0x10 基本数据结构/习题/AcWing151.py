nums, ops = [], []

def calc():
    b = nums.pop()
    a = nums.pop()
    c = ops.pop()
    if c == '+': d = a + b
    elif c == '-': d = a - b
    elif c == '*': d = a * b
    elif c == '/': d = int(a / b)
    else: d = a**b
    nums.append(d)
    
def main():
    s = input()
    s = '(' + s + ')'
    l, r = 0, 0
    for i in range(len(s)):
        if s[i] == '(': l += 1
        if s[i] == ')': r += 1
    if l >= r: s = s + ')'*(l-r)
    else: s = '('*(r-l) + s
    i = 0
    while i < len(s):
        if s[i].isdigit():
            j, t = i, 0
            while s[j].isdigit(): t = t*10 + ord(s[j])-ord('0'); j += 1
            i = j-1
            nums.append(t)
        else:
            c = s[i]
            if c == '(': ops.append(c)
            elif c == ')':
                while ops[-1] != '(': calc()
                ops.pop()
            elif c == '+' or c == '-':
                if c=='-' and i and not s[i-1].isdigit() and s[i-1]!=')':
                    if s[i+1] == '(':
                        nums.append(-1); ops.append('*')
                    else:
                        j, t = i+1, 0
                        while s[j].isdigit(): t = t*10 + ord(s[j])-ord('0'); j += 1
                        i = j-1
                        nums.append(-t)
                else:
                    while ops[-1] != '(': calc()
                    ops.append(c)
            elif c == '*' or c == '/':
                while ops[-1]=='*' or ops[-1]=='/' or ops[-1]=='^': calc()
                ops.append(c)
            elif c == '^':
                while ops[-1] == '^': calc()
                ops.append(c)
        i += 1
    print(nums[-1])
    
main()