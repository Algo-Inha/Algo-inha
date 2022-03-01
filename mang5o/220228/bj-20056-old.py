# https://www.acmicpc.net/problem/20056
# 마법사 상어와 파이어볼
import sys, math

dir_matrix = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

N, M, K = map(int, sys.stdin.readline().rstrip().split())
fireball_matrix = []
for i in range(M):
    fireball_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(K):
    # 파이어볼 이동
    for j in range(len(fireball_matrix)):
        diff_y = dir_matrix[fireball_matrix[j][4]][0] * fireball_matrix[j][3]
        diff_x = dir_matrix[fireball_matrix[j][4]][1] * fireball_matrix[j][3]
        fireball_matrix[j][0] += diff_y
        fireball_matrix[j][1] += diff_x
        if fireball_matrix[j][0] < 0:
            fireball_matrix[j][0] += N
        if fireball_matrix[j][0] >= N:
            fireball_matrix[j][0] -= N
        if fireball_matrix[j][1] < 0:
            fireball_matrix[j][1] += N
        if fireball_matrix[j][1] >= N:
            fireball_matrix[j][1] -= N
    # 합쳐진 파이어볼 확인
    yx_diff = dict()
    for j in range(len(fireball_matrix)):
        tmp_key = fireball_matrix[j][0] * 100 + fireball_matrix[j][1]
        if not tmp_key in yx_diff:
            yx_diff[tmp_key] = [fireball_matrix[j][2], fireball_matrix[j][3], [fireball_matrix[j][4]]]
        else:
            yx_diff[tmp_key] = [
                yx_diff[tmp_key][0] + fireball_matrix[j][2], yx_diff[tmp_key][1] + fireball_matrix[j][3],
                yx_diff[tmp_key][2]
            ]
            yx_diff[tmp_key][2].append(fireball_matrix[j][4])

    fireball_matrix = []
    for key in yx_diff.keys():
        if len(yx_diff[key][2]) == 1:
            fireball_matrix.append(
                [int(math.floor(key/100)), int(key % 100),
                yx_diff[key][0],yx_diff[key][1],yx_diff[key][2][0]]
            )
        else:
            odd_even_flag = True
            if yx_diff[key][2][0] % 2 == 1:
                for i in range(len(yx_diff[key][2])):
                    if yx_diff[key][2][i] % 2 == 0:
                        odd_even_flag = False
                        break
            else:
                for i in range(len(yx_diff[key][2])):
                    if yx_diff[key][2][i] % 2 == 1:
                        odd_even_flag = False
                        break

            added_m = int(math.floor(yx_diff[key][0]/5))
            added_s = int(math.floor(yx_diff[key][1]/len(yx_diff[key][2])))
            if added_m>0:
                if odd_even_flag:
                    for ii in [0,2,4,6]:
                        fireball_matrix.append([
                            int(math.floor(key / 100)), int(key % 100),
                            added_m, added_s, ii
                        ])
                else:
                    for ii in [1,3,5,7]:
                        fireball_matrix.append([
                            int(math.floor(key / 100)), int(key % 100),
                            added_m, added_s, ii
                        ])

    # 총 질량 구하기
    all_d = 0
    for fm in fireball_matrix:
        all_d += fm[2]


print(all_d)
