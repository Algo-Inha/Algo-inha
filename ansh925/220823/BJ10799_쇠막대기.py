# https://www.acmicpc.net/problem/10799
# 쇠막대기
import sys
input = sys.stdin.readline

lst=input().rstrip()
ray=lst.replace('()','#')       # 레이저 부분 replace

ans=0
stack=[]
for i in range(len(ray)):
    if ray[i]=='(':             # 쇠막대기 시작할때 stack push
        stack.append('*')
    elif ray[i]==')':           # 쇠막대기 끝날때 stack pop하고 1개 절단 ++
        stack.pop()
        ans += 1
    else:                       # 레이저면 stack에 쌓인 쇠막대기 수만큼 ++
        ans += len(stack)
print(ans)