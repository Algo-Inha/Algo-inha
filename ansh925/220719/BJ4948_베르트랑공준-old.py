# https://www.acmicpc.net/problem/4948
# 베르트랑 공준

# '에라토스테네스의 체'
def sol(x):
    if x ==1:                           # 1 제외
        return False
    for i in range(2, int(x**0.5)+1):   # 2부터 루트(x)까지
        if x%i==0:					    # 약수가 있는 경우 제외
            return False
    return True						    # 위 두 경우가 아닌 경우가 소수

while True:
    n = int(input())

    count=0
    if n == 0 :						    # 0 입력시 종료
        break
    for i in range(n, 2*n+1):		    # n~2n 범위에 소수인 경우(sol) count++
        if sol(i): count+=1
    print(count)