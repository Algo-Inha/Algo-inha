# https://www.acmicpc.net/problem/1541
# 잃어버린 괄호

# 연산 결과가 최소가 되기 위해서는 (-)를 기준으로 괄호를 치면 됨
math=input().split('-')

num=[]
for i in math:          # (-)를 기준으로 split해서 입력 받은 string을 기준으로,
    sum=0
    m = i.split('+')    # (+)를 기준으로 다시 split해서 int형으로 더해줌
    for j in m:
        sum += int(j)    
    num.append(sum)     # 더한 값들을 num list에 넣어줌

ans=num[0]              # 맨 처음의 값은 기본적으로 추가하고,
for k in range(1,len(num)):
    ans -= num[k]       # 이후의 값들은 전부 빼주고 출력하면 연산 결과 최소.

print(ans)