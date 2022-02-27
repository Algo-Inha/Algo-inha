# https://programmers.co.kr/learn/courses/30/lessons/72411
# 메뉴 리뉴얼

import itertools
def solution(orders, course):
    order_dict = [dict() for i in range(len(course))]
    for i in orders:
        # 진짜 개악질인게 주문 order는 오름차순이 아님
        # 그거도 잡아줘야함
        now_orders = []
        for j in i:
            now_orders.append(j)
        now_orders.sort()
        now_text = ""
        for j in now_orders:
            now_text += j
        for j in range(len(course)):
            # 각 주문에 대해서 조합의 경우를 뽑아 dict에 주문 횟수와 함께 저장
            now_combination = itertools.combinations(now_text,course[j])
            for nc in now_combination:
                tmp_order = ""
                for ncc in nc:
                    tmp_order += ncc
                if tmp_order in order_dict[j]:
                    order_dict[j][tmp_order] += 1
                else:
                    order_dict[j][tmp_order] = 1
    max_arr = [0 for i in range(len(course))]
    for i in range(len(course)):
        for j in order_dict[i].keys():
            if max_arr[i] < order_dict[i][j]:
                max_arr[i] = order_dict[i][j]


    all_courses = []
    for i in range(len(course)):
        for j in order_dict[i].keys():
            if order_dict[i][j] == max_arr[i] and order_dict[i][j]>1:
                all_courses.append(j)
    all_courses.sort()
    return all_courses


print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2, 3, 4]))
print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2, 3, 5]))
print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
