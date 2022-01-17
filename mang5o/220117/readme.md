# Solving

## ����
### ���� Ǯ��

```python
import copy  # to process deep copy

row_col = input()  # input
row_num, col_num = row_col.split(" ")
row_num = int(row_num)  # type casting
col_num = int(col_num)  # type casting

map_matrix = []
not_zero = []
for y in range(row_num):
    map_line = input().split(" ")
    for x in range(len(map_line)):
        map_line[x] = int(map_line[x])  # type casting
        if map_line[x] != 0:
            not_zero.append((y, x))
    map_matrix.append(map_line)

year_count = 0
divided = False
while True:
    tmp_matrix = copy.deepcopy(map_matrix)
    now_zeros = True
    for nz in not_zero:
        y, x = nz
        if tmp_matrix[y][x] != 0:
            now_zeros = False
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if map_matrix[xy_diff[0]][xy_diff[1]] == 0:
                    tmp_matrix[y][x] = tmp_matrix[y][x] - 1
                if tmp_matrix[y][x] == 0:
                    break
    if now_zeros:
        year_count = 0
        break
    map_matrix = copy.deepcopy(tmp_matrix)
    year_count = year_count + 1

    now_group = 0
    now_x = 0
    while True:
        # check group
        check_queue = []
        now_zeros = True
        for nz in not_zero:
            y, x = nz
            if tmp_matrix[y][x] != 0:
                now_zeros = False
                tmp_matrix[y][x] = 0
                check_queue.append((y, x))
                break
        if now_zeros:
            break
        now_group = now_group + 1
        now_queue_count = 0
        while len(check_queue) > now_queue_count:
            y, x = check_queue[now_queue_count]
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if tmp_matrix[xy_diff[0]][xy_diff[1]] != 0:
                    tmp_matrix[xy_diff[0]][xy_diff[1]] = 0
                    check_queue.append(xy_diff)
            now_queue_count = now_queue_count + 1
    if now_group > 1:
        print(year_count)
        divided = True
        break
if not divided:
    print(0)
```

### �˰��� ����

�ڵ尡 �� ������ �κ����� �����Ǿ��ִµ�, ù ��°�� �� �ظ��� ���ϰ� ��� �Ϳ� ���� ó���̸�, �� ��°�� ���� ���� ���ϰ� �� ���� �׷����� �̷���� �ִ°��� ���� �׷��� �۾��̴�.

```python
# ���ϰ� ��°Ϳ� ���� ó���κ�
        if tmp_matrix[y][x] != 0:
            now_zeros = False
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if map_matrix[xy_diff[0]][xy_diff[1]] == 0:
                    tmp_matrix[y][x] = tmp_matrix[y][x] - 1
                if tmp_matrix[y][x] == 0:
                    break
```
���� ���� �ڽ��� �����¿��� ���¸� Ȯ���� �� 0�� ������ŭ �ڽ��� ���� ���ָ� �Ǵµ�, ������ 1���� matrix���� �۾��� �����Ѵٸ� ���� �ؿ� ��� ���ϵ��� ���������� ���ǰ�, �� ������ ���Ŀ� ����ϴ� ���� ���� ����� �ջ�Ǿ� ���� ������ �����.
���� �� �ڵ忡�� ���̵��� `tmp_matrix = copy.deepcopy(map_matrix)` �� deep copy�� �����Ͽ� �񱳿� ����� ���� �ٸ� matrix���� �����Ͽ���.

```python
# Grouping process
 while True:
        # check group
        check_queue = []
        now_zeros = True
        for nz in not_zero:
            y, x = nz
            if tmp_matrix[y][x] != 0:
                now_zeros = False
                tmp_matrix[y][x] = 0
                check_queue.append((y, x))
                break
        if now_zeros:
            break
        now_group = now_group + 1
        now_queue_count = 0
        while len(check_queue) > now_queue_count:
            y, x = check_queue[now_queue_count]
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if tmp_matrix[xy_diff[0]][xy_diff[1]] != 0:
                    tmp_matrix[xy_diff[0]][xy_diff[1]] = 0
                    check_queue.append(xy_diff)
            now_queue_count = now_queue_count + 1
    if now_group > 1:
        print(year_count)
        divided = True
        break
```

