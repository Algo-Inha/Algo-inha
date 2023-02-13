import sys
input = sys.stdin.readline
# 시간초과 코드

# k = int(input())

# x = "0"

# while(1):
#     if len(x) == k:
#         break
#     for i in x:
#         if i == "0":
#             x += "1"
#         else:
#             x += "0"
#         if len(x) == k:
#             break
    

# print(x[k-1])

k = int(input())

def dp(x):
    if x == 0:
        return 0

    elif x == 1:
        return 1

    elif x % 2 == 0:
        return dp(x // 2)

    else:
        return 1 - dp(x // 2)


print(dp(k - 1))