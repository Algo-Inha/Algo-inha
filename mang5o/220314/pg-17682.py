# https://programmers.co.kr/learn/courses/30/lessons/17682
# 다트 게임

def solution(dartResult):
    # 보너스 이후 옵션이 없으면 X로 만들기
    dartResult = dartResult.replace("10","A")
    dartResult += "0" # IndexError 처리 (i==2일 경우)
    for i in range(3):
        if '0' <= dartResult[3*i + 2] <= '9' or dartResult[3*i + 2] == 'A':
            dartResult = dartResult[:3*i+2] + "X" + dartResult[3*i+2:]
    dartResult = dartResult[:len(dartResult)-1] # 맨 뒤 0 제거
    now_result_arr = []
    for i in range(3): # 숫자 입력
        if dartResult[3*i] == "A":
            now_result_arr.append(10)
        else:
            now_result_arr.append(int(dartResult[3*i]))
    for i in range(3): # 보너스
        if dartResult[3*i + 1] == "D":
            now_result_arr[i] **= 2
        elif dartResult[3*i + 1] == "T":
            now_result_arr[i] **= 3
    for i in range(3): # 상
        if dartResult[3*i + 2] == "*":
            if i-1 >= 0:
                now_result_arr[i-1] *= 2
            now_result_arr[i] *= 2
        elif dartResult[3*i + 2] == "#":
            now_result_arr[i] *= -1
    all_score = sum(now_result_arr)
    return all_score