# https://school.programmers.co.kr/learn/courses/30/lessons/81303
# 표 편집- PG_81303

from collections import deque

def solution(n, k, cmd):
    answer = ''
    # [0, 2, ... , n - 1]
    graph = [i for i in range(n)]
    location = k
    sta = deque()

    
    for i in range(len(cmd)):
        if len(cmd[i]) == 1:
            if cmd[i] == 'C':
                #           값             , 인덱스
                sta.append((graph[location], location))
                graph.pop(location)
                # 가장 아래칸 삭제할 경우: location 위치 -1
                # 이외: location 위치 변하지 x
                if location == len(graph):
                    location -= 1
            elif cmd[i] == 'Z':
                val, idx = sta.pop()
                if idx <= location:
                    location += 1
                graph.insert(idx, val)
        else:
            order, num = cmd[i].split()
            num = int(num)
            if order == 'U':
                location -= num
            elif order == 'D':
                location += num

    k = 0
    for i in graph:
        if i == k:
            answer += 'O'
        else:
            answer += 'X'
            graph.insert(i - 1, -1)
        k += 1

    return answer

n, k = 8, 2
cmd = ["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]
print(solution(n,k,cmd))

# list 사용하면 시간 복잡도 해결 X