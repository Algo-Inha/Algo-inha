# https://programmers.co.kr/learn/courses/30/lessons/77485
# 행렬 테두리 회전하기

def solution(rows, columns, queries):
    all_smallest = []
    all_map = [[y*columns + x + 1 for x in range(columns)] for y in range(rows)]  # Base matrix
    for query in queries: # 행렬에 대해 언급이 이상하게 되어있음
        right_top_figure = all_map[query[0] - 1][query[3] - 1]
        smallest_val = right_top_figure
        for dir_now in range(4):
            if dir_now==0:
                for x_diff in range(query[3]-query[1]):
                    now_x = query[3]-x_diff-1
                    all_map[query[0]-1][now_x] = all_map[query[0]-1][now_x-1]
                    smallest_val = min(smallest_val,all_map[query[0]-1][now_x])
            elif dir_now==1:
                for y_diff in range(query[2]-query[0]):
                    now_y = query[0] + y_diff -1
                    all_map[now_y][query[1]-1] = all_map[now_y+1][query[1]-1]
                    smallest_val = min(smallest_val,all_map[now_y][query[1]-1])
            elif dir_now==2:
                for x_diff in range(query[3]-query[1]):
                    now_x = query[1] + x_diff -1
                    all_map[query[2]-1][now_x] = all_map[query[2]-1][now_x+1]
                    smallest_val = min(smallest_val,all_map[query[2]-1][now_x])
            else:
                for y_diff in range(query[2]-query[0]):
                    now_y = query[2] - y_diff -1
                    all_map[now_y][query[3]-1] = all_map[now_y-1][query[3]-1]
                    smallest_val = min(smallest_val,all_map[now_y][query[3]-1])
        all_map[query[0]][query[3]-1] = right_top_figure
        all_smallest.append(smallest_val)
    return all_smallest

# print(solution(6,6,[[2,2,5,4]]))
print(solution(6,6,[[2,2,5,4],[3,3,6,6],[5,1,6,3]]))
print(solution(3,3,[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]))
print(solution(100,97,[[1,1,100,97]]))