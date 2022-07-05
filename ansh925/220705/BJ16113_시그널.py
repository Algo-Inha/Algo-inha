# https://www.acmicpc.net/problem/16113
# 시그널

blank = ['.','.','.','.','.']
zero = ['#','#','#','#','#','#','.','.','.','#','#','#','#','#','#']
one = ['#','#','#','#','#']
two = ['#','.','#','#','#','#','.','#','.','#','#','#','#','.','#']
three = ['#','.','#','.','#','#','.','#','.','#','#','#','#','#','#']
four = ['#','#','#','.','.','.','.','#','.','.','#','#','#','#','#']
five = ['#','#','#','.','#','#','.','#','.','#','#','.','#','#','#']
six = ['#','#','#','#','#','#','.','#','.','#','#','.','#','#','#']
seven = ['#','.','.','.','.','#','.','.','.','.','#','#','#','#','#']
eight = ['#','#','#','#','#','#','.','#','.','#','#','#','#','#','#']
nine = ['#','#','#','.','#','#','.','#','.','#','#','#','#','#','#']

n=int(input())
signal=list(input())
length = len(signal)

number = [signal[i * (length//5) : (i+1) *(length//5)] 
          for i in range((length + (length//5) - 1)//(length//5))]

temp = []
ans = []

for i in range(length//5):
    for j in range(5):
        temp.append(number[j][i])

        # 0과 1 구분
        if temp == zero:
            ans.append(0)
            temp = []
        elif temp == one and i<(length//5)-1:
            if number[j][i+1] == '.' :
                ans.append(1)
                temp = []

        elif temp == one and i == (length//5)-1 and j == 4:
            ans.append(1)
            temp = []
        elif temp == two:
            ans.append(2)
            temp = []
        elif temp == three:
            ans.append(3)
            temp = []
        elif temp == four:
            ans.append(4)
            temp = []
        elif temp == five:
            ans.append(5)
            temp = []
        elif temp == six:
            ans.append(6)
            temp = []
        elif temp == seven:
            ans.append(7)
            temp = []
        elif temp == eight:
            ans.append(8)
            temp = []
        elif temp == nine:
            ans.append(9)
            temp = []
        elif temp == blank:
            temp = []

for i in ans:
    print(int(i), end="")