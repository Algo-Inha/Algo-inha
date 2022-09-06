# https://school.programmers.co.kr/learn/courses/30/lessons/67256
# 키패드 누르기- PG_67256

def solution(numbers, hand):
    answer = ''
    
    left, l = '*', 4    # 현재 왼손위치: *, 4층
    right, r = '#', 4   # 현재 오른손위치: #, 4층
    temp = -1

    for i in numbers:
        number = (i - 1)

        if number == -1:    # 0일 경우
            temp = 4        # number 위치: 0, 4층
            dist_l = abs(temp - l)          
            dist_r = abs(temp - r)
            if left == '*': dist_l += 1
            elif left % 3 != 2: dist_l += 1   # 누르고자 하는 번호와 왼손의 위치 차이
            
            if right == '#': dist_r += 1
            elif right % 3 != 2: dist_r += 1  # 누르고자 하는 번호와 오른손의 위치 차이

            if dist_l > dist_r:
                answer += 'R'
                right, r = 0, 4
            elif dist_l < dist_r:
                answer += 'L'
                left, l = 0, 4
            else:
                if hand == 'right':
                    answer += 'R'
                    right, r = 0, 4
                else:
                    answer += 'L'
                    left, l = 0, 4
        elif number % 3 == 1:       # 2 or 5 or 8 일 경우
            temp = number // 3 + 1  # number 위치: i, temp층
            dist_l, dist_r = abs(temp - l), abs(temp - r)
            if left == '*': dist_l += 1
            elif left % 3 != 2 and left != 0: dist_l += 1   # 누르고자 하는 번호와 왼손의 위치 차이

            if right == '#': dist_r += 1
            elif right % 3 != 2 and right != 0: dist_r += 1  # 누르고자 하는 번호와 오른손의 위치 차이

            if dist_l > dist_r:
                answer += 'R'
                right, r = i, temp
            elif dist_l < dist_r:
                answer += 'L'
                left, l = i, temp
            else:
                if hand == 'right':
                    answer += 'R'
                    right, r = i, temp
                else:
                    answer += 'L'
                    left, l = i, temp
        elif number % 3 == 0:               # 1 or 4 or 7 일 경우
            answer += 'L'                   # 'L' 누르고
            left, l = i, number // 3 + 1    # 현재 왼손위치: i, (number // 3)층
        elif number % 3 == 2:               # 3 or 6 or 9 일 경우
            answer += 'R'                   # 'R' 누르고
            right, r = i, number // 3 + 1   # 현재 오른손위치: i, (number // 3)층
        
    return answer

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
hand = 'right'
print(solution(numbers, hand))