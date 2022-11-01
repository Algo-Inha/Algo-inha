# https://www.acmicpc.net/problem/3568
# iSharp

lst = input().split(' ')
tmp = lst[0]
del lst[0]

for s in lst:
    s = s.replace(",", '')
    s = s.replace(";", '')
    print(tmp, end='')

    for i in range(len(s)-1,0,-1):
        if not s[i].isalpha():
            if s[i] == ']':
                print('[', end='')
            elif s[i] == '[':
                print(']', end='')
            else:
                print(s[i], end='')
    print(' ', end='')

    for i in range(len(s)):
        if s[i].isalpha():
            print(s[i], end='')
    print(';')