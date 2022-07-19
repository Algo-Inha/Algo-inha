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

lst = list(range(2,246912))             # 문제의 조건에 해당하는 범위만 지정
prime_num = []
for i in lst:
    if sol(i):
        prime_num.append(i)             # 소수인 경우만 새로운 list에 저장

while True:
    n = int(input())
    count=0
    if n==0 :						    # 0 입력시 종료
        break
    for i in prime_num:
        if n < i < 2*n+1:
            count += 1                  # n~2n 범위에 소수인 경우(sol) count++ 
    print(count)