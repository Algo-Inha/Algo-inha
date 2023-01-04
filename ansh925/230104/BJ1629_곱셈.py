# https://www.acmicpc.net/problem/1629
# 곱셈 - 분할정복(Devide and Conquer)

a,b,c = map(int,input().split())

def DnC(x,y):
    if y==1:
        return x % c
    tmp = DnC(x, y//2)
    
    if y % 2 == 0:
        return tmp * tmp % c
    else:
        return tmp * tmp * x % c

print(DnC(a,b))