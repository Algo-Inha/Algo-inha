# https://programmers.co.kr/learn/courses/30/lessons/17681
# 비밀지도
def solution(n, arr1, arr2):
    answer = []
    arr1_bi=[]
    arr2_bi=[]
    for i in range(n):
        arr1_bi.append(bin(arr1[i])[2:])
        arr2_bi.append(bin(arr2[i])[2:])
        arr1_bi[i]=('0' * (n-len(arr1_bi[i]))) + arr1_bi[i]
        arr2_bi[i]=('0' * (n-len(arr2_bi[i]))) + arr2_bi[i]

        tmp=''
        for j in range(n):
            if arr1_bi[i][j]=='1' or arr2_bi[i][j]=='1':
                tmp+='#'
            elif arr1_bi[i][j]=='0' and arr2_bi[i][j]=='0':
                tmp+=' '
        answer.append(tmp)
    return answer