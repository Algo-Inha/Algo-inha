# https://programmers.co.kr/learn/courses/30/lessons/64065?language=python3
# Ʃ��

def solution(s) :
    stack = []

    s = s[2:-2] # { {, }}���ֱ�
    s = s.split('},{') # ���� �����ֱ�
    s.sort(key = len) # list�� ���ĵǴ� ����� ���̽�

    for i in s :
spy = i.split(',') # split�� ���� ����� ���̽�
for j in spy :
if not int(j) in stack : # �迭���� if�� Ȯ�����ִ� ����� ���̽�
stack.append(int(j))
return stack