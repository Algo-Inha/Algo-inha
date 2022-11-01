# https://www.acmicpc.net/problem/16113
# 시그널

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
blank = ['.','.','.','.','.']

n = int(input())
code = list(input())

num = [code[i*(n//5) : (i+1)*(n//5)] for i in range((n + (n//5)-1)//(n//5))]

tmp,ans = [],[]
for i in range(n//5):
    for j in range(5):
        tmp.append(num[j][i])

        if tmp == zero:     ans.append(0); tmp=[]
        elif tmp == one and i < (n//5)-1 and num[j][i+1] == '.':
            ans.append(1); tmp=[]
        elif tmp == one and i == (n//5)-1 and j == 4:
            ans.append(1); tmp=[]
        elif tmp == two:    ans.append(2); tmp=[]
        elif tmp == three:  ans.append(3); tmp=[]
        elif tmp == four:   ans.append(4); tmp=[]
        elif tmp == five:    ans.append(5); tmp=[]
        elif tmp == six:     ans.append(6); tmp=[]
        elif tmp == seven:   ans.append(7); tmp=[]
        elif tmp == eight:   ans.append(8); tmp=[]
        elif tmp == nine:    ans.append(9); tmp=[]
        elif tmp == blank:   tmp=[]

for k in ans:
    print(int(k), end='')