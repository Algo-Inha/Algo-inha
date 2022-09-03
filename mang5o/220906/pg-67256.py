# https://school.programmers.co.kr/learn/courses/30/lessons/67256
# 키패드 누르기
keypad_position = [
    [3,1], [0,0], [0,1], [0,2], [1,0], [1,1], [1,2], [2,0], [2,1], [2,2]
]
def solution(numbers, hand):
    now_right_hand = True if hand[0] == "r" else False
    finger_position = [
        [3,0], # left finger
        [3,2]  # right finger
    ]

    answer = ''
    now_mov_left = True

    for i in range(len(numbers)):
        now_num = numbers[i]
        now_num_position = keypad_position[now_num]
        if now_num == 1 or now_num == 4 or now_num == 7:
            now_mov_left = True
        elif now_num == 3 or now_num == 6 or now_num == 9:
            now_mov_left = False
        else:
            left_diff = abs(finger_position[0][0]-now_num_position[0]) + abs(finger_position[0][1]-now_num_position[1])
            right_diff = abs(finger_position[1][0]-now_num_position[0]) + abs(finger_position[1][1]-now_num_position[1])
            if left_diff < right_diff:
                now_mov_left = True
            elif left_diff > right_diff:
                now_mov_left = False
            else:
                if now_right_hand:
                    now_mov_left = False
                else:
                    now_mov_left = True

        if now_mov_left:
            finger_position[0] = now_num_position
            answer += "L"
        else:
            finger_position[1] = now_num_position
            answer += "R"

    return answer


print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], "left"))
print(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], "right"))
