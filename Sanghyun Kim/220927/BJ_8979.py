# https://www.acmicpc.net/problem/8979
# 올림픽- BJ_8979

n, k = map(int, input().split())
country = [[] for _ in range(n)]

for i in range(n):
    c, gold, silver, bronze = map(int, input().split())
    country[c - 1] = [gold, silver, bronze, c]

# 금메달이 많은 순으로 정렬을 하고
# 금메달이 같다면 은메달,
# 은메달이 같다면 동메달이 많은 순으로 정렬
country.sort(key=lambda x: (-x[0], -x[1], -x[2]))

count = [1]

for i in range(n):
    if i > 0:
        if country[i][0]==country[i-1][0] and country[i][1]==country[i-1][1] and country[i][2]==country[i-1][2]:
            count.append(count[-1])
        else:
            count.append(i+1)
    if country[i][3] == k:
        print(count[i])
        break