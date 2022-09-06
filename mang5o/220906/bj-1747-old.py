import sys
all_fig = int(sys.stdin.readline())
ans = []
for i in range(all_fig):
    N, M = map(int, sys.stdin.readline().split())
    for j in range(M):
        _ = sys.stdin.readline()
    ans.append(N-1)
for i in range(all_fig):
    print(ans[i])
