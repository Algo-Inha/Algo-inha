### Python Code Usages
## list
```python
list_a = []
list_a.append(3) # 뒤에 3 추가
list_a.append(4) # 뒤에 4 추가
list_a.append(5) # 뒤에 5 추가
top_elem = list_a.pop()
print(top_elem) # 5
print(list_a) # [3,4]
```

## Deque
single thread 등 코딩테스트 환경에선 queue보다 deque가 빠르므로 deque 사용
stack도 list로 사용 가능하지만 deque로도 빠르게 사용 가능
```python
from collections import deque
deque_obj = deque()
deque_obj.append(10) # 오른쪽 끝에 삽입
deque_obj.append(20) # 오른쪽 끝에 삽입
deque_obj.appendleft(40) # 왼쪽 끝에 삽입
deque_obj.appendleft(50) # 왼쪽 끝에 삽입
print(deque_obj) # [50,40,10,20]
right_elem = deque_obj.pop()
left_elem = deque_obj.popleft()
print(right_elem) # 20
print(left_elem) # 50
print(deque_obj)
print(len(deque_obj))
```
`deque를 queue처럼 사용할 때엔 append 및 popleft()를 사용`

## Itertools
```python
import itertools
comb = itertools.combinations([1,2,3,4],3)  # [1,2,3,4] 에서 3개를 뽑는 방법 (조합)
print(list(comb))
perm = itertools.permutations([1,2,3,4],3)  # [1,2,3,4] 에서 3개를 배열하는 방법 (배열)
print(list(perm))
```
`실제로 사용할 때엔 iterator이므로 list로 형변환 하지 말고 for문으로 하나씩 만들기`

## List index 접근
```python
tmplist = [1,2,3,4,5,6,7,8]
tmp_a = tmplist[2:5]   # 2번 인덱스부터 5번 인덱스 전까지
tmp_b = tmplist[:5]    # 처음부터 5번 인덱스 전까지
tmp_c = tmplist[2:]    # 2번 인덱스부터 마지막까지
tmp_d = tmplist[2:5:2] # 2번 인덱스부터 5번 인덱스 전까지 2개씩 뛰어가며
tmp_e = tmplist[2:-2]   # 2번 인덱스부터 마지막 2개 이전까지
print(tmp_a)           # [3, 4, 5]
print(tmp_b)           # [1, 2, 3, 4, 5]
print(tmp_c)           # [3, 4, 5, 6, 7, 8]
print(tmp_d)           # [3, 5]
print(tmp_e)           # [3, 4, 5, 6]
print(tmplist[-2])     # 7
```

## dict
```python
a = dict()  # a = {}
a["keyA"] = "valueA"
a["keyB"] = "valueB"
for key in a.keys():
    print("KEY : {}, Val : {}".format(key, a[key]))
```

## set
```python
set_object = set()
set_object.add(1)
set_object.add(1)
set_object.add(2)
set_object.add(3)
print(set_object) # 1,2,3
set_object_b = set([2,3,4])
print(set_object_b) # 2,3,4

print(set_object & set_object_b)  # 교집합 {2,3}
print(set_object - set_object_b)  # 차집합 {1}
print(set_object | set_object_b)  # 합집합 {1,2,3,4}

set_object.remove(3)
print(set_object)

set_object.remove(3) # Error
```

## range
```python
print(list(range(3,5))) # 출력 3,4
```