# https://www.acmicpc.net/problem/1759
# 암호 만들기

import sys, itertools
L, C = map(int, sys.stdin.readline().rstrip().split())
all_letters = list(map(str, sys.stdin.readline().rstrip().split()))
all_conso = []  # 자음
all_vowel = []  # 모음
for i in range(C):
    if all_letters[i] == 'a' or all_letters[i] == 'e' \
            or all_letters[i] == 'i' or all_letters[i] == 'o' or all_letters[i] == 'u':
        all_vowel.append(all_letters[i])
    else:
        all_conso.append(all_letters[i])
all_cases = []
for i in range(L-2):
    now_conso = 2+i  # 최소 2개의 자음
    now_vowel = L-now_conso # 최소 1개의 모음
    comb_conso = list(itertools.combinations(all_conso, now_conso))
    comb_vowel = list(itertools.combinations(all_vowel, now_vowel))
    for cc in comb_conso:
        for cv in comb_vowel:
            now_tmp = list(cc+cv)
            now_tmp.sort()
            now_str = ""
            for ns in now_tmp:
                now_str += ns
            all_cases.append(now_str)
all_cases.sort()
for ac in all_cases:
    print(ac)