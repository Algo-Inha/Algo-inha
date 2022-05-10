import sys
N, H = map(int, sys.stdin.readline().rstrip().split())
all_disable = []
for i in range(N):
    all_disable.append(int(sys.stdin.readline().rstrip()))
all_map = [0 for x in range(H)]
for i in range(N):
    if i%2 == 0:
        for height in range(all_disable[i]):
            all_map[height] += 1
    else:
        for height in range(all_disable[i]):
            all_map[H-1-height] += 1
print(all_map)
min_val = 999999999
min_pos = 0
for i in range(H):
    if min_val > all_map[i]:
        min_val = all_map[i]
        min_pos = 1
    elif min_val == all_map[i]:
        min_pos += 1

print("{} {}".format(min_val, min_pos))
