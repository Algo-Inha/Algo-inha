# https://www.acmicpc.net/problem/2504
# 괄호의 값

import sys
input=sys.stdin.readline

lst=list(input().rstrip())

s=[]                                # stack 선언
for i in lst:
    if i=='(' or i=='[':            # (1): '(' 또는 '[' 인 경우 stack에 저장
        s.append(i)

    elif i==')':                    # (2): ')' 인 경우
        t=0
        while len(s) != 0:
            tmp=s.pop()             # stack pop해서 tmp에 저장
            if tmp=='(':            # 소괄호와 매칭 되면
                if t==0:
                    s.append(2)     # 저장해둔 수가 없으면 +2
                else:
                    s.append(2*t)   # 저장해둔 수가 있으면 x2
                break
            elif tmp=='[':          # 괄호 매칭 안되면 0 출력 및 종료
                print(0); exit(0)
            else:                   # stack pop(tmp)가 괄호가 아닌 숫자인 경우 더하기
                t = t+int(tmp)
    
    elif i==']':                    # (3): ']' 인 경우 - (2)의 경우와 동일
        t=0
        while len(s) != 0:
            tmp=s.pop()             # stack pop해서 tmp에 저장
            if tmp=='[':            # 대괄호 매칭 되면
                if t==0:
                    s.append(3)     # 저장해둔 수가 없으면 +3
                else:
                    s.append(3*t)   # 저장해둔 수가 있으면 x2
                break
            elif tmp=='(':
                print(0); exit(0)
            else:
                t = t+int(tmp)

ans=0
for i in s:                         # 입력lst 다 돌고 나서 남은 stack에서
    if i=='(' or i=='[':            # stack에 괄호가 남아 있으면 매칭 안된거이므로
        print(0); exit(0)           # 0 출력 및 종료
    else:
        ans += i                    # 매칭이 잘 되었으면 stack에 저장된 수들 더해서 출력
print(ans)