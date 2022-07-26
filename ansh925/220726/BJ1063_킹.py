# https://www.acmicpc.net/problem/1063
# 킹

king,rock,n = input().split()

# 킹,돌 위치 알파벳 아스키로 변경 후 list에 저장
k = list(map(int,[ord(king[0])-64, king[1]]))
r = list(map(int,[ord(rock[0])-64, rock[1]]))

# 8 방향 -> dictionary로 지정
move = {'R':[1,0], 'L':[-1,0], 'B':[0,-1], 'T':[0,1], 
        'RT':[1,1], 'LT':[-1,1], 'RB':[1,-1], 'LB':[-1,-1]} 

for _ in range(int(n)):
    m=input()
    k_nx = k[0] + move[m][0]
    k_ny = k[1] + move[m][1]            # 킹 이동

    if 0<k_nx<=8 and 0<k_ny<=8:         # 킹이 map 안벗어나고,
        if k_nx==r[0] and k_ny==r[1]:   # 이동 시 돌에 부딪히면
            r_nx = r[0] + move[m][0]
            r_ny = r[1] + move[m][1]    # 돌 이동
            if 0<r_nx<=8 and 0<r_ny<=8: # 돌이 map 안벗어나면
                k = [k_nx,k_ny]         # 킹 위치 저장
                r = [r_nx,r_ny]         # 돌 위치 저장
        else:
            k = [k_nx,k_ny]             # 돌 안부딪히면 킹 위치만 저장

print(f'{chr(k[0]+64)}{k[1]}')          # 아스키 다시 문자로 돌리고,
print(f'{chr(r[0]+64)}{r[1]}')          # 문자+숫자 붙여서 킹,돌 위치 출력