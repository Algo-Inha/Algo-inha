# 보물상자 비밀번호
# https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo&categoryId=AWXRUN9KfZ8DFAUo&categoryType=CODE&&&

T = int(input())
outputs_arr = []
for step in range(T):
    N, K = map(int, input().split())
    now_str = input()
    for i in range(N//4):
        now_str += now_str[i]
    tmp_arr = [now_str[i:i+N//4] for i in range(N)]
    tmp_arr = list(set(tmp_arr))
    tmp_arr.sort(reverse=True)
    now_return = tmp_arr[K-1]
    now_return_fig = 0
    for i in range(N//4):
        now_num = 0
        if '0'<=now_return[i]<='9':
            now_num = int(now_return[i])
        else:
            if now_return[i]=='A':
                now_num = 10
            elif now_return[i]=='B':
                now_num = 11
            elif now_return[i]=='C':
                now_num = 12
            elif now_return[i]=='D':
                now_num = 13
            elif now_return[i]=='E':
                now_num = 14
            elif now_return[i]=='F':
                now_num = 15
        now_multiple = 1
        for cnt in range(N//4-1):
            now_multiple *= 16
        for cnt in range(i):
            now_multiple /= 16
        now_return_fig += now_num*now_multiple
    outputs_arr.append(int(now_return_fig))
for step in range(T):
    print("#{} {}".format(step+1, outputs_arr[step]))

