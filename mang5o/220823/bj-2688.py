# https://www.acmicpc.net/problem/2688
# 줄어들지 않아

import sys
from itertools import combinations_with_replacement
T = int(sys.stdin.readline().rstrip())
queries = []
for i in range(T):
    queries.append(int(sys.stdin.readline().rstrip()))

# 중복된 input이 들어올 경우 다시 계산하지 않고 이를 사용
unique_dict = dict()
# 계산에 사용할 팩토리얼을 미리 선언 (factorials[n] =>> n!)
factorials = [1]
for i in range(max(queries)+10):
    factorials.append(factorials[i]*(i+1))


# n자리수에서 "증가"가 가능한 위치는 총 n+1개 (맨 앞자리 왼쪽과 맨 뒷자리 오른쪽을 포함)
# "증가"의 개수는 0부터 9까지의 수로 9개이다
# 따라서 n+1의 위치에 9개의 "증가"가 들어갈 수 있는 중복조합의 개수 (n+1)H9 = (n+9)C9
for i in range(T):
    if i in unique_dict:
        print(unique_dict[i])
    else:
        tmp_query = queries[i]
        all_fig_count = factorials[tmp_query+9] // (factorials[9] * factorials[tmp_query])
        unique_dict[i] = all_fig_count
        print(all_fig_count)
