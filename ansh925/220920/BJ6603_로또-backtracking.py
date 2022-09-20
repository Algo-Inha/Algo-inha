# https://www.acmicpc.net/problem/6603
# 로또-백트랙킹

def sol():
    if len(stack)==6:
        print(' '.join(list(map(str,stack))))
    else:
        for i in range(1,s[0]+1):
            if not stack:
                stack.append(s[i])
                sol()
                stack.pop()
            elif s[i] > stack[-1]:
                stack.append(s[i])
                sol()
                stack.pop()

while True:
    s=list(map(int,input().split()))
    if s[0] == 0:
        break
    stack=[]    
    sol()
    print()