# https://www.acmicpc.net/problem/1946
# 신입 사원- BJ_1946

import sys
input = sys.stdin.readline
t = int(input())

for i in range(t) :
    n = int(input())
    personLi = [0 for _ in range(n)]
    for j in range(n) :
            t1 ,t2 = map(int,input().split())
            personLi[j] = [t1,t2]

    personLiSort = sorted(personLi, key = lambda x : x[0])  # 서류 기준 정렬
    hired = 1
    man = personLiSort[0][1]
    for j in range(1,n) :
        if personLiSort[j][1] < man :   # 앞 지원자 보다 면접 성적 높으면 채용
            man = personLiSort[j][1]
            hired += 1

    print(hired)