# https://school.programmers.co.kr/learn/courses/30/lessons/77885
# 2개 이하로 다른 비트- PG_77885

# 10^15 => 11100011010111111010100100110001101000000000000000

def solution(numbers):
    answer = []
    for i in numbers:
        x = i
        temp = [0 for _ in range(50)]
        temp_1 = [0 for _ in range(50)]

        count_ = 0
        while i >= 2:
            temp[count_] = i % 2
            temp_1[count_] = i % 2
            i //= 2
            count_ += 1
        temp[count_] = i
        temp_1[count_] = i
        
        f_x = 1
        while True:
            count = 0
            for j in range(count_ + 1):
                if temp_1[j] == 1:
                    temp_1[j] = 0
                    if j == count_:
                        temp_1[count_ + 1] = 1
                        count_ += 1
                        break
                else:
                    temp_1[j] = 1
                    break
            for j in range(count_ + 1):
                if temp[j] != temp_1[j]:
                    count += 1
                    if count > 2:
                        break
            if count <= 2:
                answer.append(x + f_x)
                break
            f_x += 1
    return answer