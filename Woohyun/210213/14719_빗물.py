import sys
input = sys.stdin.readline

h, w = map(int,input().split())
li = list(map(int,input().split()))


total = 0
l_max = 0
r_max = 0


for i in range(1, len(li) - 1):
    l_max = max(li[:i])
    r_max = max(li[i+1:])

    if li[i] < min(l_max,r_max):
        total += min(l_max,r_max) - li[i]

print(total)

