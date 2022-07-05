# https://www.acmicpc.net/problem/1713
# 후보 추천하기
import sys
input=sys.stdin.readline

img=[]      # 사진틀 리스트
index=[]    # 추천수 리스트
n=int(input())      # 사진틀 수
m=int(input())      # 추천수
k=list(map(int,input().split()))    # 추천받은 학생의 번호

for i in range(m):
    if k[i] in img:     # 이미 사진틀에 있을 경우
        for j in range(len(img)):   
            if k[i] == img[j]:  # 추천 학생과 사진틀 학생이 같으면
                index[j] += 1   # 추천수++
    else:
        if len(img) >= n:       # 사진틀에 없고, 사진틀이 꽉 차있는 경우
            for j in range(n):
                if index[j] == min(index):  # 추천수 가장 적은 학생
                    del img[j]              # 사진틀에서 지우고
                    del index[j]            # 추천수도 삭제
                    break
        img.append(k[i])    # 지운 뒤에 새로운 사진 추가 & 추천수 1
        index.append(1)
        
img.sort()      # 추천받은 학생 번호 순 정렬
print(' '.join(map(str,img)))