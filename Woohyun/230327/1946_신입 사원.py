import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())  # 지원자 수
    applicants = []  # 지원자 정보를 담을 리스트

    # 지원자 정보 입력 받기
    for i in range(N):
        document, interview = map(int, input().split())
        applicants.append([document, interview])

    # document 기준으로 오름차순 정렬
    applicants.sort(key=lambda x: x[0])

    # interview 순위가 현재까지의 최고 순위보다 높은 지원자들만 선발
    cnt = 1  # 첫 번째 지원자는 무조건 선발
    highest_interview = applicants[0][1]  # 현재까지의 최고 순위
    for i in range(1, N):
        if applicants[i][1] < highest_interview:  # 면접시험 순위가 높은 지원자만 선발
            highest_interview = applicants[i][1]  # 현재까지의 최고 순위 갱신
            cnt += 1

    print(cnt)  # 선발 가능한 신입사원 수 출력