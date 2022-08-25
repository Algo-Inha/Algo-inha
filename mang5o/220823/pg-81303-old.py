def solution(n, k, cmd):
    """
    :param n: 처음 표의 행 개수를 나타내는 정수
    :param k: 처음에 선택된 행의 위치를 나타내는 정수
    :param cmd: 수행한 명령어들이 담긴 문자열 배열
    :return: 행에 대한 계산 결과
    """
    table_to_cal = [True for x in range(n)]
    first_cursor = k
    deleted_stack = []
    for i in range(len(cmd)):
        now_cmd = cmd[i]
        if now_cmd[0] == "U":
            fig = int(now_cmd.split()[1])
            while fig>0:
                first_cursor -= 1
                if table_to_cal[first_cursor]:
                    fig -= 1
        elif now_cmd[0] == "D":
            fig = int(now_cmd.split()[1])
            while fig>0:
                first_cursor += 1
                if table_to_cal[first_cursor]:
                    fig -= 1
        elif now_cmd[0] == "C":
            table_to_cal[first_cursor] = False
            deleted_stack.append(first_cursor)
            now_flag = False
            while first_cursor < n - 1:
                first_cursor += 1
                if table_to_cal[first_cursor]:
                    now_flag = True
                    break
            if not now_flag:
                while True:
                    first_cursor -= 1
                    if table_to_cal[first_cursor]:
                        break
        else: # Z
            fig = deleted_stack.pop()
            table_to_cal[fig] = True

    answer = ''
    for i in range(len(table_to_cal)):
        if table_to_cal[i]:
            answer += "O"
        else:
            answer += "X"
    return answer