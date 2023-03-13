import sys
input = sys.stdin.readline

n = int(input())

li = list(map(int,input().split()))

li.sort()

min_left, min_right = 0, n-1
left = 0
right = n - 1
min = abs(li[0] + li[-1])

if li[0] > 0:
    print(li[0],li[1],end=" ")

elif li[-1] < 0:
    print(li[-2], li[-1],end=" ")

else:
    while(left<right):
        temp = li[left] + li[right]



        if abs(temp) < min:
            min_left = left
            min_right = right
            min = abs(temp)

        if temp == 0:
            break


        if temp < 0:
            left += 1
        else:
            right -= 1

print(li[min_left], li[min_right], end=" ")
            