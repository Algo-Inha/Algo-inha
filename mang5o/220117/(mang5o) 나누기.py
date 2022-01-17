# https://www.acmicpc.net/problem/21757

num = int(input())
figures = input().split(" ")
sum_of_all = 0
for i in range(len(figures)):
    now_num = int(figures[i])  # type casting
    sum_of_all = sum_of_all + now_num
    figures[i] = now_num

sum_of_each_block = sum_of_all / 4

block_arr = {-1: 1}
for i in range(4):
    tmp_ba = {}
    for ba in block_arr.items():
        now_sum = 0
        now_multi = ba[1]
        start_point = ba[0]
        for pointer in range(start_point + 1, num):
            now_sum = now_sum + figures[pointer]
            if now_sum == sum_of_each_block:
                if pointer in tmp_ba:
                    tmp_ba[pointer] = tmp_ba[pointer] + now_multi
                else:
                    tmp_ba[pointer] = now_multi
    block_arr = tmp_ba

method_count = 0
for i in block_arr.items():
    if i[0] == num - 1:
        method_count = i[1]
        break

print(method_count)
