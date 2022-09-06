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
n=int(input())
ans=0
for i in range(n,1000001):
    if str(i) == str(i)[::-1]:
        if sosu(i):
            ans=i
            break
if ans==0:
    ans=1003001
print(ans)