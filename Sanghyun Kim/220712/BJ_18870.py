# https://www.acmicpc.net/problem/18870
# 좌표 압축

# import sys
# input = sys.stdin.readline

# n = int(input())
# x = list(map(int, input().split()))
# x_ = [0 for _ in range(n)]

# # min, max 정해
# min, max = min(x), max(x)
# # min이 0보다 작을 경우 max - min 크기의 list를 만들어
# # (-) index로 접근 가능하도록
# if min < 0:
#   coordinate = [0 for _ in range(max - min + 1)]
# else:
#   coordinate = [0 for _ in range(max + 1)]

# # 존재하는 원소 위치 ++
# for i in range(n):
#   coordinate[x[i]] += 1

# # 하나씩 비교하며 min부터 max 까지
# # 존재할 경우 count 1씩 증가시키며 좌표 압축
# count = 0 
# for i in range(min, max + 1):
#   if coordinate[i] != 0:
#     for j in range(n):
#       if x[j] == i:
#         x_[j] = count
#     count += 1

# print(*x_)
# # 메모리 초과 뜸...

import sys
input = sys.stdin.readline

n = int(input())
x = list(map(int, input().split()))

# set : 중복 제거
# sorted : 오름차순
x_ = sorted(list(set(x)))

# dictionary 사용 {원소, 원소 index}
dic_x = {x_[i] : i for i in range(len(x_))}
# list x의 원소에 대해
for i in x:
  # key i에 대한 value 값 출력 후 띄어쓰기
  print(dic_x[i], end = ' ')