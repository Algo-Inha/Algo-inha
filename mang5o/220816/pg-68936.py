# https://school.programmers.co.kr/learn/courses/30/lessons/68936
# 쿼드압축 후 개수 세기

def solution(arr):
    size = len(arr)
    now_width = size
    block_fig = [0,0]  # how many block
    while True:
        # Check all block
        for y_idx in range(size//now_width):
            for x_idx in range(size//now_width):
                # check Block {start_y~end_y, start_x~end_x}
                start_y = y_idx * now_width
                end_y = (y_idx + 1) * now_width - 1
                start_x = x_idx * now_width
                end_x = (x_idx + 1) * now_width - 1
                if arr[start_y][start_x] == 2:
                    continue
                now_flag = True
                for yy in range(start_y, end_y+1):
                    for xx in range(start_x, end_x + 1):
                        if arr[yy][xx] != arr[start_y][start_x]:
                            now_flag = False
                            break
                    if not now_flag:
                        break
                if now_flag:
                    block_fig[arr[start_y][start_x]] += 1
                    for yy in range(start_y, end_y + 1):
                        for xx in range(start_x, end_x + 1):
                            arr[yy][xx] = 2
        if now_width == 1:
            break
        else:
            now_width //= 2

    return block_fig

