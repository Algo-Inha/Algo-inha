# https://school.programmers.co.kr/learn/courses/30/lessons/12899
# 124 나라의 숫자

# 풀이(1)
def solution(n):
    arr=['1','2','4']
    answer=''

    while n > 0:
        n -= 1
        answer = arr[n%3] + answer
        n //= 3

    return answer

# 풀이(2)
def solution(n):
    if n<=3:
        return '124'[n-1]
    else:        
        q,r = (n-1)//3, (n-1)%3         # q,r = divmod(n-1, 3) 동일!
        return solution(q) + '124'[r]


# print(solution(4))