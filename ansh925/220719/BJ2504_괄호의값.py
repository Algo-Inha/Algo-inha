# https://www.acmicpc.net/problem/2504
# 괄호의 값

stack=[]
tmp=1; ans=0

lst=list(input())

for i in range(len(lst)):       
    if lst[i]=='(':             # '(' 이면 2곱하고 stack에 저장
        tmp *= 2
        stack.append(lst[i])
    elif lst[i]=='[':           # '[' 이면 3곱하고 stack에 저장
        tmp *= 3
        stack.append(lst[i])

    elif lst[i]==')':           # ')' 일 때,
        if not stack or stack[-1]=='[':
            ans=0
            break               # 매칭 안되면 0 출력
        if lst[i-1]=='(':
            ans += tmp          # 이전 '('와 매칭되면 ans에 누적
        tmp //= 2
        stack.pop()             # '()' 이므로 2 나눠주고 stack pop

    else:                       # ']' 일 때,
        if not stack or stack[-1]=='(':
            ans=0
            break               # 매칭 안되면 0 출력
        if lst[i-1]=='[':
            ans += tmp          # 이전 '['와 매칭되면 ans에 누적
        tmp //= 3
        stack.pop()             # '[]' 이므로 3 나눠주고 stack pop

if stack:       # stack에 괄호가 남았으면 매칭 안된거이므로 0 출력
    ans=0

print(ans)