map matrix���� 0�� �ƴ� �� ���� ���������� ������ ��, �� ���� �̾����ִ� ���� �� 0�� �ƴ� ���� check_queue�� �ִ´�. visited ����� �ٽ� �����ϱ⿣ �޸𸮻� ���ذ� ���Ƽ� ���� ���μ������� deep copy�� �����ߴ� `tmp_matrix` ����� ������ ��Ȱ���Ѵ�. �湮�� �� �ش� ���Ҹ� 0���� �ٲٰ� queue�� ����ִ´�. �׷����� ������ �� ���� 0�� �κ��� ���ʿ� �������� �ʱ� ������ 0���� �ٲٴ°��� visited�� ������ ���ش�.


## ������
### ����Ǯ��

```python
num = int(input())
figures = input().split(" ")
sum_of_all = 0
for i in range(len(figures)):
    now_num = int(figures[i])  # type casting
    sum_of_all = sum_of_all + now_num
    figures[i] = now_num

sum_of_each_block = sum_of_all / 4

block_arr = {-1: 1}
for i in range(4):
    tmp_ba = {}
    for ba in block_arr.items():
        now_sum = 0
        now_multi = ba[1]
        start_point = ba[0]
        for pointer in range(start_point + 1, num):
            now_sum = now_sum + figures[pointer]
            if now_sum == sum_of_each_block:
                if pointer in tmp_ba:
                    tmp_ba[pointer] = tmp_ba[pointer] + now_multi
                else:
                    tmp_ba[pointer] = now_multi
    block_arr = tmp_ba

method_count = 0
for i in block_arr.items():
    if i[0] == num - 1:
        method_count = i[1]
        break

print(method_count)
```

### �˰��� ����

����� 4 �κ����� ���� ���� ������ �۾��̴ϸ�ŭ, �� ����� ���� 4�� ������ �� �κ��� �������� ������ ����� �� ������ �۾��� �����Ѵ�.
`block_arr = {-1: 1}` �ش� dictionary�� key ������ ���� ������ ��ġ, value ������ ������ �� �ִ� �������� ������ �ȴ�. �������� -1�� ���� ���� ������ ������ ���� -1�̰�, �� ���� ���� ������(�ε���)�� 0�����̱� �����̴�.
pointer�� ���� position index�� ��Ÿ����, �� ���Ǹ��� `sum_of_each_block' ����ŭ �� ���� �������� pointer�� ���������� ������ �����̸鼭 �����ϴ� pointer�� ��ġ�� dictionary�� �����Ѵ�. ���⿡ value������ ���� "������" �� �Ʒ��� ���� ����Ѵ�.
```
input (���� ����)
10
4 -1 2 1 -3 1 2 2 1 3
each value of block_arr at each step
{1: 1, 4: 1} (ù ��° ����� ����)
{3: 1, 6: 2} (�� ��° ����� ����)
{8: 3} (�� ��° ����� ����)
{9: 3} (�� ��° ����� ����)
```

# Discussion
���� ������ ������ �ڵ��̾�����, ���� �������� DFS�� BFS�� Ǯ��, ������ �������� Dynamic Programming�� ������� ������ Ǯ �� �־ �������� ���� ��µ� ���� ������ �ƴ�. �ٸ� Python���� ����Ǯ�̸� �����ϴٺ��� Ʋ�ȴٴ� ä�� ����� ���� ������ ������, �ð��ʰ��� �޸��ʰ��� ���� ����Ǯ�� ���ж�� ���â�� �ſ� ���� ����. �� ������ ���� �������� not_zero ����� ����� ���� Ƚ���� �ִ��� ���̱⵵ �ϰ�, ������ �������� Hashmap�� ������ dictionary�� ����Ͽ� �ִ��� ������ ���� �� �ֵ��� �����ϴ� ���� �ð��� ���� ��Ҵ�. ���� Pypy�� Python ����ü�� ������ ���� �ڵ带 ���� �õ��ϸ� �ð��� ���ϴ� �͵� �������� ����� �����̾��� ������ ���� �������ʹ� �ͼ��� C++�� ����Ͽ� ����Ǯ�̸� ������ �� ����.