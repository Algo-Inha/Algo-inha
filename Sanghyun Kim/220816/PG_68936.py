# https://school.programmers.co.kr/learn/courses/30/lessons/68936
# 쿼드압축 후 개수 세기- PG_68936

def quad(x, y, temp, answer, arr):
    bin_val = arr[x][y]    
    break_ = False
    for i in range(x, x + temp):
        if break_:
            break
        for j in range(y, y + temp):
            if arr[i][j] != bin_val:
                break_ = True
                break
    if break_:
        temp_2 = temp // 2
        for i in range(x, x + temp, temp_2):
            for j in range(y, y + temp, temp_2):
                quad(i, j, temp_2, answer, arr)
    else:
        answer[bin_val] += 1
                

def solution(arr):
    answer = [0, 0]

    temp = len(arr)
    quad(0, 0, temp, answer, arr)


    return answer

arr = [[1,1,1,1,1,1,1,1],[0,1,1,1,1,1,1,1],[0,0,0,0,1,1,1,1],[0,1,0,0,1,1,1,1],[0,0,0,0,0,0,1,1],[0,0,0,0,0,0,0,1],[0,0,0,0,1,0,0,1],[0,0,0,0,1,1,1,1]]
print(solution(arr))