# https://school.programmers.co.kr/learn/courses/30/lessons/77885
# 2개 이하로 다른 비트

def solution(numbers):
    ans_lst = []
    for number in numbers:
        now_bin = []
        now_fig = number
        while number != 0:
            now_bin.append(number%2)
            number //= 2
        now_bin += [0, 0] # Care overflow

        start_check = 0
        for i in range(len(now_bin)):
            if now_bin[i] == 1:
                start_check += 1
            else:
                break

        if start_check >= 1:
            add_fig = 2**(start_check - 1)
            ans_lst.append(now_fig + add_fig)
        else:
            compare_lst = [now_bin[x] for x in range(len(now_bin))]  # copy
            compare_fig = now_fig
            diff_cnt = 0  # Compare
            while True:
                compare_fig += 1
                start_ptr = 0
                while True:  # add 1
                    if compare_lst[start_ptr] == 0:
                        compare_lst[start_ptr] = 1
                        if now_bin[start_ptr] == 0:
                            diff_cnt += 1
                        else:
                            diff_cnt -= 1
                        break
                    else:
                        compare_lst[start_ptr] = 0
                        if now_bin[start_ptr] == 1:
                            diff_cnt += 1
                        else:
                            diff_cnt -= 1
                        start_ptr += 1

                if diff_cnt <= 2:
                    ans_lst.append(compare_fig)
                    break

    return ans_lst

print(solution([2,7,1]))