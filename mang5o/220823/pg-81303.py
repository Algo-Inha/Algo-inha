# https://school.programmers.co.kr/learn/courses/30/lessons/81303
# 표 편집

def solution(n, k, cmd):
    """
    :param n: 처음 표의 행 개수를 나타내는 정수
    :param k: 처음에 선택된 행의 위치를 나타내는 정수
    :param cmd: 수행한 명령어들이 담긴 문자열 배열
    :return: 행에 대한 계산 결과
    """
    table_to_cal = ["O" for x in range(n)]
    first_cursor = k
    deleted_stack = []
    linked_idx = [[x-1, x+1] for x in range(n)]
    for i in range(len(cmd)):
        now_cmd = cmd[i]
        if now_cmd[0] == "U":
            for iter_fig in range(int(now_cmd.split()[1])):
                first_cursor = linked_idx[first_cursor][0]
        elif now_cmd[0] == "D":
            for iter_fig in range(int(now_cmd.split()[1])):
                first_cursor = linked_idx[first_cursor][1]
        elif now_cmd[0] == "C":
            table_to_cal[first_cursor] = "X"
            if linked_idx[first_cursor][0]>=0:
                linked_idx[linked_idx[first_cursor][0]][1] = linked_idx[first_cursor][1]
            if linked_idx[first_cursor][1]<n:
                linked_idx[linked_idx[first_cursor][1]][0] = linked_idx[first_cursor][0]
            deleted_stack.append(first_cursor)
            if linked_idx[first_cursor][1] >= n:
                first_cursor = linked_idx[first_cursor][0]
            else:
                first_cursor = linked_idx[first_cursor][1]
        else: # Z
            fig = deleted_stack.pop()
            table_to_cal[fig] = "O"
            now_left = linked_idx[fig][0]
            now_right = linked_idx[fig][1]

            if now_left != -1:
                linked_idx[now_left][1] = fig
            if now_right != n:
                linked_idx[now_right][0] = fig
            linked_idx[fig] = [now_left, now_right]

    answer = "".join(table_to_cal)
    return answer

print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]))
print(solution(8,2,	["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]))