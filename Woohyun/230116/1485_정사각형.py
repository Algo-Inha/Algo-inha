import sys
input = sys.stdin.readline

T = int(input())



for test in range(T):
    li = [[] for _ in range(4)]
    length_li = []
    for i in range(4):
        x, y = map(int,input().split())
        li[i].append(x)
        li[i].append(y)


    for i in range(1,4):
        a = (li[0][0] - li[i][0])**2 + (li[0][1] - li[i][1])**2
        length_li.append(a)

    for i in range(2,4):
        a = (li[1][0] - li[i][0])**2 + (li[1][1] - li[i][1])**2
        length_li.append(a)

    for i in range(3,4):
        a = (li[2][0] - li[i][0])**2 + (li[2][1] - li[i][1])**2
        length_li.append(a)

    length_li.sort() 

    if length_li.count(length_li[0]) == 4 and length_li.count(length_li[-1]) == 2 and (0 not in length_li):
        print(1)
    else:
        print(0)