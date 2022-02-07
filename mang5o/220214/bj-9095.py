# https://www.acmicpc.net/problem/9095
def get_output(now_figure):
    if now_figure < 0:
        return 0
    elif now_figure <= 1:
        return 1
    else:
        return get_output(now_figure - 1) + get_output(now_figure - 2) + get_output(now_figure - 3)


outputs = []
for i in range(int(input())):
    outputs.append(get_output(int(input())))
for i in outputs:
    print(i)
