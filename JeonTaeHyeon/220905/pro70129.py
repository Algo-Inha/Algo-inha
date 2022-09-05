def solution(strr):
    answer = []
    zero=0
    change=0
    while(len(strr)!=1):
        size=int(len(strr))
        strr=strr.replace('0','')
        temp=int(len(strr))
        zero+=size-temp
        strr=""
        change+=1
        while(temp):
            re=temp%2
            temp//=2
            strr=str(re)+strr
    answer.append(change)
    answer.append(zero)
    return answer