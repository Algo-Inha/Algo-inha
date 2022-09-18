# https://school.programmers.co.kr/learn/courses/30/lessons/84021
# 퍼즐 조각 채우기- PG_84021

from collections import deque
import copy

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def rotate_a_matrix_by_90_degree(a):
    row_length = len(a)
    column_length = len(a[0])
    
    res = [[0] * row_length for _ in range(column_length)]
    for r in range(row_length):
        for c in range(column_length):
            res[c][row_length-1-r] = a[r][c]
    
    return res

def get_new_locations(location):
    new_locations = []
    for loc in location:
        x_min = int(1e9)
        x_max = 0
        y_min = int(1e9)
        y_max = 0
        for x, y in loc:
            x_min = min(x_min, x)
            x_max = max(x_max, x)
            y_min = min(y_min, y)
            y_max = max(y_max, y)
        new_locations.append([x_min, x_max, y_min, y_max])
    return new_locations

def bfs(table, q, location, n):
    while q:
        x, y  = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if table[nx][ny] == 1:
                    location.append([nx, ny])
                    table[nx][ny] = 0
                    q.append([nx, ny])
    return location

def get_piece_or_space(table, new_locations):
    pieces = []
    for x_min, x_max, y_min, y_max in new_locations:
        piece = []
        for x in range(x_min, x_max+1):
            row = table[x]
            piece.append(row[y_min:y_max+1])
        pieces.append(piece)
    return pieces

def solution(game_board, table):
    answer = 0
    n = len(table)

    # game_board 1, 0 반전
    for x in range(n):
        for y in range(n):
            if game_board[x][y] == 0:
                game_board[x][y] = 1
            else:
                game_board[x][y] = 0

    puzzle = []
    # 새로운 table 생성
    new_table = copy.deepcopy(table)
    # 새로운 table의 조각 찾기
    for x in range(n):
        for y in range(n):
            if new_table[x][y] == 1:
                new_table[x][y] = 0
                q = deque([[x, y]])
                location = [[x, y]]
                puzzle.append(bfs(new_table, q, location, n))
    
    # 좌표 가공
    new_locations = get_new_locations(puzzle)
    pieces = get_piece_or_space(table, new_locations)
    empty = []
    
    # 가공한 조각들을 90도씩 회전하며 game_board의 빈 공간과 같은지 비교
    for _ in range(4):
        new_pieces = []
        for piece in pieces:
            new_pieces.append(rotate_a_matrix_by_90_degree(piece))
        new_game_board = copy.deepcopy(game_board)
        for x in range(n):
            for y in range(n):
                if new_game_board[x][y] == 1:
                    new_game_board[x][y] = 0
                    q = deque([[x, y]])
                    location = [[x, y]]
                    new_location = get_new_locations([bfs(new_game_board, q, location, n)])
                    space = get_piece_or_space(game_board, new_location)[0]
                    if space in new_pieces:
                        new_pieces.remove(space)
                        for x_min, x_max, y_min, y_max in new_location:
                            for x in range(x_min, x_max+1):
                                for y in range(y_min, y_max+1):
                                    if game_board[x][y] == 1:
                                        game_board[x][y] = 0
                                        answer += 1
        pieces = new_pieces

    return answer

game_board = [[1,1,0,0,1,0],[0,0,1,0,1,0],[0,1,1,0,0,1],[1,1,0,1,1,1],[1,0,0,0,1,0],[0,1,1,1,0,0]]
table = [[1,0,0,1,1,0],[1,0,1,0,1,0],[0,1,1,0,1,1],[0,0,1,0,0,0],[1,1,0,1,1,0],[0,1,0,0,0,0]]
print(solution(game_board, table))