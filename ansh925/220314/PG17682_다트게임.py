# https://programmers.co.kr/learn/courses/30/lessons/17682
# 다트 게임

def solution(dartResult):
    divided=[]
    tmp=list(dartResult)

    for i in range(len(tmp)):
        if tmp[i]=='1' and tmp[i+1]=='0':   # 10인 경우 따로 처리
            divided.append('10')
        elif tmp[i]=='0' and tmp[i-1]=='1': # 마찬가지로 10인 경우 중복처리 제외
            continue
        else:
            divided.append(tmp[i])
    
    ans=[]

    for j in divided:
        if j.isdigit():
            num=int(j)
        elif j.isalpha():
            if j=='S':
                num**=1
                ans.append(num)
            elif j=='D':
                num**=2
                ans.append(num)
            elif j=='T':
                num**=3
                ans.append(num)
        
        if j=='*':
            if len(ans)>=2:
                ans[-1]*=2
                ans[-2]*=2
            else:
                ans[-1]*=2
        elif j=='#':
            ans[-1]*=(-1)
    return sum(ans)