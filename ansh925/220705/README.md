## 후보 추천하기
### BJ 1713

```python
import sys
input=sys.stdin.readline

img=[]      # 사진틀 리스트
index=[]    # 추천수 리스트
n=int(input())      # 사진틀 수
m=int(input())      # 추천수
k=list(map(int,input().split()))    # 추천받은 학생의 번호

for i in range(m):
    if k[i] in img:     # 이미 사진틀에 있을 경우
        for j in range(len(img)):   
            if k[i] == img[j]:  # 추천 학생과 사진틀 학생이 같으면
                index[j] += 1   # 추천수++
    else:
        if len(img) >= n:       # 사진틀에 없고, 사진틀이 꽉 차있는 경우
            for j in range(n):
                if index[j] == min(index):  # 추천수 가장 적은 학생
                    del img[j]              # 사진틀에서 지우고
                    del index[j]            # 추천수도 삭제
                    break
        img.append(k[i])    # 지운 뒤에 새로운 사진 추가 & 추천수 1
        index.append(1)
        
img.sort()      # 추천받은 학생 번호 순 정렬
print(' '.join(map(str,img)))
```

> - 사진틀, 추천수 리스트 생성
> - 추천 받은 학생이 이미 사진틀에 있고, 사진틀의 사진과 같은 경우 추천수++
> - 사진틀에 없고, 사진틀이 꽉차 있으면, 추천수가 가장 적은 학생 찾아서 사진, 추천수 삭제
> - 꽉차서 삭제한 후 또는 원래부터 사진틀에 없는 경우 사진 추가하고 추천수 설정
> - 학생 번호순으로 정렬 후 출력


## 나무 자르기
### BJ 2805
```python
import sys
input=sys.stdin.readline

n,m =map(int,input().split())
tree=list(map(int,input().split()))

left=1; right=sum(tree)     # 이분 탐색

while left <= right:
    mid=(left+right)//2
    cnt=0
    for i in tree:
        if i > mid:
            cnt += i-mid

    if cnt >= m:
        left = mid+1
    else:
        right = mid-1
print(right)
```
> - 나무 길이 전체에 대해서 왼쪽, 오른쪽 끝 지정
> - 왼쪽, 오른쪽의 중간을 찾아가며 이분 탐색
> - 자른 나무의 합이 m이 되면 왼쪽에 추가, 아니면 오른쪽에 추가하며 반복
> - 이분 탐색을 전부 진행한 뒤, 자르고 남은 나무의 최대 길이인 오른쪽 값 출력
> - 지난주에 이어 이분 탐색을 한번 더 다뤄볼 수 있었던 기회

## DFS와 BFS
### BJ 1260
```python
def DFS(v):
    visit1[v]=1
    print(v,end=' ')
    for i in range(1,n+1):
        if visit1[i]==0 and tree_arr[v][i]==1:
            DFS(i)

def BFS(v):
    queue=[v]
    visit2[v]=1
    while queue:
        v=queue.pop(0)
        print(v,end=' ')
        for i in range(1,n+1):
            if visit2[i]==0 and tree_arr[v][i]==1:
                queue.append(i)
                visit2[i]=1
                
n,m,v=map(int,input().split())
tree_arr=[[0]*(n+1) for i in range(n+1)]
visit1=[0]*(n+1)
visit2=[0]*(n+1)

for i in range(m):
    a,b=map(int,input().split())
    tree_arr[a][b]=tree_arr[b][a]=1

DFS(v)
print()
BFS(v)
```
> - 이전에 풀었었던 문제. DFS와 BFS의 기본적인 틀을 다루는 문제인데, 오랜만이라고 그새 헷갈렸다.

## 가장 큰 수
### PG 42746
```python
def solution(numbers):
    numbers_str = list(map(str,numbers))              # string으로 list 변환
    numbers_str.sort(key=lambda x:x*3, reverse=True)  # 각 문자열 3번 반복(3자리 수로 맞춰서 비교) 후, 내림차순 정렬

    return str(int(''.join(numbers_str)))             # 문자열을 이어 붙여서 int로 변환 후, 다시 string으로 출력
```
> - 크기를 비교할 때 3자리 수로 맞추어 ASCII 값을 비교하는 부분에서 x3 해주는 생각을 어떻게 한건지 모르겠다.
> - 그 외에는 풀이를 보고 이해할 수 있는 정도

## 시그널
### BJ16113
```python
blank = ['.','.','.','.','.']
zero = ['#','#','#','#','#','#','.','.','.','#','#','#','#','#','#']
one = ['#','#','#','#','#']
two = ['#','.','#','#','#','#','.','#','.','#','#','#','#','.','#']
three = ['#','.','#','.','#','#','.','#','.','#','#','#','#','#','#']
four = ['#','#','#','.','.','.','.','#','.','.','#','#','#','#','#']
five = ['#','#','#','.','#','#','.','#','.','#','#','.','#','#','#']
six = ['#','#','#','#','#','#','.','#','.','#','#','.','#','#','#']
seven = ['#','.','.','.','.','#','.','.','.','.','#','#','#','#','#']
eight = ['#','#','#','#','#','#','.','#','.','#','#','#','#','#','#']
nine = ['#','#','#','.','#','#','.','#','.','#','#','#','#','#','#']
```
> - 풀이를 봤음에도 이해 아직 부족
> - 위처럼 숫자마다 신호를 지정해주고 푸는 방식을 많이 찾아봤는데, 이후의 과정 이해 못함
