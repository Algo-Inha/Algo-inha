# https://www.acmicpc.net/problem/1747
# 소수&팰린드롬

# 소수 판별
def sosu(x):
    if x == 1:
        return False
    for i in range(2, int(x**0.5)+1):
        if x%i==0:
            return False
    return True	

# 팰린드롬 판별
def pallindrom(xx):
    x=str(xx)
    if len(x) % 2==0:
        front = x[:len(x)//2]
        back = x[len(x)//2:]
        bback = back[::-1]
        if front==bback:
            return True
    else:
        front = x[:len(x)//2+1]
        back = x[len(x)//2:]
        bback = back[::-1]
        if front==bback:
            return True

n=int(input())
while 1:
    if sosu(n) and pallindrom(n):
        break
    n+=1
print(n)