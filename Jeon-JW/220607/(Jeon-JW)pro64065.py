# https://programmers.co.kr/learn/courses/30/lessons/64065?language=python3
# 튜플

def solution(s) :
    stack = []

    s = s[2:-2] # { {, }}빼주기
    s = s.split('},{') # 숫자 나눠주기
    s.sort(key = len) # list가 정렬되는 개사기 파이썬

    for i in s :
spy = i.split(',') # split이 편한 개사기 파이썬
for j in spy :
if not int(j) in stack : # 배열에서 if로 확인해주는 개사기 파이썬
stack.append(int(j))
return stack