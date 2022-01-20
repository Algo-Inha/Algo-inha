inputs = int(input())
inp_arr = list(map(int, input().split()))
block = [1, 0, 0, 0]
acc = 0
division = sum(inp_arr) / 4
for i in range(inputs - 1):
    acc += inp_arr[i]
    for j in [3, 2, 1]:
        if acc == j * division:
            block[j] += block[j - 1]
print(block[3])
