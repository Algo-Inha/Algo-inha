# https://school.programmers.co.kr/learn/courses/30/lessons/12924
# 숫자의 표현

def solution(n):
    acc_sum = [0]  # 누적합 행렬
    for idx in range(n):
        acc_sum.append(acc_sum[-1] + idx + 1)

    start_ptr = 0
    end_ptr = 0
    answer = 0
    while end_ptr <= n:
        if acc_sum[end_ptr] - acc_sum[start_ptr] == n:
            # print("{} ~ {}".format(start_ptr + 1, end_ptr))
            answer += 1
            end_ptr += 1
        elif acc_sum[end_ptr] - acc_sum[start_ptr] < n:
            end_ptr += 1
        else:
            start_ptr += 1

    return answer


print(solution(15))
