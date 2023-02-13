import sys
input = sys.stdin.readline

# N,K = map(int,input().split())

# answer = 0
# count = 0
# while(1):
#     if N == K:
#         break
#     else:
#         if N % 2 == 0:
#             N = N//2
#         else:
#             N = N//2 + 1
#             answer += 2**count
#         count += 1

# print(answer)

import sys

n, k = map(int, input().split())

count = 0

while bin(n).count('1') > k:
    n = n + 1
    count = count + 1

print(count)