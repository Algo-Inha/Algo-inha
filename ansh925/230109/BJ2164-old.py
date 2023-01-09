# https://www.acmicpc.net/problem/2164
# 카드2 - old

n = int(input())
lst = list(range(1, n+1))

while (len(lst)>1):
    lst.pop(0)
    temp = lst.pop(0)
    lst.append(temp)

print(lst.pop(0))