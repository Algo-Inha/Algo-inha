# https://programmers.co.kr/learn/courses/30/lessons/17681
# 비밀지도
def solution(n, arr1, arr2) :
    result = []

    for j in range(0,len(arr1)) :
        ret = ''
        num = arr1[j] | arr2[j]

        for i in range(0, n) :
            if num % 2 == 0 :
                ret = ' ' + ret

            else : 
                ret = '#' + ret

            num = int(num / 2)

        result.append(ret)

    return result