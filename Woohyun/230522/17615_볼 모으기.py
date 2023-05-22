import sys
input = sys.stdin.readline

n = int(input())
str_balls = str(input().strip())
cnt = []

right_red = str_balls.rstrip('R')
cnt.append(right_red.count('R'))

right_blue = str_balls.rstrip('B')
cnt.append(right_blue.count('B'))

left_red = str_balls.lstrip('R')
cnt.append(left_red.count('R'))

left_blue = str_balls.lstrip('B')
cnt.append(left_blue.count('B'))

print(min(cnt))