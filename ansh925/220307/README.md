## 숫자 문자열과 영단어
### PG81301

```python
def solution(s):
    answer = s
    answer=answer.replace('zero','0')
    answer=answer.replace('one','1')
    answer=answer.replace('two','2')
    answer=answer.replace('three','3')
    answer=answer.replace('four','4')
    answer=answer.replace('five','5')
    answer=answer.replace('six','6')
    answer=answer.replace('seven','7')
    answer=answer.replace('eight','8')
    answer=answer.replace('nine','9')    
    return int(answer)
```
> - 입력받은 문자열에서 각각에 해당하는 부분을 replace 함수로 변환해주면 끝인 단순한 문제였다.   
> - 설마 이게 맞나? 하면서 제출했지만 정말 맞았던 문제.
   

## 비밀지도
### PG17681

```python
def solution(n, arr1, arr2):
    answer = []
    arr1_bi=[]
    arr2_bi=[]
    for i in range(n):
        arr1_bi.append(bin(arr1[i])[2:])
        arr2_bi.append(bin(arr2[i])[2:])
        arr1_bi[i]=('0' * (n-len(arr1_bi[i]))) + arr1_bi[i]
        arr2_bi[i]=('0' * (n-len(arr2_bi[i]))) + arr2_bi[i]

        tmp=''
        for j in range(n):
            if arr1_bi[i][j]=='1' or arr2_bi[i][j]=='1':
                tmp+='#'
            elif arr1_bi[i][j]=='0' and arr2_bi[i][j]=='0':
                tmp+=' '
        answer.append(tmp)
    return answer
```
> - 각각의 지도 정보를 리스트에 넣은뒤 파이썬의 bin함수를 이용해서 이진수 변환을 했다. 그리고 새로운 리스트에 이진수 각 자리값을 넣어서 두 지도의 벽 위치를 저장한다.   
> - 문제의 조건에 따라 두 지도(두 리스트)의 값을 or와 and 조건의 if문으로 비밀지도를 구성한 후 출력한다.   

```python
def solution(n, arr1, arr2) :
    result = []
    
    for j in range(0,len(arr1)) :
        tmp = ''
        num = arr1[j] | arr2[j]

        for i in range(0, n) :
            if num % 2 == 0 :
                tmp = ' ' + tmp
            else : 
                tmp = '#' + tmp
            num = int(num / 2)
        result.append(tmp)
    return result
```   
> - 다른 사람의 풀이를 보다가 이런식으로 풀어도 되는것을 확인했다. 리스트가 아니라 ''꼴으로 바로 비밀지도 벽에 해당하는 문자열을 출력하는 방식으로 보인다.
   
   
## 의견
- 2주전부터 파이썬을 처음으로 공부를 시작했다. 백준에서 쉬운 난이도의 문제들을 파이썬으로 풀어가며 대강의 감을 잡았고, 이번에 처음으로 스터디 문제를 파이썬으로 시도해봤다. 첫번째 문제부터 문자열 문제. cpp였다면 모르겠지만 파이썬의 replace 함수를 알게되어서 바로 적용해보았고, 정답이었다.   
아직은 파이썬 언어에 대해 전반적으로 모르는 부분이 많지만, 알면 알수록 진작에 파이썬 공부할걸 이라는 생각이 많이 든다.   
- 이번에는 프로그래머스 2문제만 해결했고, 나머지 문제는 시도해봤지만 해결하지 못했다. 주말을 이용해 인터넷의 풀이 코드를 보면서 봐도 제대로는 이해하지 못한것 같다. 여전히 골드는 어려움..
