# https://programmers.co.kr/learn/courses/30/lessons/92341?language=python3
# 주차 요금 계산

import math

def dateToMinutes(date):                # hh:mm 형태의 시간을 분 단위로 변경하는 함수
    h, m = map(int, date.split(':'))
    return h*60 + m
    
def solution(fees, records):
    answer = []
    dt, df, ut, uf = fees   # 기본시간, 기본요금, 단위시간, 단위요금    
    dic = dict()

    for r in records:
        time, number, history = r.split()
        number = int(number)
        
        if number in dic:
            dic[number].append([dateToMinutes(time), history])
        else:
            dic[number] = [[dateToMinutes(time), history]]
        # dictionary 자료형은 sort()를 쓰지 못하기 때문에 (key,value) 꼴 list로 변환 

    rList = list(dic.items())
    rList.sort(key=lambda x : x[0])
    
    for r in rList:
        t = 0
        for rr in r[1]:
            if rr[1] == "IN":
                t -= rr[0]
            else:
                t += rr[0]

        if r[1][-1][1] == "IN":
            t += dateToMinutes('23:59')
        # 예외 처리

        if t <= dt:
            answer.append(df)
        else:
            answer.append(df + math.ceil((t-dt) / ut) * uf)        

    return answer