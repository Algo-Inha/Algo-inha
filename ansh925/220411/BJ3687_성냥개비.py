# https://www.acmicpc.net/problem/3687
# 성냥개비
import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    ans_min=[0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22]    # 성냥개비로 만들수있는 최소 수(0~7에서만 미리 선언)
    ansMax='7'*(n%2) + '1'*(n//2-(n%2))             # 성냥개비로 만들수있는 최대 수 구하는 식

    if n<=10:    # 한자리 수 일때는 그대로 출력
        print(ans_min[n], ansMax)
        continue

    ansMin=''
    while n>0:
        n=n-7
        if n>=0:
             ansMin=ansMin+'8'
        else: 
            n=n+7
            break

    small={6:6, 2:1, 5:2}
    if n in small: 
        ansMin=str(small[n])+ansMin
    else: 
        if n==1: 
            ansMin='10'+ansMin[1:]
        elif n==3: 
            ansMin='200'+ansMin[2:]
        elif n==4: 
            ansMin='20'+ansMin[1:]
    print(ansMin, ansMax)