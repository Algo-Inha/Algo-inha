# https://www.acmicpc.net/problem/6603
# 로또-dfs

def dfs(start,depth):
    if depth==6:                    # depth가 6이면
        for i in range(6):
            print(tmp[i],end=' ')   # tmp 리스트 출력
        print()
        return                      # 이전 dfs함수로 돌아감
    
    for i in range(start,len(s)):
        tmp[depth] = s[i]           # tmp 리스트에 입력 리스트 s의 값 저장
        dfs(i+1,depth+1)            # 증가한 i와 depth에 대해서 dfs 재실행

tmp=[0]*13
while True:
    s=list(map(int,input().split()))
    if s[0] == 0:   # 0 입력 시 종료
        break

    del s[0]        # 테스트케이스 t 제거
    dfs(0,0)        # dfs 실행
    print()