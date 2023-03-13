import sys
input = sys.stdin.readline


n = int(input())

li = []
minus_li = []
zero_li = []
one_li = []
plus_li = []

answer = 0

for i in range(n):
    li.append(int(input()))



for i in li:
    if i < 0:
        minus_li.append(i)
    elif i == 0:
        zero_li.append(i)
    elif i == 1:
        one_li.append(i)
    else:
        plus_li.append(i)

li.sort()
minus_li.sort()
plus_li.sort()

if plus_li:
    if len(plus_li)%2 == 0:
        for i in range(len(plus_li)):
            if i%2 == 0:
                temp = plus_li[i]
            else:
                answer += temp*plus_li[i]
    else:
        if len(plus_li) == 1:
            answer += plus_li[0]
        else:
            answer += plus_li[0]
            for i in range(1,len(plus_li)):
                if i%2 == 1:
                    temp = plus_li[i]
                else:
                    answer += temp*plus_li[i]

if minus_li:
    if len(minus_li)%2 == 0:
        for i in range(len(minus_li)):
            if i%2 == 0:
                temp = minus_li[i]
            else:
                answer += temp*minus_li[i]
    else:
        if len(minus_li) == 1:
            if not zero_li:
                answer += minus_li[0]
        else:
            if zero_li:
                for i in range(len(minus_li) - 1):
                    if i%2 == 0:
                        temp = minus_li[i]
                    else:
                        answer += temp*minus_li[i]
            else:
                answer += minus_li[-1]
                for i in range(len(minus_li) - 1):
                    if i%2 == 0:
                        temp = minus_li[i]
                    else:
                        answer += temp*minus_li[i]

if one_li:
    for i in one_li:
        answer += i



print(answer)