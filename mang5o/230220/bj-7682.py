# https://www.acmicpc.net/problem/7682
# 틱택토

def check_ended(input_map):
    for y in range(3):
        if input_map[y][0] == input_map[y][1] == input_map[y][2] and input_map[y][0] != '.':
            return [True, input_map[y][0]]
    for x in range(3):
        if input_map[0][x] == input_map[1][x] == input_map[2][x] and input_map[0][x] != '.':
            return [True, input_map[0][x]]
    if input_map[0][0] == input_map[1][1] == input_map[2][2] and input_map[0][0] != '.':
        return [True, input_map[0][0]]
    if input_map[2][0] == input_map[1][1] == input_map[0][2] and input_map[2][0] != '.':
        return [True, input_map[2][0]]
    return [False]

import sys
output_query = []
while True:
    inp = sys.stdin.readline().rstrip()
    if inp == 'end':
        break
    inp = list(inp)
    # OX 개수 확인
    fig_O = 0
    fig_X = 0
    for idx in range(9):
        if inp[idx] == 'X':
            fig_X += 1
        elif inp[idx] == 'O':
            fig_O += 1
    if fig_X != fig_O and fig_X != fig_O + 1:
        output_query.append('invalid')
        continue
    inp = [inp[0:3], inp[3:6], inp[6:9]]
    tmp_check_ended = check_ended(inp)
    if tmp_check_ended[0]:
        if tmp_check_ended[1] == 'O' and fig_X != fig_O:  # O로 끝났을 때 X와 O의 개수가 같아야함
            output_query.append('invalid')
            continue
        if tmp_check_ended[1] == 'X' and fig_X != fig_O + 1:  # X로 끝났을 때 X가 O보다 1개 더 많아야함
            output_query.append('invalid')
            continue
        # 이전 단계엔 틱택토가 아니어야 함
        now_flag = False
        for yy in range(3):
            for xx in range(3):
                if inp[yy][xx] == tmp_check_ended[1]:
                    tmp_inp = inp[yy][xx]
                    inp[yy][xx] = '.'
                    if not check_ended(inp)[0]:
                        now_flag = True
                        break
                    inp[yy][xx] = tmp_inp
            if now_flag:
                break
        if now_flag:
            output_query.append('valid')
            continue
        else:
            output_query.append('invalid')
            continue
    else: # 틱택토가 나오지 않았을 때
        if fig_X == 5 and fig_O == 4:
            output_query.append('valid')
            continue
        else:
            output_query.append('invalid')
            continue
for output in output_query:
    print(output)

