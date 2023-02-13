import sys
input = sys.stdin.readline

N,K = map(int,input().split())

answer = 0
count = 0
while(1):
    if N == K:
        break
    else:
        if N % 2 == 0:
            N = N//2
        else:
            N = N//2 + 1
            answer += 2**count
        count += 1

print(answer)