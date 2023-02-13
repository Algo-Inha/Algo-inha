import sys
input = sys.stdin.readline

d, k = map(int,input().split()) # d = 할머니가 넘어온 날, k = 호랑이에게 준 떡의 개수

A_Coef = 0
B_Coef = 0

f1, f2 = 1, 2

first = 0
second = 0

if d == 3:
    A_Coef = 1
    B_Coef = 1
elif d == 4:
    A_Coef = 1
    B_Coef = 2
else:
    for i in range(d-4):
        f1, f2 = f2, f1 + f2


    A_Coef = f1
    B_Coef = f2

for A in range(1, 100001):
    for B in range(2, 100001):
        if (A_Coef*A + B_Coef*B) == k:
            first = A
            second = B
            break
    if (A_Coef*A + B_Coef*B) == k:
        break

print(first)
print(second)