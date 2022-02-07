# https://www.acmicpc.net/problem/1914

output_str = ""

def mov_tower(height, from_idx, to_idx,):
    return_str = ""
    if height == 1:
        print("{} {}".format(from_idx, to_idx))
        return return_str, 1
    elif height == 2:
        other = 6 - from_idx - to_idx
        print("{} {}\n{} {}\n{} {}".format(from_idx, other, from_idx, to_idx, other, to_idx))
        return return_str, 3
    else:
        other = 6 - from_idx - to_idx
        mov_tower(height - 1, from_idx, other)
        print("{} {}".format(from_idx, to_idx))
        mov_tower(height - 1, other, to_idx)


def mov_tower_without_print(height):
    return_list = [0 for i in range(height)]
    for i in range(height):
        if i == 0:
            return_list[i] = 1
        elif i == 1:
            return_list[i] = 3
        else:
            return_list[i] = 2 * return_list[i - 2] + return_list[i - 1] + 2
    return return_list[-1]


now_height = int(input())
print_flag = True if 21 > now_height else False
if print_flag:
    print(mov_tower_without_print(now_height))
    mov_tower(now_height, 1, 3)
else:
    print(mov_tower_without_print(now_height))
