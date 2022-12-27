## 오르막수
### BJ11057
https://www.acmicpc.net/problem/11057

```python
n = int(input())
dp = [1 for i in range(10)]

for i in range(n-1):
    for j in range(10):
        dp[j] = sum(dp[j:])
print(sum(dp) % 10007)
```
> 이전에 유사한 문제 풀었던 기억이 있어 DP 활용해서 푸는건 알겠는데 점화식을 찾지 못해서 헤맸습니다.


## 흙길보수하기
### BJ1911
https://www.acmicpc.net/problem/1911

```python
N, L = map(int, input().split())
pool = [list(map(int, input().split())) for _ in range(N)]

pool.sort(key=lambda x:x[0])    # 웅덩이 정렬
cur,cnt = 0,0       # 마지막 널빤지 위치, 널빤지 갯수

for s, e in pool:
    if s > e:
        continue    
    if cur > s:     # 이전 널빤지가 현재 웅덩이와 겹치는 경우 
        s = cur
    while s < e:    # 널빤지 개수
        s += L
        cnt += 1
    cur = s
print(cnt)
```
> 웅덩이를 정렬한 후, 차례대로 웅덩이를 널빤지로 덮고 다음 웅덩이를 덮을때 겹치는 경우를 제외하고 덮아가는 방식으로 그리디 탐색.

> - 취업+연말연초 약속으로 오래동안 코테를 안했더니 머리가 새하얘졌습니다. 스터디 문제와 더불어 기본적인 알고리즘 문제부터 다시 감 잡아갈게요. python도 너무 오래만에 씀요..
