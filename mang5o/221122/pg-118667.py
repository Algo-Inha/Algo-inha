# https://school.programmers.co.kr/learn/courses/30/lessons/118667
# 두 큐 합 같게 만들기

from collections import deque
def solution(queue1, queue2):
    sum_1 = sum(queue1)
    sum_2 = sum(queue2)
    deque1 = deque(queue1)
    deque2 = deque(queue2)
    max_val = len(queue1) + len(queue2)
    steps = 0

    while True:
        if max_val*2 < steps:
            steps = -1
            break
        if sum_1 > sum_2:
            tmp = deque1.popleft()
            sum_2 += tmp * 2
            deque2.append(tmp)
            steps += 1
        elif sum_1 < sum_2:
            tmp = deque2.popleft()
            sum_1 += tmp * 2
            deque1.append(tmp)
            steps += 1
        else:
            break

    return steps

print(solution([3, 2, 7, 2],[4, 6, 5, 1]))
print(solution([1, 2, 1, 2],[1, 10, 1, 2]))
print(solution([1, 1],[1, 5]))