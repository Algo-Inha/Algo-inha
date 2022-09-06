# https://school.programmers.co.kr/learn/courses/30/lessons/67256
# 키패드 누르기 - 2020 카카오 인턴십

def solution(numbers, hand):
    answer = ''

    # dictionary에 키패드의 위치 정보를 좌표로 미리 저장
    keypad = {  '1':(0,0), '2':(0,1), '3':(0,2),
                '4':(1,0), '5':(1,1), '6':(1,2),
                '7':(2,0), '8':(2,1), '9':(2,2),
                '*':(3,0), '0':(3,1), '#':(3,2)
            }

    # 시작 위치
    L = keypad['*']
    R = keypad['#']

    for num in numbers: 

        # 왼쪽 손 사용 1,4,7   
        if num == 1 or num == 4 or num == 7:
            answer += 'L'           # answer에 'L' 추가
            L = keypad[str(num)]    # 위치 저장

        # 오른쪽 손 사용 3,6,9
        elif num == 3 or num == 6 or num == 9:
            answer += 'R'
            R = keypad[str(num)]

        # 가운데 부분 2,5,8,0
        else:
            # 2,5,8,0에서 왼손,오른손까지의 거리 측정
            L_dist = abs(L[0] - keypad[str(num)][0]) + abs(L[1] - keypad[str(num)][1])
            R_dist = abs(R[0] - keypad[str(num)][0]) + abs(R[1] - keypad[str(num)][1])

            if L_dist < R_dist:
                answer += 'L'
                L = keypad[str(num)]
            elif L_dist > R_dist:
                answer += 'R'
                R = keypad[str(num)]

            # 거리 같은 경우 오른,왼손잡이 따라 판단
            else:
                if hand == 'right':
                    answer += 'R'
                    R = keypad[str(num)]
                else:
                    answer += 'L'
                    L = keypad[str(num)]
    return answer

print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))