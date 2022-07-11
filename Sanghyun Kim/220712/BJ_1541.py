# https://www.acmicpc.net/problem/1541
# 잃어버린 괄호

# (-) 만나면, 다음 (-) 만날 때까지 괄호
# (-) 기준으로 나누기
arr = input().split('-')
total = 0

# 맨 처음 문자는 숫자이므로
for i in arr[0].split('+'):
  total += int(i)

# 모두 더해서 빼기
for i in arr[1:]:
  for j in i.split('+'):
    total -= int(j)
print(total)
