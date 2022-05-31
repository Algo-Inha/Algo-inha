# https://programmers.co.kr/learn/courses/30/lessons/42885
# 구명보트
import bisect
def solution(people, limit):
    people.sort()  # 오름차순 정렬
    now_return = 0
    while len(people) > 0:
        if len(people) > 1:
            if people[0] + people[1] > limit:
                now_return += len(people)
                break
        tmp_people = people.pop()
        if len(people) == 0:
            now_return += 1
            break
        elif tmp_people == limit:
            now_return += 1
        else:
            max_val = limit - tmp_people
            bisect_left_idx = bisect.bisect_left(people, max_val)
            if bisect_left_idx == len(people):
                people.pop()
                now_return += 1
            elif people[bisect_left_idx] == max_val:
                del people[bisect_left_idx]
                now_return += 1
            else:
                if bisect_left_idx == 0:
                    now_return += 1
                else:
                    del people[bisect_left_idx - 1]
                    now_return += 1

    return now_return


print(solution([70, 50, 80, 50], 100))
print(solution([70, 80, 50], 100))
print(solution([50, 50, 50, 50, 50, 100, 50, 50, 50, 50, 50, 50, 50, 50], 100))
print(solution([70, 80, 50, 80, 50, 80, 50, 80, 50, 80], 100))
print(solution([100, 500, 500, 900, 950], 1000))
print(solution([40, 50, 150, 160], 200))
