# https://www.acmicpc.net/problem/1244
# 스위치 켜고 끄기- BJ_1244

import sys
input = sys.stdin.readline

n = int(input())    # 100 이하 자연수
switch = list(map(int, input().split()))    # n개 스위치 상태
nStu = int(input())     # 학생 수
for i in range(nStu):
    s, num = map(int, input().split())    # 성별, 받은 수
    num -= 1
    if s == 1:  # 남학생일 경우
        for j in range(num, n, num + 1):
            if switch[j] == 1:
                switch[j] = 0
            elif switch[j] == 0:
                switch[j] = 1
    elif s == 2:    # 여학생일 경우
        temp = 0
        while (0 <= num - temp and num + temp < n):
            if switch[num - temp] == switch[num + temp]:
                if switch[num - temp] == 1:
                    switch[num - temp] = 0
                    switch[num + temp] = 0
                elif switch[num - temp] == 0:
                    switch[num - temp] = 1
                    switch[num + temp] = 1
            else:
                break
            temp += 1

if len(switch) <= 20:   # 스위치 길이 21보다 작을 때
    print(*switch)
else:   # 스위치 길이 20보다 클 때
    for i in range(len(switch)):
        print(switch[i], end=' ')
        if (i + 1) % 20 == 0:
            print()