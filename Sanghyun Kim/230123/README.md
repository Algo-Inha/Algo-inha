# Solving

## 센서
https://www.acmicpc.net/problem/2212
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
k = int(input())
sensor = list(map(int,input().split()))
sensor.sort()

array = []
for i in range(n - 1):
    array.append(sensor[i + 1] - sensor[i])

array.sort()

print(sum(array[:n - k]))
```
### 의견
구현으로 풀어내려 했지만.. 해결하지 못했다.
구글링을 해보니 골드라고 하기엔 쉬운 문제였다.
다음에 다시 나오면 풀 수 있을까?


## N과 M (12)
https://www.acmicpc.net/problem/15666
### 문제풀이
```python
from itertools import combinations_with_replacement
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
nLi = list(set(list(map(int, input().split()))))
nLi.sort()

ans = list(set(list(combinations_with_replacement(nLi, m))))
for i in reversed(range(m)):
    ans.sort(key=lambda x:x[i])

for i in range(len(ans)):
    print(*ans[i])
```
combinations_with_replacement 내장함수를 사용해 중복조합
### 의견
모든 경우의 수를 구하려 했는데, 메모리 초과가 발생하여 중복조합 사용해 해결