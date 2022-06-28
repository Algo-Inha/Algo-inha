# https://programmers.co.kr/learn/courses/30/lessons/43238
# 입국심사
def get_count(tmp_time):
    # print("get_count : {}".format(tmp_time))
    if tmp_time in all_count_dict:
        return all_count_dict[tmp_time]
    else:
        tmp_cnt = 0
        for pers in all_times:
            tmp_cnt += tmp_time//pers
        all_count_dict[tmp_time] = tmp_cnt
        return tmp_cnt

def solution(n, times):
    global all_times
    global all_count_dict
    all_times = [times[x] for x in range(len(times))]
    all_count_dict = dict()

    # 좌측 우측 boundary 설정
    min_fig = 0
    tmp_max_fig = max(times) * n
    now_add_fig = 1
    max_fig = 1
    while max_fig < tmp_max_fig:
        max_fig += now_add_fig
        now_add_fig *= 2
    # 이분탐색
    while True:
        mid_fig = (min_fig + max_fig)//2
        now_count = get_count(mid_fig)
        if mid_fig == min_fig or mid_fig == max_fig:
            break
        if now_count < n:
            min_fig = mid_fig
        else:
            max_fig = mid_fig
    return_fig = min_fig
    for i in range(min_fig-1, max_fig+1):
        if get_count(i) < n:
            if get_count(i+1) >= n:
                return_fig = i+1
                break
    return return_fig

print(solution(6, [7,10]))
print(solution(8, [1,9]))
print(solution(10,[3,8,3,6,9,2,4]))
