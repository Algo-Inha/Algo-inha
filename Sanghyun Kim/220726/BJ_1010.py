# https://www.acmicpc.net/problem/1010
# 다리놓기- BJ_1010

def factorial(num):
    total = 1
    for i in range(1, num + 1):
        total *= i
    return total

for _ in range(int(input())):
    n, m = map(int, input().split())
    if m - n == 0:
        print(1)
    else:
        print(factorial(m) // (factorial(m - n) * factorial(n)))    
