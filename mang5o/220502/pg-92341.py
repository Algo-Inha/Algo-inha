# https://programmers.co.kr/learn/courses/30/lessons/92341
# 주차 요금 계산
import math


def solution(fees, records):
    cost_list = dict()
    now_car = dict()
    for record in records:
        record_splited = record.split()
        if record_splited[2]=="IN":
            if not record_splited[1] in now_car:
                now_car[record_splited[1]] = record_splited[0]
        else:
            if record_splited[1] in now_car:
                now_time = record_splited[0].split(":")
                start_time = now_car[record_splited[1]].split(":")
                start_min = int(start_time[0])*60 + int(start_time[1])
                end_min = int(now_time[0])*60 + int(now_time[1])
                min_interval = end_min - start_min
                now_car.pop(record_splited[1])
                if record_splited[1] in cost_list:
                    cost_list[record_splited[1]] = cost_list[record_splited[1]] + min_interval
                else:
                    cost_list[record_splited[1]] = min_interval

    out_records = []
    for rec in now_car.keys():
        out_records.append("23:59 {} OUT".format(rec))

    for record in out_records:
        record_splited = record.split()
        now_time = record_splited[0].split(":")
        start_time = now_car[record_splited[1]].split(":")
        start_min = int(start_time[0]) * 60 + int(start_time[1])
        end_min = int(now_time[0]) * 60 + int(now_time[1])
        min_interval = end_min - start_min
        now_car.pop(record_splited[1])
        if record_splited[1] in cost_list:
            cost_list[record_splited[1]] = cost_list[record_splited[1]] + min_interval
        else:
            cost_list[record_splited[1]] = min_interval

    costs = []
    for i in cost_list.keys():
        now_key = i
        now_time = cost_list[now_key]

        tmp_cost = fees[1]
        if now_time > fees[0]:
            tmp_cost += (math.ceil((now_time-fees[0])/fees[2]))*fees[3]
        costs.append([now_key,tmp_cost])
    costs.sort(key=lambda x : x[0])

    all_cost = []
    for i in costs:
        all_cost.append(i[1])

    return all_cost


print(solution([180, 5000, 10, 600],["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))
print(solution([120, 0, 60, 591],["16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"]))
print(solution([1, 461, 1, 10],["00:00 1234 IN"]))