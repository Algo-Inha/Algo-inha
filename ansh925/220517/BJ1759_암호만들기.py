# https://www.acmicpc.net/problem/1759
# 암호 만들기

import sys
input=sys.stdin.readline

arr=[]
L,C=map(int,input().split())
lst=input().split()
check=[0]*C
lst.sort()

def recur(len,k):
    if len==L:
        vowel=0;consonant=0
        for i in range(L):
            if arr[i] in 'aeiou':
                vowel+=1
            else:
                consonant+=1
        if vowel>=1 and consonant>=2:
            #print(*arr)
            print(''.join(arr))
        return
    
    for i in range(k,C):
        if check[i]==0:
            arr.append(lst[i])
            check[i]=1
            recur(len+1,i+1)
            check[i]=0
            del arr[-1]
recur(0,0)